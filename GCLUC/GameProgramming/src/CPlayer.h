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
	//プレイヤーのインスタンス
	static CPlayer* mpinstance;
	CInput mInput;

public:
	//コンストラクタ
    //CPlayer(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CPlayer(float x, float y, float w, float h, CTexture* pt);
	//~デストラクタ
	~CPlayer();

	//インスタンスのポインタの取得
	static CPlayer* Instance();

	//更新処理
	void Update();

	static int sHp;	//HP

	//HPを取得
	static int Hp();
};