#pragma once
#include "CFont.h"
/*
* CUi
* ユーザーインタフェースクラス
*/
class CUi
{
private:
	int mEnemy;	//敵の数
	int mHp;    //プレイヤーのHP
	int mTime;	//経過時間
	CFont mFont;

public:
	//コンストラクタ
	CUi();
	//デストラクタ
	~CUi();

	//ゲームクリア表示
	void Clear();
	//ゲームオーバー表示
	void Over();
	//スタート表示
	void Start();

	//Enemy(敵の数)
	void Enemy(int enemy);
	void Hp(int hp);
	//Time(時間)
	void Time(int time);
	void Render();
};
