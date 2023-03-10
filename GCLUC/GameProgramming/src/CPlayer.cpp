#include "CPlayer.h"
#include "CApplication.h"
#include "CTaskManager.h"

#define TEXCOORD 168, 188, 158, 128	//�e�N�X�`���}�b�s���O

CPlayer* CPlayer::mpinstance = nullptr;

//�R���X�g���N�^
CPlayer::CPlayer(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::EPlayer)
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
		if (mInput.Key('W'))
	{
		float y = Y() + 5.0f;
		Y(y);
	}
	if (mInput.Key('S'))
	{
		float y = Y() - 5.0f;
		Y(y);
	}
	if (mInput.Key('D'))
	{
		float x = X() + 5.0f;
		X(x);
	}
	if (mInput.Key('A'))
	{
		float x = X() - 5.0f;
		X(x);
	}
}