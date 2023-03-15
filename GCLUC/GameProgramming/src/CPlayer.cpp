#include "CPlayer.h"
#include "CApplication.h"

//アイドリングテクスチャ(右向き)
#define DEFAULT  0, 200, 400, 200

#define JUMPV0 30               	//ジャンプの初速
#define GRAVITY 2.0f	            //重力加速度

#define PLAYERHP 10                 //プレイヤーのHP
#define STAMINA 100                 //プレイヤーのスタミナ

CPlayer* CPlayer::spinstance = nullptr;
int CPlayer::sHp = 0;
int CPlayer::sStamina = 0;

//コンストラクタ
CPlayer::CPlayer(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::ECharacter)
	, mInvincible(0)
	, mIdlingcount(0)
	, mJumpcount(0)
	, mMovecount(0)
	, mAttackcount(0)
	, mJumpY(0.0f)
{
	Set(x, y, w, h * 1.5);
	Texture(pt, DEFAULT);
	spinstance = this;
	mState = EState::EIDLING;
	sHp = PLAYERHP;
	sStamina = STAMINA;
}

//デストラクタ
CPlayer::~CPlayer()
{
}

//インスタンス作成
CPlayer* CPlayer::Instance()
{
	return spinstance;
}

//HPを取得
int CPlayer::HP()
{
	return sHp;
}

//スタミナを取得
int CPlayer::Stamina()
{
	return sStamina;
}

//更新処理
void CPlayer::Update()
{
	float left;
	float right;
	switch (State())
	{
	case EState::EMOVE:
		//X軸方向移動
		if (mInput.Key('A'))
		{
			mVx = -VELOCITY - 1;
			X(X() + mVx);
			mIdlingcount = 0;
		}
		if (mInput.Key('D'))
		{
			mVx = VELOCITY + 1;
			X(X() + mVx);
			mIdlingcount = 0;
		}
		//Y軸方向移動
		if (mInput.Key('W'))
		{
			mVy = VELOCITY + 1;
			Y(Y() + mVy);
			mIdlingcount = 0;
		}
		if (mInput.Key('S'))
		{
			mVy = VELOCITY - 1;
			Y(Y() - mVy);
			mIdlingcount = 0;
		}

		mMovecount %= 48;
		left = (mMovecount / 8) * 200;
		right = left + 200;
		mMovecount++;
		if (mVx >= 0)
		{
			Texture(Texture(), left, right, 200, 0);
		}
		if (mVx < 0)
		{
			Texture(Texture(), right, left, 200, 0);
		}
		//攻撃
		if (mInput.Key('K'))
		{
			mAttackcount = 0;
			mState = EState::EATTACK;
		}
		//キー入力がされていないかつカウントが0以上の時
		if (mInput.Key('W') != true ||
			mInput.Key('A') != true ||
			mInput.Key('S') != true ||
			mInput.Key('D') != true ||
			mInput.Key('J') != true ||
			mInput.Key('K') != true)
		{
			mIdlingcount--;
			if (mIdlingcount <= -10)
			{
				mState = EState::EIDLING;
			}
		}
		if (mState != EState::EJUMP)
		{
			if (mInput.Key('J'))
			{
				mJumpY = Y();
				mVy = JUMPV0;
				mInvincible = 20;
				mState = EState::EJUMP;
			}
		}
		break;

	case EState::EJUMP:
		mInvincible--;
		//Y軸速度に重力を減算する
		mVy -= GRAVITY;
		Y(Y() + mVy);

		mJumpcount %= 30;
		left = (mJumpcount / 10) * 200;
		right = left + 200;
		mJumpcount++;
		if (mVx >= 0)
		{
			Texture(Texture(), left, right, 800, 600);
		}
		else
		{
			Texture(Texture(), right, left, 800, 600);
		}

		if (mJumpY >= Y())
		{
			//無敵カウンタが0になったら状態をIDLINGにする
			if (mInvincible <= 0)
			{
				mState = EState::EIDLING;
			}
			else if (mJumpcount < 29)
			{
				mState = EState::EIDLING;
			}
		}
		//X軸方向移動
		if (mInput.Key('A'))
		{
			mVx = -VELOCITY;
			X(X() + mVx);
		}
		if (mInput.Key('D'))
		{
			mVx = VELOCITY;
			X(X() + mVx);
		}
		break;

	case EState::EIDLING:
		if (mInput.Key('W') || mInput.Key('A') ||
			mInput.Key('S') || mInput.Key('D') ||
			mInput.Key('J') || mInput.Key('K'))
		{
			mState = EState::EMOVE;
			mIdlingcount = 0;
		}
		mIdlingcount %= 72;
		left = (mIdlingcount / 18) * 200;
		right = left + 200;
		if (mVx >= 0)
		{
			Texture(Texture(), left, right, 400, 200);
		}
		else
		{
			Texture(Texture(), right, left, 400, 200);
		}
		mIdlingcount++;
		break;

	case EState::EATTACK:
		mAttackcount++;
		mAttackcount %= 24;
		left = (mAttackcount / 12) * 200;
		right = left + 200;
		if (mVx >= 0)
		{
			Texture(Texture(), left, right, 600, 400);
		}
		else
		{
			Texture(Texture(), right, left, 600, 400);
		}
		if (mAttackcount >= 23)
		{
			mState = EState::EIDLING;
		}
		break;

	case EState::EDAMAGE:
		break;

	case EState::EDEATH:
		break;

	}
	//デバッグ用
	if (mInput.Key('L'))
	{
		mVx = -VELOCITY - 1;
		X(X() + mVx);
	}
	CCharacter::Update();
}