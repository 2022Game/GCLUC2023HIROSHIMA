#pragma once
#include "CCharacter.h"
#include "CTexture.h"

//仮のイラスト
#define SLIME "スライム.png"
#define SLIMEX 1.5f 
#define SLIMEY 1.5f

class CSlime : public CCharacter
{
public:
	enum class EState	//状態
	{
		EMOVE,	//移動
		ESTOP,	//停止
		EJUMP,	//ジャンプ
		EDA,	//ダメージ
		EDEATH, //死亡
		EAT,    //攻撃
	};
protected:
public:
	EState State();	//状態を取得する
	bool Enabled(); //消す
	static CSlime* Instance2();
	static int SEhp();
	//敵の数を設定
	static void Num(int num);
	//敵の数を取得
	static int Num();
	//衝突処理2
	void Collision();
	//衝突処理4
	void Collision(CCharacter* m, CCharacter* o);
	//CEnemy2(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CSlime(float x, float y, float w, float h, CTexture* pt);
	//更新処理
	void Update();
	static CTexture mTexture6;
	static CTexture* Texture6();
private:
	static CSlime* spInstance2;
	static int sSEhp; //スライムのHP
	static int sNum;	//敵の数
	int mSlimeTime; //スライム用の時間
	int mSlimeTime2; //予備のスライム用の時間
	EState mState; //状態
	bool mEnabled; //消す
	float mVx;	//X軸速度
	float mVy;	//Y軸速度
};