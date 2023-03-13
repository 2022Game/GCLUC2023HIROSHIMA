#pragma once
#include "CCharacter.h"
#include "CTexture.h"

//仮のイラスト
#define WOLFX 2.0f 
#define WOLFY 2.0f

class CWolf : public CCharacter
{
public:
	enum class EState	//状態
	{
		EMOVE,	//移動
		ESTOP,	//停止
		EDA,	//ダメージ
		EDEATH, //死亡
		EAT,    //攻撃
	};
protected:
public:
	EState State();	//状態を取得する
	bool Enabled(); //消す
	static CWolf* Instance2();
	static int WEhp(); //オオカミのHP
	//敵の数を設定
	static void Num(int num);
	//敵の数を取得
	static int Num();
	//衝突処理2
	void Collision();
	//衝突処理4
	void Collision(CCharacter* m, CCharacter* o);
	//CWolf(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CWolf(float x, float y, float w, float h, CTexture* pt);
	//更新処理
	void Update();
	static CTexture mTexture7;
	static CTexture* Texture7();
private:
	static CWolf* spInstance2;
	static int sWEhp; //オオカミのHP
	static int sNum;	//敵の数
	int mWolfTime; //オオカミ用の時間
	int mWolfTime2; //予備のオオカミ用の時間
	EState mState; //状態
	bool mEnabled; //消す
	float mWVx;	//X軸速度
	float mWVy;	//Y軸速度
};