#include "CPlayer.h"
#include "CApplication.h"

//移動テクスチャ(右向き)
#define MOVETEXTURE   12,  201,199, 2
#define MOVETEXTURE2 202, 399, 186, 7
#define MOVETEXTURE3 401, 599, 193,10
#define MOVETEXTURE4 600, 796, 193, 8
#define MOVETEXTURE5 798, 997, 189,17
//移動テクスチャ(左向き)
#define MOVETEXTURE6  201,  12, 199, 2
#define MOVETEXTURE7  399, 202, 186, 7
#define MOVETEXTURE8  599, 401, 193,10
#define MOVETEXTURE9  796, 600, 193, 8
#define MOVETEXTURE10 997, 798, 189,17
//アイドリングテクスチャ(右向き)
#define IDLINGTEXTURE  200, 330, 402, 218
#define IDLINGTEXTURE2 437, 561, 402, 218
#define IDLINGTEXTURE3 635, 763, 402, 218
//アイドリングテクスチャ(左向き)
#define IDLINGTEXTURE4 332, 201, 405, 213
#define IDLINGTEXTURE5 561, 437, 402, 218
#define IDLINGTEXTURE6 763, 635, 402, 218
//ジャンプテクスチャ(右向き)
#define JUMPTEXTURE   26, 185, 798, 607
#define JUMPTEXTURE2 218, 382, 800, 603
//ジャンプテクスチャ(左向き)
#define JUMPTEXTURE3 185,  26, 798, 607
#define JUMPTEXTURE4 382, 218, 800, 603
//攻撃テクスチャ(右向き)
#define ATTACKTEXTURE  832, 961, 402, 218
#define ATTACKTECTURE2  30, 181, 606, 418 
//攻撃テクスチャ(左向き)
#define ATTACKTEXTURE  916, 832, 402, 218
#define ATTACKTECTURE2  181, 30, 606, 418 
//ダメージテクスチャ
#define DAMAGETEXTURE 217, 381, 602, 421
//死亡テクスチャ
#define DEATHTEXTURE  635, 775, 599, 421
#define DEATHTEXTURE2 798, 995, 593, 492


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
	,mIdlingcount(0)
	, mJumpY(0.0f)
{
	Set(x, y, w, h*1.5);
	Texture(pt, IDLINGTEXTURE);
	spinstance = this;
	mState = EState::EMOVE;
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
		//攻撃
		if (mInput.Key('K'))
		{
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
			if (mIdlingcount <= 0)
			{
				mIdlingcount = 20;
			}
			mIdlingcount--;
			if (mIdlingcount <= 10)
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
				mInvincible = 25;
				mState = EState::EJUMP;
			}
		}
		break;

	case EState::EJUMP:
		mInvincible--;
		//Y軸速度に重力を減算する
		mVy -= GRAVITY;
		Y(Y() + mVy);
		if (mJumpY >= Y())
		{
			//無敵カウンタが0になったら状態をMOVEにする
			if (mInvincible <= 0)
			{
				mState = EState::EMOVE;
			}
		}
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
		}
		if (mIdlingcount <= 0)
		{
			mIdlingcount = 72;
		}
		else
		{
			mIdlingcount--; 
		}
		if (mIdlingcount == 72)
		{
			if (mVx >= 0) { Texture(Texture(), IDLINGTEXTURE); }
			if (mVx < 0) { Texture(Texture(), IDLINGTEXTURE4); }
		}
		if (mIdlingcount == 54)
		{
			if (mVx >= 0) { Texture(Texture(), IDLINGTEXTURE2); }
			if (mVx < 0) { Texture(Texture(), IDLINGTEXTURE5); }
		}
		if (mIdlingcount == 36)
		{
			if (mVx >= 0) { Texture(Texture(), IDLINGTEXTURE3); }
			if (mVx < 0) { Texture(Texture(), IDLINGTEXTURE6); }
		}
		if (mIdlingcount == 18)
		{
			if (mVx >= 0) { Texture(Texture(), IDLINGTEXTURE2); }
			if (mVx < 0) { Texture(Texture(), IDLINGTEXTURE5); }
		}
		break;
	case EState::EATTACK:
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

