#include "CBoss.h"
#include "CApplication.h"

#define MU 0,0,0,0
//立ち絵
#define BOSSNTL 2442,2984,500,0
#define BOSSNTR 2984,2442,500,0
//攻撃時
#define BOSSAT1L 43,583,500,21
#define BOSSAT1R 583,43,500,21
#define BOSSAT2L 626,1182,488,23
#define BOSSAT2R 1182,626,488,23
//ダメージ
#define BOSSDAL 1842,2384,500,0
#define BOSSDAR 2384,1842,500,0
//死亡
#define BOSSDTL 1206,1796,433,133
#define BOSSDTR 1796,1206,433,133

#define BOSSHP 600

#define BOSSSR 648,1194,500,0
#define BOSSSL 1194,648,500,0
#define BOSSSSR 1206,1796,500,0
#define BOSSSSL 1796,1206,500,0

int CBoss::sBEhp = 0;

int CBoss::sNum = 0;

CBoss* CBoss::spInstance4 = nullptr;

CBoss* CBoss::Instance4()
{
	return spInstance4;
}

int CBoss::BEhp()
{
	return sBEhp;
}

void CBoss::Num(int num)
{
	sNum = num;
}

int CBoss::Num()
{
	return sNum;
}

void CBoss::Collision()
{
	//CApplication::CharacterManager()->Collision(this);
}

void CBoss::Collision(CCharacter* m, CCharacter* o)
{
	//めり込み調整変数を宣言する
	float x, y;
	switch (o->Tag())
	{
	case ETag::EPLAYER:
		//折り返しに当たった時
		if (mState != EState::EDEATH)
		{
			if (CRectangle::Collision(o, &x, &y))
			{
				if (mBossInvincible <= 0)
				{
					mBossInvincible = 60;
					if (mState != EState::EDAMAGE)
					{
						mBossTime2 = 60;
						if (mBVx < 0) { Texture(Texture(), MU); }
						if (mBVx > 0) { Texture(Texture(), MU); }
						sBEhp = sBEhp - 100;
						if (sBEhp <= 0)
						{
							mBossTime3 = 40;
							mState = EState::EDEATH;
						}
						if (mState != EState::EATTACK && mState != EState::EATTACK2)
						{
							mState = EState::EDAMAGE;
						}
					}
				}
			}
			break;
			//}
			//case ETag::E魔法:　//仮
			// if (mState != EState::EDEATH)
			//{
			//	if (CRectangle::Collision(o, &x, &y))
			//	{
			//		if (mBossInvincible <= 0)
			//		{
			//			mBossInvincible = 60;
			//			if (mState != EState::EDAMAGE)
			//			{
			//				//mBossTime = 60;
			//				if (mBVx < 0) { Texture(Texture(), MU); }
			//				if (mBVx > 0) { Texture(Texture(), MU); }
			//				sBEhp = sBEhp - 100;
			//				if (sBEhp <= 0)
			//				{
			//					mBossTime3 = 40;
			//					mState = EState::EDEATH;
			//				}
			//				if (mState != EState::EATTACK)
			//				{
			//					mBossTime2 = 60;
			//					mState = EState::EDAMAGE;
			//				}
			//			}
			//		}
			//	}
			//	break;
		}
	}
}

CBoss::CBoss(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::ECharacter)
{
	mTexture8.Load("ボス.png");
	Set(x, y, w, h);
	Texture(pt, BOSSNTL);
	mState = EState::EMOVE;
	mTag = ETag::EENEMY;
	sBEhp = BOSSHP;
	//XとY軸速度の初期値を移動速度にする
	mBVx = BOSSX;
	mBVy = BOSSY;
	mFlg1 = 0;
	mFlg2 = 0;
	mFlg3 = 0;
	mFlg4 = 0;
	spInstance4 = this;
	sNum++;
}

void CBoss::Update()
{
	if (mFlg1 != 1 && sBEhp <= 750)
	{
		mFlg1 = 1;
		mState = EState::EATTACK2;
	}
	if (mBossEattack > 0)
	{
		mBossEattack--;
		if (mBossEattack <= 0)
		{
			delete mpBossAttackBox;
		}
	}
	if (mBossEattack2 > 0)
	{
		mBossEattack2--;
		if (mBossEattack2 <= 0)
		{
			delete mpBossAttackBox2;
		}
	}
	if (mInput.Key('6'))
	{
		mBossInvincible = 20;
		mBossTime2 = 20;
		mState = EState::EDAMAGE;
	}
	if (mBossInvincible >= 0)
	{
		mBossInvincible--;
	}
	CCharacter::Update();
	switch (mState)
	{
	case EState::EMUTEKI:
		break;
	case EState::EDEATH://死亡時
		if (mBossTime3 >= 0)
		{
			mBossTime3--;
		}
		if (mBossTime3 == 39)
		{
			if (mBVx < 0) { Texture(Texture(), BOSSDTL); }
			if (mBVx > 0) { Texture(Texture(), BOSSDTR); }
		}
		if (mBossTime3 == 0)
		{
			sNum--;
		}
		break;
	case EState::ESTOP: //停止時、クールタイム間
		break;
	case EState::EATTACK: //攻撃時
		if (mBossTime >= 0)
		{
			mBossTime--;
		}
		if (mBossTime == 59)
		{
			if (mBVx < 0)
			{
				Texture(Texture(), BOSSAT1L);
			}
			if (mBVx > 0)
			{
				Texture(Texture(), BOSSAT1R);
			}
		}
		if (mBossTime == 30)
		{
			if (mBVx < 0)
			{
				Texture(Texture(), BOSSAT2L);
				mpBossAttackBox = new CBossAttackBox(X() - 300, Y(), 160.0f, 240.0f, CBoss::Texture8());
				mBossEattack = 30;
			}
			if (mBVx > 0)
			{
				Texture(Texture(), BOSSAT2R);
				mpBossAttackBox = new CBossAttackBox(X() + 300, Y(), 160.0f, 240.0f, CBoss::Texture8());
				mBossEattack = 30;
			}
		}
		if (mBossTime == 20)
		{
			if (mBVx < 0)
			{
				Texture(Texture(), BOSSAT2L);
			}
			if (mBVx > 0)
			{
				Texture(Texture(), BOSSAT2R);
			}
		}
		if (mBossTime == 10)
		{
			if (mBVx < 0)
			{
				Texture(Texture(), BOSSAT2L);
			}
			if (mBVx > 0)
			{
				Texture(Texture(), BOSSAT2R);
			}
		}
		if (mBossTime == 0)
		{
			//delete mpEattack;
			if (mFlg4 != 1 && mFlg1 != 0 && sBEhp <= 750)
			{
				if (mFlg2 != 0)
				{
					if (mFlg3 != 0)
					{
						mFlg4 = 1;
					}
					mFlg3 = 1;
					mState = EState::EMOVE;
				}
				mFlg2 = 1;
				mState = EState::EMOVE;
			}
			if (sBEhp > 750)
			{
				mState = EState::EMOVE;
			}
		}
		if (mFlg4 == 1)
		{
			mState = EState::EATTACK2;
			mBossTime4 = 120;
		}
		break;
	case EState::EATTACK2:
		if (mBossTime4 >= 0)
		{
			mBossTime4--;
		}
		if (sBEhp <= 750)
		{
			if (mBossTime4 >= 90)
			{
				if (X() > CPlayer::Instance()->X() - 650 && X() < CPlayer::Instance()->X() + 650)
				{
					X(X() + mBVx);
					mBVx = BOSSXXR;
				}
				/*if (X() > CPlayer::Instance()->X() - 650 && X() < CPlayer::Instance()->X() + 0)
				{
					X(X() + mBVx);
					mBVx = BOSSXXL;
				}*/
				/*if (Instance4()->Y() != CSlime::Instance2()->Y())
				{
					Y(Y() + mBVy);
					if (Y() < CSlime::Instance2()->Y())
					{
						if (mBVy < 0)
							mBVy = -mBVy;
					}
					else
					{
						if (mBVy > 0)
							mBVy = -mBVy;
					}
				}*/
			}
			if (mBossTime4 == 89)
			{

				//着地描画
			}
			if (mBossTime4 == 79)
			{

				//衝撃用意描画
			}
			if (mBossTime4 == 59)
			{
				if (mBVx > 0)
				{
					Texture(Texture(), BOSSAT2L);
					mpBossAttackBox2 = new CBossAttackBox2(X() - 300, Y(), 160.0f, 240.0f, CBoss::Texture8());
					mBossEattack2 = 59;
				}
				if (mBVx < 0)
				{
					Texture(Texture(), BOSSAT2R);
					mpBossAttackBox2 = new CBossAttackBox2(X() + 300, Y(), 160.0f, 240.0f, CBoss::Texture8());
					mBossEattack2 = 59;
				}
			}
			if (mBossTime4 < 0)
			{
				mBVx = BOSSX;
				mBVy = BOSSY;
				mFlg2 = 0;
				mFlg3 = 0;
				mFlg4 = 0;
				mState = EState::EMOVE;
			}
		}
		break;
	case EState::EDAMAGE: //ダメージ時
		if (sBEhp <= 0)
		{
			mBossTime3 = 40;
			mState = EState::EDEATH;
		}
		if (mBossTime2 >= 0)
		{
			mBossTime2--;
		}
		if (mBossTime2 == 59)
		{
			if (mBVx < 0) { Texture(Texture(), BOSSDAL); }
			if (mBVx > 0) { Texture(Texture(), BOSSDAR); }
		}
		if (mBossTime2 == 0)
		{
			mState = EState::EMOVE;
		}
		break;
	case EState::EBACK: //後飛
		break;
	case EState::EMOVE: //移動
		CCharacter::Update();
		if (X() > CPlayer::Instance()->X() - 250 && X() < CPlayer::Instance()->X() + 250)
		{
			if (Y() > CPlayer::Instance()->Y() - 125 && Y() < CPlayer::Instance()->Y() + 125)
			{
				if (mBossTime <= 0)
				{
					mBossTime = 60;
					mState = EState::EATTACK;
				}
			}
		}
		if (X() < CPlayer::Instance()->X())
		{
			mBLR = 1;
		}
		else
		{
			mBLR = 2;
		}

		//プレイヤーを追尾する
		if (mBLR == 1)
		{
			if (X() < CPlayer::Instance()->X() - 250)
			{
				X(X() + mBVx);
				if (X() < CPlayer::Instance()->X())
				{
					if (mBVx < 0)
						mBVx = -mBVx;
				}
			}
		}
		if (mBLR == 2)
		{
			if (X() > CPlayer::Instance()->X() + 250)
			{
				X(X() + mBVx);
				if (X() > CPlayer::Instance()->X())
				{
					if (mBVx > 0)
						mBVx = -mBVx;
				}
			}
		}
		if (Instance4()->Y() != CPlayer::Instance()->Y())
		{
			Y(Y() + mBVy);
			if (Y() < CPlayer::Instance()->Y())
			{
				if (mBVy < 0)
					mBVy = -mBVy;
			}
			else
			{
				if (mBVy > 0)
					mBVy = -mBVy;
			}
		}
		const int PITCH = 64;//画像を切り替える間隔
		if ((int)X() % PITCH < PITCH / 2)
		{
			//仮
			if (mBVx < 0)
			{
				Texture(Texture(), BOSSNTL); //Texture(Texture(), BOSSSR);
			}
			else
			{
				Texture(Texture(), BOSSNTL); //Texture(Texture(), BOSSSSL);
			}
		}
		else
		{
			if (mBVx > 0)
			{
				Texture(Texture(), BOSSNTL); //Texture(Texture(), BOSSSL);
			}
			else
			{
				Texture(Texture(), BOSSNTL); //Texture(Texture(), BOSSSSR);
			}
		}
	}
}

CTexture* CBoss::Texture8()
{
	return &mTexture8;
}
CTexture CBoss::mTexture8;