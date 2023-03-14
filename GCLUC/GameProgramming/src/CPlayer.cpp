#include "CPlayer.h"
#include "CApplication.h"
#include "CTaskManager.h"

#define TEXCOORD 168, 188, 158, 128	//テクスチャマッピング

#define HP 10

CPlayer* CPlayer::mpinstance = nullptr;

//コンストラクタ
CPlayer::CPlayer(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::ECharacter)
{
	Set(x, y, w, h);
	Texture(pt, TEXCOORD);
	mpinstance = this;
}

//デストラクタ
CPlayer::~CPlayer()
{
}

//インスタンス作成
CPlayer* CPlayer::Instance()
{
	return mpinstance;
}

//更新処理
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
	if (mInput.Key('V'))
	{
		mVy = VELOCITY - 1;
		Y(Y() - mVy - mVy);
	}
	CCharacter::Update();
}

int CPlayer::sHp = 0;	//HP

int CPlayer::Hp()
{
	return sHp;
}