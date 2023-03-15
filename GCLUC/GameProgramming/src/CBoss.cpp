#include "CBoss.h"
#include "CApplication.h"

//立ち絵
#define BOSSNTL 2442,2984,500,0
#define BOSSNTR 2984,2442,500,0
//攻撃時
#define BOSSATL 43,583,500,21
#define BOSSATR 583,43,500,21
#define BOSSAT1L 626,1182,488,23
#define BOSSAT2R 1182,626,488,23
//ダメージ
#define BOSSDAL 1842,2384,500,0
#define BOSSDAR 2384,1842,500,0
//死亡
#define BOSSDTL 1206,1796,433,133
#define BOSSDTR 1796,1206,433,133

#define BOSSHP 100

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
	////めり込み調整変数を宣言する
	//float x, y;
	//switch (o->Tag())
	//{
	//case ETag::ETURN:
	//	//折り返しに当たった時
	//	if (CRectangle::Collision(o, &x, &y))
	//	{
	//		//めり込まない位置まで戻す
	//		X(X() + x);
	//		Y(Y() + y);
	//		//X軸速度を反転させる
	//		mVx = -mVx;
	//	}
	//	break;
	//case ETag::EENEMY:
	//	break;
	//case ETag::EPLAYER:
	//	if (CRectangle::Collision(o))
	//	{
	//		if (o->State() == EState::EJUMP)
	//		{
	//			if (mState != EState::ECRY)
	//			{
	//				mSuraTime = 90;
	//				sEHp--;
	//			}
	//			mState = EState::ECRY;
	//		}
	//	}
	//	break;
	//case ETag::EBLOCK:
	//	if (CRectangle::Collision(o, &x, &y))
	//	{
	//		X(X() + x);
	//		Y(Y() + y);
	//		//着地した時
	//		if (y != 0.0f)
	//		{
	//			//Y軸速度を0にする
	//			mVy = 0.0f;
	//			if (y > 0.0f)
	//			{
	//				if (mState != EState::ECRY && mState != EState::EDEATH)
	//				{
	//					mState = EState::EMOVE;
	//				}
	//			}
	//		}
	//	}
	//	break;
	//}
}

CBoss::CBoss(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::ECharacter)
{
	mTexture8.Load("ボス.png");
	Set(x, y, w, h);
	Texture(pt, BOSSNTL);
	mState = EState::EMOVE;
	sBEhp = BOSSHP;
	//XとY軸速度の初期値を移動速度にする
	mBVx = BOSSX;
	mBVy = BOSSY;
	spInstance4 = this;
}

void CBoss::Update()
{
	//CCharacter::Update();
	switch (mState)
	{
	case EState::EDEATH: //死亡時
		break;
	case EState::ESTOP: //停止時、クールタイム間
		break;
	case EState::EATTACK: //攻撃時
		break;
	case EState::EDAMAGE: //ダメージ時
		break;
	case EState::EBACK: //後飛
		break;
	case EState::EMOVE: //移動
		CCharacter::Update();
		if (X() < CPlayer::Instance()->X())
		{
			if (mBVx < 0)
				mBVx = -mBVx;
			Texture(Texture(), BOSSNTR);
		}
		else
		{
			if (mBVx > 0)
				mBVx = -mBVx;
			Texture(Texture(), BOSSNTL);
		}
		if (Y() < CPlayer::Instance()->Y())
		{
			if (mBVy < 0)
			{
				mBVy = -mBVy;
			}
		}
		else
		{
			if (mBVy > 0)
			{
				mBVy = -mBVy;
			}
		}
		X(X() + mBVx);
		Y(Y() + mBVy);
	}
}

CTexture* CBoss::Texture8()
{
	return &mTexture8;
}
CTexture CBoss::mTexture8;