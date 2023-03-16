#include <stdio.h>
#include "CUi.h"
#include "CPlayer.h"

//コンストラクタ
CUi::CUi()
	: mHp(0)
	, mTime(0)
	, mEnemy(0)
	, mHeart(20,770,24,24,&mTexture100)
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
	//mFont.Draw(36, 300, 18, 36, "START PUSH ENTER KEY!");
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
	mFont.Draw(1120, 780, 10, 20, str);

	if (mHp == 10)
	{
		mHeart.Set(30, 770, 24, 24);
		mHeart.Render();
		mHeart.X(80);
		mHeart.Render();
		mHeart.X(130);
		mHeart.Render();
		mHeart.X(180);
		mHeart.Render();
		mHeart.X(230);
		mHeart.Render();
		mHeart.X(280);
		mHeart.Render();
		mHeart.X(330);
		mHeart.Render();
		mHeart.X(380);
		mHeart.Render();
		mHeart.X(430);
		mHeart.Render();
		mHeart.X(480);
		mHeart.Render();
	}
	if (mHp == 9)
	{
		mHeart.Set(30, 770, 24, 24);
		mHeart.Render();
		mHeart.X(80);
		mHeart.Render();
		mHeart.X(130);
		mHeart.Render();
		mHeart.X(180);
		mHeart.Render();
		mHeart.X(230);
		mHeart.Render();
		mHeart.X(280);
		mHeart.Render();
		mHeart.X(330);
		mHeart.Render();
		mHeart.X(380);
		mHeart.Render();
		mHeart.X(430);
		mHeart.Render();
	}
	if (mHp == 8)
	{
		mHeart.Set(30, 770, 24, 24);
		mHeart.Render();
		mHeart.X(80);
		mHeart.Render();
		mHeart.X(130);
		mHeart.Render();
		mHeart.X(180);
		mHeart.Render();
		mHeart.X(230);
		mHeart.Render();
		mHeart.X(280);
		mHeart.Render();
		mHeart.X(330);
		mHeart.Render();
		mHeart.X(380);
		mHeart.Render();
	}
	if (mHp == 7)
	{
		mHeart.Set(30, 770, 24, 24);
		mHeart.Render();
		mHeart.X(80);
		mHeart.Render();
		mHeart.X(130);
		mHeart.Render();
		mHeart.X(180);
		mHeart.Render();
		mHeart.X(230);
		mHeart.Render();
		mHeart.X(280);
		mHeart.Render();
		mHeart.X(330);
		mHeart.Render();
	}
	if (mHp == 7)
	{
		mHeart.Set(30, 770, 24, 24);
		mHeart.Render();
		mHeart.X(80);
		mHeart.Render();
		mHeart.X(130);
		mHeart.Render();
		mHeart.X(180);
		mHeart.Render();
		mHeart.X(230);
		mHeart.Render();
		mHeart.X(280);
		mHeart.Render();
		mHeart.X(330);
		mHeart.Render();
	}
	if (mHp == 6)
	{
		mHeart.Set(30, 770, 24, 24);
		mHeart.Render();
		mHeart.X(80);
		mHeart.Render();
		mHeart.X(130);
		mHeart.Render();
		mHeart.X(180);
		mHeart.Render();
		mHeart.X(230);
		mHeart.Render();
		mHeart.X(280);
		mHeart.Render();
	}
	if (mHp == 5)
	{
		mHeart.Set(30, 770, 24, 24);
		mHeart.Render();
		mHeart.X(80);
		mHeart.Render();
		mHeart.X(130);
		mHeart.Render();
		mHeart.X(180);
		mHeart.Render();
		mHeart.X(230);
		mHeart.Render();
	}
	if (mHp == 4)
	{
		mHeart.Set(30, 770, 24, 24);
		mHeart.Render();
		mHeart.X(80);
		mHeart.Render();
		mHeart.X(130);
		mHeart.Render();
		mHeart.X(180);
		mHeart.Render();
	}
	if (mHp == 3)
	{
		mHeart.Set(30, 770, 24, 24);
		mHeart.Render();
		mHeart.X(80);
		mHeart.Render();
		mHeart.X(130);
		mHeart.Render();
	}
	if (mHp == 2)
	{
		mHeart.Set(30, 770, 24, 24);
		mHeart.Render();
		mHeart.X(80);
		mHeart.Render();
	}
	if (mHp == 1)
	{
		mHeart.Set(30, 770, 24, 24);
		mHeart.Render();
	}
}
