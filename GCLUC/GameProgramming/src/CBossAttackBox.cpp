#include "CBossAttackBox.h"

#define MU 0, 200, 0, 0�@//��
#define WOLFNTL 1206,1796,433,133 //��

//�R���X�g���N�^
CBossAttackBox::CBossAttackBox(float x, float y, float w, float h, CTexture* pt)
	:CCharacter((int)ETaskPriority::ECharacter)
{
	Set(x, y, w, h);
	Texture(pt, WOLFNTL);
	mState = EState::EATTACK;
}

//�f�X�g���N�^
CBossAttackBox::~CBossAttackBox()
{
}

//�X�V����
void CBossAttackBox::Update()
{
	CCharacter::Update();
}