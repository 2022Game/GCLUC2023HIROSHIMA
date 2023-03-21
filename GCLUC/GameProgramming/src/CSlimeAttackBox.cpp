#include "CSlimeAttackBox.h"

#define MU 0, 200, 0, 0�@//��
#define WOLFNTL 1206,1796,433,133 //��

//�R���X�g���N�^
CSlimeAttackBox::CSlimeAttackBox(float x, float y, float w, float h, CTexture* pt)
	:CCharacter((int)ETaskPriority::ECharacter)
{
	Set(x, y, w, h);
	Texture(pt, WOLFNTL);
	mTag = ETag::EATTACK;
}

//�f�X�g���N�^
CSlimeAttackBox::~CSlimeAttackBox()
{
}

//�X�V����
void CSlimeAttackBox::Update()
{
	CCharacter::Update();
}