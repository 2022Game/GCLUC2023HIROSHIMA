#include <stdio.h>
#include "CUi.h"

//�R���X�g���N�^
CUi::CUi()
	: mHp(0)
	, mTime(0)
	, mEnemy(0)
{
	mFont.Load("FontWhite.png", 1, 64);
}

//�f�X�g���N�^
CUi::~CUi()
{
}

//�N���A�\��
void CUi::Clear()
{
	mFont.Draw(36, 300, 18, 36, "GAME CLEAR!!");
	mFont.Draw(36, 200, 18, 36, "PUSH ENTER KEY!");
}

//�Q�[���I�[�o�[�\��
void CUi::Over()
{
	mFont.Draw(36, 300, 18, 36, "GAME OVER!!");
	mFont.Draw(36, 200, 18, 36, "PUSH ENTER KEY!");
}

//�X�^�[�g�\��
void CUi::Start()
{
	mFont.Draw(36, 300, 18, 36, "START PUSH ENTER KEY!");
}

void CUi::Enemy(int enemy)
{
	mEnemy = enemy;
}

void CUi::Hp(int hp)
{
	mHp = hp;
}

void CUi::Time(int time)
{
	mTime = time;
}

void CUi::Render()
{
	char str[16];
	sprintf(str, "TIME:%03d", mTime);
	mFont.Draw(1130, 780, 10, 20, str);
	sprintf(str, "HP:%d", mHp);
	mFont.Draw(20, 20, 10, 20, str);
	sprintf(str, "ENEMY:%d", mEnemy);
	mFont.Draw(20, 780, 10, 20, str);
}
