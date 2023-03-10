#pragma once
#include"CTask.h"
#include"CRectangle.h"
#include"CTexture.h"
/*
キャラクタークラス
ゲームキャラクタの基本的な機能を定義する
*/
class CCharacter : public CRectangle, public CTask
{
private:
	CTask* mptask;
	CTexture* mpTexture;
	int mLeft,
		mRight,
		mBottom,
		mTop;
	bool mEnabled;
public:
	//コンストラクタ
	CCharacter(int priority);
	//デストラクタ
	~CCharacter();

	//描画処理
	void Render();
	CTexture* Texture();
	void Texture(CTexture* pTexture,
		int left, int right, int bottom, int top);

	//衝突処理
	virtual void Collision(CCharacter* m, CCharacter* o) {}
	//衝突処理2
	virtual void Collision() {};

	bool Enabled();
	void Update();
};