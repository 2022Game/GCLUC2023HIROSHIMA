#pragma once
#include "CUi.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CEnemy2.h"
#include "CBackGround.h"
#include "CBackGround2.h"
#include "CBackGround3.h"
#include "CBackGround4.h"
#include "CHeart.h"
#include "CInput.h"
#include "CSlime.h"
#include "CWolf.h"

//定数の定義
#define TEXTURE "image.png"//テクスチャのファイル名
#define TIPSIZE 40.0f //基本サイズ
/*
* CGameクラス
* ゲームクラス
* ゲームのマップを作成し、
* キャラクタを配置する
*/
class CGame
{
private:
	CPlayer* mpPlayer; //プレイヤーのポインタ
	CEnemy* mpEnemy;   //敵のポインタ
	CEnemy2* mpEnemy2; //敵２のポインタ
	CSlime* mpSlime;
	CWolf* mpWolf;
	CBackGround* mpBackGround;
	CBackGround2* mpBackGround2;
	CBackGround3* mpBackGround3;
	CBackGround4* mpBackGround4;
	CHeart* mpHeart;
	CInput mInput;

	int mCdx, mCdy;    //カメラとプレイヤーの座標の差分
	void CameraSet();  //カメラ設定
	int mTime; //経過時間
	int mH;
	int mCt;
	static int mNum;
	CUi* mpUi;         //UIクラスのポインタ

public:
	static int Num();
	//コンストラクタ
	CGame();
	//デストラクタ
	~CGame();

	/*bool Allderet*/
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
	//Stage1
	void Stage1();

	//更新処理
	void Update();
};
