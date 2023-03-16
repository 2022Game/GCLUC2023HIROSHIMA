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
	, mAnimationCount(0)
	, mJumpY(0.0f)
	, mpMagicBullet(nullptr)
{
	Set(x, y, w, h );
	Texture(pt, DEFAULT);
	mTag = ETag::EPLAYER;
	mState = EState::EIDLING;
	sHp = PLAYERHP;
	sStamina = STAMINA;
	spinstance = this; 
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

//死亡カウンタを取得
int CPlayer::DeathCount()
{
	return mDeathcount;
}

//更新処理
void CPlayer::Update()
{
	switch (State())
	{
		//移動状態
	case EState::EMOVE: Move();
		break;
		//ジャンプ状態
	case EState::EJUMP: Jump();
		break;
		//アイドリング状態
	case EState::EIDLING: Idling();
		break;
		//攻撃状態
	case EState::EATTACK: Attack();
		break;
		//被弾状態
	case EState::EDAMAGE: Damage();
		break;
		//死亡状態
	case EState::EDEATH: Death();
		break;
	}

	//デバッグ用
	if (mInput.Key('L') == true)
	{
     	mVx = -VELOCITY - 1;
		X(X() + mVx);
	}
	//デバッグ用
	if (mInput.Key('M'))
	{
		if (mState != EState::EJUMP && mState != EState::EDAMAGE)
		{
			sHp--;
			mState = EState::EDAMAGE;
		}
	}
	//HPが0になると死亡状態にする
	if (sHp <= 0)
	{
		if (mState != EState::EJUMP)
		{
			mState = EState::EDEATH;
		}
	}
	CCharacter::Update();
}

//移動処理
void CPlayer::Move()
{
	float left;
	float right;
	mAnimationCount %= 48;
	left = (mAnimationCount / 8) * 200;
	right = left + 200;
	mAnimationCount++;
	//右向き
	if (mVx >= 0)
	{
		Texture(Texture(), left, right, 200, 0);
	}
	if (mVx < 0) //左向き
	{
		Texture(Texture(), right, left, 200, 0);
	}
	//X軸方向移動
	if (mInput.Key('A'))
	{
		mVx = -VELOCITY - 1;
		X(X() + mVx);
	}
	if (mInput.Key('D'))
	{
		mVx = VELOCITY + 1;
		X(X() + mVx);
	}
	//Y軸方向移動
	if (mInput.Key('W'))
	{
		mVy = VELOCITY + 1;
		Y(Y() + mVy);
	}
	if (mInput.Key('S'))
	{
		mVy = VELOCITY - 1;
		Y(Y() - mVy);
	}
	//攻撃
	if (mInput.Key('K'))
	{
		mState = EState::EATTACK;
		mAnimationCount = 0;
	}
	//ジャンプ
	if (mState != EState::EJUMP)
	{
		if (mInput.Key('J'))
		{
			mJumpY = Y();
			mVy = JUMPV0;
			mState = EState::EJUMP;
			mAnimationCount = 0;
		}
	}
	//何も入力されていない時アイドリング状態にする
	if (mInput.Key('W') == false && mInput.Key('A') == false &&
		mInput.Key('S') == false && mInput.Key('D') == false &&
		mInput.Key('J') == false && mInput.Key('K') == false)
	{
		mState = EState::EIDLING;
		mAnimationCount = 0;
	}
}

//ジャンプ処理
void CPlayer::Jump()
{
	float left;
	float right;
	//Y軸速度に重力を減算する
	mVy -= GRAVITY;
	Y(Y() + mVy);

	mAnimationCount++;
	mAnimationCount %= 30;
	left = (mAnimationCount / 15) * 200;
	right = left + 200;
	if (mVx >= 0)
	{
		Texture(Texture(), left, right, 800, 600);
	}
	else
	{
		Texture(Texture(), right, left, 800, 600);
	}
	//着地したらアイドリング状態にする
	if (mJumpY >= Y())
	{
		mState = EState::EIDLING;
		mAnimationCount = 0;
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
}

//アイドリング処理
void CPlayer::Idling()
{
	float left;
	float right;
	mAnimationCount++;
	mAnimationCount %= 40;
	left = (mAnimationCount / 20) * 200;
	right = left + 200;
	//右向き
	if (mVx >= 0)
	{
		Texture(Texture(), left, right, 400, 200);
	}
	else //左向き
	{
		Texture(Texture(), right, left, 400, 200);
	}

	//キー入力で各状態に移行する
	if (mInput.Key('W') || mInput.Key('A') ||
		mInput.Key('S') || mInput.Key('D'))
	{
		mAnimationCount = 0;
		mState = EState::EMOVE;
	}
	if (mInput.Key('K'))
	{
		mAnimationCount = 0;
		mState = EState::EATTACK;
	}
	if (mInput.Key('J'))
	{
		mAnimationCount = 0;
		mState = EState::EJUMP;
	}
}

//攻撃処理
void CPlayer::Attack()
{
	float left;
	float right;
	mAnimationCount++;
	left = (mAnimationCount / 15) * 200;
	right = left + 200;
	if (mVx >= 0)
	{
		Texture(Texture(), left, right, 600, 400);
	}
	else
	{
		Texture(Texture(), right, left, 600, 400);
	}
	//状態をアイドリングにする
	if (mAnimationCount >= 29)
	{
		mAnimationCount = 0;
		mState = EState::EIDLING;
		delete mpMagicBullet;
	}
	//一つだけ生成
	if (mAnimationCount == 10)
	{
		//右向き
		if (mVx >= 0)
		{
			mpMagicBullet = new CMagicBullet(X() + 50, Y() - 50, 100, 100, CApplication::Texture());
		}
		else //左向きの時
		{
			mpMagicBullet = new CMagicBullet(X() - 50, Y() - 50, 100, 100, CApplication::Texture());
		}
	}
}

//被弾処理
void CPlayer::Damage()
{
	float left;
	float right;
	mAnimationCount++;
	mAnimationCount %= 10;
	left = (mAnimationCount / 5) * 200;
	right = left + 200;
	//右向き
	if (mVx >= 0)
	{
		Texture(Texture(), left, right, 1000, 800);
	}
	else //左向き
	{
		Texture(Texture(), right, left, 1000, 800);
	}
	//無敵時間の設定
	if (mInvincible < 0)
	{
		mInvincible = 40;
	}
	mInvincible--;
	if (mInvincible == 0)
	{
		mState = EState::EIDLING;
		mAnimationCount = 0;
	}

	//X軸方向移動
	if (mInput.Key('A'))
	{
		mVx = -VELOCITY - 1;
		X(X() + mVx);
	}
	if (mInput.Key('D'))
	{
		mVx = VELOCITY + 1;
		X(X() + mVx);
	}
	//Y軸方向移動
	if (mInput.Key('W'))
	{
		mVy = VELOCITY + 1;
		Y(Y() + mVy);
	}
	if (mInput.Key('S'))
	{
		mVy = VELOCITY - 1;
		Y(Y() - mVy);
	}
}

//死亡処理
void CPlayer::Death()
{
	float left;
	float right;
	if (mAnimationCount <= 40)
	{
		mAnimationCount++;
	}
	left = (mAnimationCount / 40) * 200;
	right = left + 200;
	Texture(Texture(), left, right, 1200, 1000);
}