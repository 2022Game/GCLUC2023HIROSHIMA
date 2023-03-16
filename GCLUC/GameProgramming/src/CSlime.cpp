#include "CSlime.h"
#include "CApplication.h"
#include "CCharacter.h"

//無
#define MU 0,0,0,0
//立ち絵
#define SLIMENTL 37,163,176,63
#define SLIMENTR 163,37,176,63
//ジャンプ
#define SLIMEJPL 629,775,189,29
#define SLIMEJPR 775,629,189,29
//降下
#define SLIMEDWL 1036,1175,170,5
#define SLIMEDWR 1175,1036,170,5
//ダメージ
#define SLIMEDAL 230,369,174,62
#define SLIMEDAR 369,230,174,62
//攻撃
#define SLIMEATL 408,589,188,18
#define SLIMEATR 589,408,188,18
//死亡
#define SLIMEDTL 812,988,186,89
#define SLIMEDTR 988,812,186,89
#define SLIMEDTL2 812,988,186,69
#define SLIMEDTR2 988,812,186,69
#define SLIMEDTL3 812,988,186,49
#define SLIMEDTR3 988,812,186,49
#define SLIMEDTL4 812,988,186,29
#define SLIMEDTR4 988,812,186,29
#define SLIMEDTL5 812,988,186,9
#define SLIMEDTR5 988,812,186,9

#define GRAVITY (TIPSIZE / 250.0f)	
#define GRAVITY2 (TIPSIZE / 120.0f)//重力加速度
#define JUMPV0 (TIPSIZE / 8.0f)	//ジャンプの初速

#define SLIMEHP 300 //スライムのHP

//int CSlime::sSEhp = 0;

int CSlime::sNum = 0;

CSlime* CSlime::spInstance2 = nullptr;

CSlime* CSlime::Instance2()
{
	return spInstance2;
}

int CSlime::SEhp()
{
	return sSEhp;
}

void CSlime::Num(int num)
{
	sNum = num;
}

int CSlime::Num()
{
	return sNum;
}

void CSlime::Collision()
{
	//CApplication::CharacterManager()->Collision(this);
}

void CSlime::Collision(CCharacter* m, CCharacter* o)
{
	//めり込み調整変数を宣言する
	float x, y;
	switch (o->Tag())
	{
		if (mState != EState::EDEATH)
		{
	case ETag::EPLAYER:
		if (CRectangle::Collision(o, &x, &y))
		{
			if (mSlimeInvincible <= 0)
			{
				mSlimeInvincible = 60;
				if (mState != EState::EDAMAGE)
				{
					mSlimeTime = 60;
					sSEhp = sSEhp - 100;
					if (mSVx < 0) { Texture(Texture(), MU); }
					if (mSVx > 0) { Texture(Texture(), MU); }
					if (mState != EState::EATTACK)
					{
						mState = EState::EDAMAGE;
					}
				}
			}
		}
		break;
		/*if (CRectangle::Collision(o, &x,&y))
		{
				if (mSlimeTime3 <= 0)
				{
					mSlimeTime3 = 61;
					mState = EState::EATTACK;
				}
		}
		break;*/
		//case ETag::EMAGIC: //仮の魔法
			/*if (CRectangle::Collision(o, &x, &y))
			{
				if (mSlimeInvincible <= 0)
				{
					mSlimeInvincible = 60;
					if (mState != EState::EDAMAGE)
					{
						mSlimeTime = 31;
						sSEhp = sSEhp - 100;
						if (mSVx < 0) { Texture(Texture(), MU); }
						if (mSVx > 0) { Texture(Texture(), MU); }
		 if(mState != EState::EATTACK)
		 {
						mState = EState::EDAMAGE;
		 }
					}
				}
			}
		break;*/
		//case ETag::EDAGEKI: //仮の打撃
	//	if (CRectangle::Collision(o, &x, &y))
	//	{
	//		if (mSlimeInvincible <= 0)
	//		{
	//			mSlimeInvincible = 60;
	//			if (mState != EState::EDAMAGE)
	//			{
	//				mWolfTime = 31;
	//				sWEhp = sWEhp - 25;
	//				if (mState != EState::EATTACK)
	//				{
	//					mState = EState::EDAMAGE;
	//				}
	//			}
	//		}
	//	}
		}
	}
}

CSlime::CSlime(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::ECharacter)
{
	mTexture6.Load("スライム.png");
	Set(x, y, w, h);
	Texture(pt, SLIMENTL); //テスト用の開始時の立ち絵
	mState = EState::EMOVE;
	mTag = ETag::EENEMY;
	sSEhp = SLIMEHP;
	//XとY軸速度の初期値を移動速度にする
	mSVx = SLIMEX;
	mSVy = SLIMEY;
	spInstance2 = this;
	sNum++;
}

void CSlime::Update()
{
	CCharacter::Update();
	if (mSlimeInvincible >= 0)
	{
		mSlimeInvincible--;
	}
	//テスト用入力キー
	if (mInput.Key('4'))
	{
		mSlimeTime = 11;
		mState = EState::EDAMAGE;
	}
	if (mInput.Key('5'))
	{
		mSlimeTime3 = 61;
		mState = EState::EATTACK;
	}
	if (mSlimeInvincible != 10 && mInput.Key('8'))
	{
		mSlimeInvincible = 10;
		if (mState != EState::EDAMAGE)
		{
			mSlimeTime = 31;
			sSEhp = sSEhp - 100;
			mState = EState::EDAMAGE;
		}
	}
	switch (mState)
	{
	case EState::EMUTEKI:
		break;
	case EState::EDEATH: //死亡時
		//mVy -= GRAVITY;
		//ここのスライムタイムはテスト用。の
		//後に死亡用とダメージ用に別々にする
		if (mSlimeTime4 >= 0)
		{
			mSlimeTime4--;
		}
		if (mSlimeTime4 == 40)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDTL); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDTR); }
		}
		if (mSlimeTime4 == 30)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDTL2); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDTR2); }
		}
		if (mSlimeTime4 == 20)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDTL3); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDTR3); }
		}
		if (mSlimeTime4 == 10)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDTL4); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDTR4); }
		}
		if (mSlimeTime4 == 5)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDTL5); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDTR5); }
		}
		if (mSlimeTime4 == 0)
		{
			sNum--;
		}
		break;
	case EState::ESTOP: //停止時、クールタイム間
		if (mSVx < 0) { Texture(Texture(), SLIMENTL); }
		if (mSVx > 0) { Texture(Texture(), SLIMENTR); }
		break;
	case EState::EATTACK: //攻撃時
		if (mSlimeTime3 > 0)
		{
			mSlimeTime3--;
		}
		if (mSlimeTime3 == 60)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMENTL); }
			if (mSVx > 0) { Texture(Texture(), SLIMENTR); }
		}
		if (mSlimeTime3 == 30)
		{
			if (mSVx < 0)
			{
				Texture(Texture(), SLIMEATL);
				//new CSlime(X() - 100, Y(), 80.0f, 80.0f, CSlime::Texture6());
			}
			if (mSVx > 0)
			{
				Texture(Texture(), SLIMEATR);
				//	new CSlime(X() + 100, Y(), 80.0f, 80.0f, CSlime::Texture6());
			}
		}
		if (mSlimeTime3 == 0)
		{
			mState = EState::EMOVE;
		}
		break;
	case EState::EDAMAGE: //ダメージ時
		//テスト用に死亡までつながるようにしている
		if (sSEhp <= 0)
		{
			mSlimeTime4 = 41;
			mState = EState::EDEATH;
		}
		if (mSlimeTime > 0)
		{
			mSlimeTime--;
		}
		if (mSlimeTime == 30)
		{
			/*if (mSVx < 0) { Texture(Texture(), MU); }
			if (mSVx > 0) { Texture(Texture(), MU); }*/
		}
		if (mSlimeTime == 59)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDAL); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDAR); }
		}
		if (mSlimeTime <= 0)
		{
			mState = EState::EMOVE;
		}
		break;
	case EState::EMOVE2:
		mSlimeTime2--;
		X(X() + mSVx);
		if (X() != CPlayer::Instance()->X())
		{
			//X(X() + mSVx);
			Y(Y() + mSVy);
			if (mSlimeTime2 > 0)
			{
				mSVy -= GRAVITY2;
			}
			if (mSlimeTime2 < 0)
			{
				mSlimeTime2 = 40;
				mState = EState::EMOVE;
			}
			if (mSVy > 0)
			{
				if (mSVx < 0.0f)
				{
					Texture(Texture(), SLIMEJPL);
				}
				if (mSVx > 0.0f)
				{
					Texture(Texture(), SLIMEJPR);
				}
			}
			if (mSVy < 0)
			{
				if (mSVx < 0.0f)
				{
					Texture(Texture(), SLIMEDWL);
				}
				if (mSVx > 0.0f)
				{
					Texture(Texture(), SLIMEDWR);
				}
			}
		}
		break;
	case EState::EMOVE:
		mSlimeTime2--;
		X(X() + mSVx);
		if (X() != CPlayer::Instance()->X())
		{
			Y(Y() + mSVy);
			if (X() < CPlayer::Instance()->X())
			{
				if (mSVx < 0)
					mSVx = -mSVx;
				Texture(Texture(), SLIMEDWR);
			}
			else
			{
				if (mSVx > 0)
					mSVx = -mSVx;
				Texture(Texture(), SLIMEDWL);
			}
			if (Y() < CPlayer::Instance()->Y())
			{
				if (mSVy < 0)
				{
					mSVy = -mSVy;
				}
			}
			else
			{
				if (mSVy > 0)
				{
					mSVy = JUMPV0;
					mSVy = -mSVy;
				}
			}
			if (mState != EState::EMOVE2 && mSlimeTime2 < 30)
			{
				mSVy = JUMPV0;
				mState = EState::EMOVE2;
			}
		}
	}
}

CTexture* CSlime::Texture6()
{
	return &mTexture6;
}
CTexture CSlime::mTexture6;
