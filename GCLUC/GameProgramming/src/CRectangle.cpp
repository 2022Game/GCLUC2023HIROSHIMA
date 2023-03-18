#include "CRectangle.h"
#include <stdio.h>
#include "glut.h"

#define COLLISIONX 50
//�R���X�g���N�^
CRectangle::CRectangle()
	:mX(0.0f)
	,mY(0.0f)
	,mW(0.0f)
	,mH(0.0f)
	,az(0.0f)
	,mZ(0.0f)
{
	printf("�C���X�^���X�����܂�܂���\n");
}

//�f�X�g���N�^
CRectangle::~CRectangle()
{
	printf("�C���X�^���X���j������܂���\n");
}

bool CRectangle::Collision(CRectangle* r)
{
	float distX = mX - r->mX;
	if (distX < 0.0f)
		distX = -distX;
	if (distX >= mW + r->mW)
		return false;
	float distY = mY - r->mY;
	if (distY < 0.0f)
		distY = -distY;
	if (distY >= mH + r->mH)
		return false;
	return true;
}

bool CRectangle::Collision(CRectangle* r, float* ax, float* ay)
{
	//������
	*ax = 0;
	*ay = 0;

	//Z�������蔻��
	if (mZ < r->mZ)
		az = r->mZ - mZ;
	else
		az = mZ - r->mZ;
	//az���Βl�ɂ���
	if (az < 0.0f)
		az = -az;
	//�萔�Ɣ�r(az��0�`50�̊ԂȂ�Collision)
	if (0 < az && az <= COLLISIONX)
	{
		//X�������蔻��
		if (mX  < r->mX)
			*ax = r->mX - mX - mW - r->mW;
		else
			*ax = mX - r->mX - mW - r->mW;
		//0�ȏ�͏Փ˂��Ȃ�
		if (*ax >= 0.0f)
			return false;

		//Y�������蔻��
		if (mY < r->mY)
			*ay = r->mY - mY - mH - r->mH;
		else
			*ay = mY - r->mY - mH - r->mH;
		//0�ȏ�͏Փ˂��Ȃ�
		if (*ay >= 0.0f)
			return false;

		//Y���Z��������
		if (*ax < *ay)
		{//Y�C���AX��0
			*ax = 0.0f;
			//���̎�
			*ay = *ay / 3;
			//��̎�
			if (mY > r->mY)
				*ay = -*ay / 3;
			else if (mY < r->mY)
				*ay = *ay / 3;
		}
		else
		{//X�C���AY��0
			*ay = 0.0f;
			//���̎�
			*ax = *ax / 3;
			//�E�̎�
			if (mX > r->mX)
				*ax = -*ax / 3;
		}
		return true;
	}
	return false;
}


void CRectangle::Render()
{
	Render(mX, mY, mW, mH);
}

void CRectangle::Render(float x, float y, float w, float h)
{
	glBegin(GL_QUADS);
	glVertex2f(x - w, y - h);
	glVertex2f(x + w, y - h);
	glVertex2f(x + w, y + h);
	glVertex2f(x - w, y + h);
	glEnd();
}

void CRectangle::Set(float x, float y, float w, float h)
{
	mX = x;
	mY = y;
	mW = w;
	mH = h;
}

float CRectangle::X()
{
	return mX;
}

float CRectangle::Y()
{
	return mY;
}

float CRectangle::W()
{
	return mW;
}

float CRectangle::H()
{
	return mH;
}

void CRectangle::Y(float y)
{
	mY = y;
}

void CRectangle::X(float x)
{
	mX = x;
}