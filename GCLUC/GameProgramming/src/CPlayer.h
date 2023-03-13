#pragma once
#include "CCharacter.h"
#include "CInput.h"
/*
プレイヤークラス
キャラクタスを継承
*/
class CPlayer : public CCharacter
{
private:
	static CPlayer* spinstance; //プレイヤーのインスタンス
	static int sHp;             //プレイヤーのHP
	static int sStamina;        //プレイヤーのスタミナ

	int mInvincible;            //無敵カウンタ
	int mIdlingcount;           //アイドリングカウンタ 
	float mJumpY;               //プレイヤーのジャンプ時のY座標
	CInput mInput;              //キー入力判定

public:
	//コンストラクタ
    //CPlayer(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CPlayer(float x, float y, float w, float h, CTexture* pt);
	//~デストラクタ
	~CPlayer();

	//インスタンスのポインタの取得
	static CPlayer* Instance();
	//プレイヤーのHPを取得
	static int HP();
	//プレイヤーのスタミナを取得
	static int Stamina();
	//更新処理
	void Update();
};