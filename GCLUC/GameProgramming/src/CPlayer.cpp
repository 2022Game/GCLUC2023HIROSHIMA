#include "CPlayer.h"
#include "CApplication.h"
#include "CTaskManager.h"

#define TEXCOORD 168, 188, 158, 128	//テクスチャマッピング

CPlayer* CPlayer::mpinstance = nullptr;

//コンストラクタ
CPlayer::CPlayer(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::EPlayer)
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