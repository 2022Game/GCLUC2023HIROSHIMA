#include "CWolf.h"
#include "CApplication.h"

//移動１
#define WOLFMOVEL 408,595,174,38
#define WOLFMOVER 595,408,174,38
//移動２　//移動１の後に移動２を表示する
#define WOLFMOVEL2 622,781,177,36
#define WOLFMOVER2 781,622,177,36
//ダメージ
#define WOLFCRYL 237,383,190,46
#define WOLFCRYR 383,237,190,46
//攻撃１
#define WOLFATL 1005,1198,182,33
#define WOLFATR 1198,1005,182,33
//攻撃２　//攻撃１の後に攻撃２を表示する
#define WOLFATL 1225,1398,181,33
#define WOLFATR 1398,1225,181,33
//死亡
#define WOLFDTL 843,987,185,49
#define WOLFDTR 987,843,185,49

#define WOLFHP 100 

int CWolf::sWEhp = 0;

int CWolf::sNum = 0;

CWolf* CWolf::spInstance2 = nullptr;

CWolf* CWolf::Instance2()
{
	return spInstance2;
}

int CWolf::WEhp()
{
	return sWEhp;
}

void CWolf::Num(int num)
{
	sNum = num;
}

int CWolf ::Num()
{
	return sNum;
}

void CWolf::Collision()
{
	//CApplication::CharacterManager()->Collision(this);
}

void CWolf::Collision(CCharacter* m, CCharacter* o)
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

CWolf::CWolf(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::ECharacter)
{
	mTexture7.Load("子狼.png");
	Set(x, y, w, h);
	Texture(pt, WOLFMOVEL); //開始時の立ち絵
	mState = EState::EMOVE;
	sWEhp = WOLFHP; //オオカミのHP
	//XとY軸速度の初期値を移動速度にする
	mWVx = WOLFX;
	mWVy = WOLFY;
	spInstance2 = this;
}

void CWolf::Update()
{
	//プレイヤーを追尾する
	if (X() < CPlayer::Instance()->X())
	{
		if (mWVx < 0)
			mWVx = -mWVx;
	}
	else
	{
		if (mWVx > 0)
			mWVx = -mWVx;
	}
	if (Y() < CPlayer::Instance()->Y())
	{
		if (mWVy < 0)
			mWVy = -mWVy;
	}
	else
	{
		if (mWVy > 0)
			mWVy = -mWVy;
	}
	switch (mState)
	{
	case EState::EDEATH: //死亡時
		//HPが０になった数秒後に消滅させる
		if (mWolfTime > 0)
		{
			mWolfTime--;
		}
		if (mWolfTime == 50)
		{
			if (mWVx < 0) { Texture(Texture(), WOLFDTL); }
			if (mWVx > 0) { Texture(Texture(), WOLFDTR); }
		}
		if (mWolfTime == 0)
		{
			mEnabled = false;
		}
		break;
	case EState::ESTOP: //停止時、クールタイム間
	case EState::EAT: //攻撃時
	case EState::EDA: //ダメージ時
	case EState::EMOVE:
	X(X() + mWVx);
	Y(Y() + mWVy);
	const int PITCH = 32;//画像を切り替える間隔
	if ((int)X() % PITCH < PITCH / 2)
	{
		if (mWVx < 0)
			{
				Texture(Texture(), WOLFMOVEL);
			}
			else
			{
				Texture(Texture(), WOLFMOVER2);
			}
		}
		else
		{
			if (mWVx > 0)
			{
				Texture(Texture(), WOLFMOVER);
			}
			else
			{
				Texture(Texture(), WOLFMOVEL2);
			}
		}
	}
}

CTexture* CWolf::Texture7()
{
	return &mTexture7;
}
CTexture CWolf::mTexture7;