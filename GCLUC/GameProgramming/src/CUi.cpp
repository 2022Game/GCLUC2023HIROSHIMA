#include <stdio.h>
#include "CUi.h"
#include "CPlayer.h"

//コンストラクタ
CUi::CUi()
	: mHp(0)
	, mTime(0)
	, mEnemy(0)
{
	mFont.Load("FontWhite.png", 1, 64);
	mTexture100.Load("プレイヤーHP.png");
}

//デストラクタ
CUi::~CUi()
{
}

//クリア表示
void CUi::Clear()
{
	mFont.Draw(36, 300, 18, 36, "GAME CLEAR!!");
	mFont.Draw(36, 200, 18, 36, "PUSH ENTER KEY!");
}

//ゲームオーバー表示
void CUi::Over()
{
	mFont.Draw(36, 300, 18, 36, "GAME OVER!!");
	mFont.Draw(36, 200, 18, 36, "PUSH ENTER KEY!");
}

//スタート表示
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
	if (mHp == 10)
	{
		mpHeart = new CHeart(40, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(80, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(120, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(160, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(200, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(240, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(280, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(320, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(360, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(400, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
	}
	if (mHp == 9)
	{
		mpHeart = new CHeart(40, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(80, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(120, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(160, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(200, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(240, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(280, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(320, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(360, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
	}
	if (mHp == 8)
	{
		mpHeart = new CHeart(40, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(80, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(120, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(160, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(200, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(240, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(280, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(320, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
	}
	if (mHp == 7)
	{
		mpHeart = new CHeart(40, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(80, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(120, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(160, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(200, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(240, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(280, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
	}
	if (mHp == 6)
	{
		mpHeart = new CHeart(40, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(80, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(120, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(160, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(200, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(240, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
	}
	if (mHp == 5)
	{
		mpHeart = new CHeart(40, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(80, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(120, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(160, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(200, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
	}
	if (mHp == 4)
	{
		mpHeart = new CHeart(40, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(80, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(120, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(160, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
	}
	if (mHp == 3)
	{
		mpHeart = new CHeart(40, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(80, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(120, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
	}
	if (mHp == 2)
	{
		mpHeart = new CHeart(40, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
		mpHeart = new CHeart(80, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
	}
	if (mHp == 1)
	{
		mpHeart = new CHeart(40, 770.0f, 20.0f, 20.0f, 0, 49, 49, 0, &mTexture100);
		mpHeart->Render();
	}
}

void CUi::Time(int time)
{
	mTime = time;
}

void CUi::Render()
{
	char str[16];
	sprintf(str, "TIME:%03d", mTime);
	mFont.Draw(1120, 780, 10, 20, str);
}
