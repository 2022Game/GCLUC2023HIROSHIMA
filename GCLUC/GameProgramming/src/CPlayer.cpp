#include "CPlayer.h"
#include "CApplication.h"
#include "CTaskManager.h"

#define TEXCOORD 168, 188, 158, 128	//�e�N�X�`���}�b�s���O

CPlayer* CPlayer::mpinstance = nullptr;

//�R���X�g���N�^
CPlayer::CPlayer(float x, float y, float w, float h, CTexture* pt)
	: CCharacter(mVz)//(int)ETaskPriority::ECharacter)
{
	Set(x, y, w, h);
	Texture(pt, TEXCOORD);
	mpinstance = this;
}

//�f�X�g���N�^
CPlayer::~CPlayer()
{
}

//�C���X�^���X�쐬
CPlayer* CPlayer::Instance()
{
	return mpinstance;
}

//�X�V����
void CPlayer::Update()
{
	mState = EState::EMOVE;
	if (mInput.Key('A'))
	{
		mVx = -VELOCITY - 1;
		X(X() + mVx + mVx);
	}
	if (mInput.Key('D'))
	{
		mVx = VELOCITY + 1;
		X(X() + mVx + mVx);
	}
	if (mInput.Key('W'))
	{
		mVy = VELOCITY + 1;
		Y(Y() + mVy + mVy);
	}
	if (mInput.Key('S'))
	{
		mVy = VELOCITY - 1;
		Y(Y() - mVy - mVy);
	}
}