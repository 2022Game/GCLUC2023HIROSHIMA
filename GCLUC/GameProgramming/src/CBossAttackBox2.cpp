#include "CBossAttackBox2.h"
#include "CBoss.h"

#define MU 0, 200, 0, 0　//仮
#define WOLFNTL 1206,1796,433,133 //仮

//コンストラクタ
CBossAttackBox2::CBossAttackBox2(float x, float y, float w, float h, CTexture* pt)
	:CCharacter((int)ETaskPriority::ECharacter)
{
	Set(x, y, w, h);
	Texture(pt, WOLFNTL);
	mState = EState::EATTACK;
}

//デストラクタ
CBossAttackBox2::~CBossAttackBox2()
{
}

//更新処理
void CBossAttackBox2::Update()
{
	if (CBoss::Instance4()->mVx >= 0)
	{
		Texture(Texture(), WOLFNTL);
		mVx = -VELOCITY - 10;
		X(X() + mVx);
	}
	else
	{
		Texture(Texture(), WOLFNTL);
		mVx = VELOCITY + 10;
		X(X() + mVx);
	}
	CCharacter::Update();
}