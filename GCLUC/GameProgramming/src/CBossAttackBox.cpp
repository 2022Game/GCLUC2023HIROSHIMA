#include "CBossAttackBox.h"

#define MU 0, 200, 0, 0　//仮
#define WOLFNTL 1206,1796,433,133 //仮

//コンストラクタ
CBossAttackBox::CBossAttackBox(float x, float y, float w, float h, CTexture* pt)
	:CCharacter((int)ETaskPriority::ECharacter)
{
	Set(x, y, w, h);
	Texture(pt, WOLFNTL);
	mState = EState::EATTACK;
}

//デストラクタ
CBossAttackBox::~CBossAttackBox()
{
}

//更新処理
void CBossAttackBox::Update()
{
	CCharacter::Update();
}