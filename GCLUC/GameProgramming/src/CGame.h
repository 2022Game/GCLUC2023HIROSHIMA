#pragma once
#include "CUi.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CEnemy2.h"

//定数の定義
#define TEXTURE "image.png" //テクスチャのファイル名
#define TIPSIZE 40.0f //基本サイズ
/*
* CGameクラス
* ゲームクラス
* ゲームのマップを作成し、
* キャラクタを配置する
*/
class CGame
{
public:
	//コンストラクタ
	CGame();
	//デストラクタ
	~CGame();

	//ゲームクリア判定
	//bool IsClear();
	//ゲームクリア処理
	void Clear();

	//ゲームオーバー判定
	//bool IsOver();
	//ゲームオーバー処理
	void Over();

	//スタート処理
	void Start();

	//更新処理
	void Update();
private:
	int mCdx, mCdy;    //カメラとプレイヤーの座標の差分
	void CameraSet();  //カメラ設定
	CPlayer *mpPlayer; //プレイヤーのポインタ
	CEnemy* mpEnemy;   //敵のポインタ
	CEnemy2* mpEnemy2; //敵２のポインタ
	int mTime;         //経過時間
	CUi *mpUi;         //UIクラスのポインタ
};
