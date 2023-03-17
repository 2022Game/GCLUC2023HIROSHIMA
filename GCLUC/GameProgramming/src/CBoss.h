#pragma once
#include "CCharacter.h"
#include "CTexture.h"
#include "CInput.h"
#include "CEattack.h"

#define BOSSX 1.0f 
#define BOSSY 1.0f

class CBoss : public CCharacter
{
	friend CEattack;
public:
	enum class EState	//状態
	{
		EMOVE,	//移動
		ESTOP,	//停止
		EDAMAGE,	//ダメージ
		EDEATH, //死亡
		EBACK, //後ろへ
		EATTACK,    //攻撃
		EMUTEKI,
	};
protected:
public:
	EState State();	//状態を取得する
	bool Enabled(); //消す
	static CBoss* Instance4();
	static int BEhp(); //オオカミのHP
	//敵の数を設定
	static void Num(int num);
	//敵の数を取得
	static int Num();
	//衝突処理2
	void Collision();
	//衝突処理4
	void Collision(CCharacter* m, CCharacter* o);
	//CWolf(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CBoss(float x, float y, float w, float h, CTexture* pt);
	//更新処理
	void Update();
	static CTexture mTexture8;
	static CTexture* Texture8();
private:
	CEattack* mpEattack;
	static CBoss* spInstance4;
	static int sBEhp; //ボスのHP
	static int sNum;	//敵の数
	int mBossEattack; //攻撃持続時間
	int mBossTime; //攻撃のボス用の時間
	int mBossTime2; //ダメージのボス用の時間
	int mBossTime3; //死亡のボス用の時間
	int mBossInvincible; //無敵用のボス用の時間
	EState mState; //状態
	bool mEnabled; //消す
	float mBVx;	//X軸速度
	float mBVy;	//Y軸速度
	float mBLR;
	CInput mInput;
};