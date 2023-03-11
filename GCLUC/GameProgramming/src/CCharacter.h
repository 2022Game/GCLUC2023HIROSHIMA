#pragma once
#include"CTask.h"
#include"CRectangle.h"
#include"CTexture.h"
#define VELOCITY 4.0f	//移動速度
/*
キャラクタークラス
ゲームキャラクタの基本的な機能を定義する
*/
class CCharacterManager;
class CCharacter : public CRectangle, public CTask
{
	friend CTask;
	friend CCharacterManager;
public:
	enum class EState	//状態
	{
		ENULL,  //空
		EMOVE,	//移動
		ESTOP,	//停止
		EJUMP,	//ジャンプ
	};

private:
	CTexture* mpTexture;
	int mLeft,	mRight,mBottom,mTop;
	bool mEnabled;

protected:
	EState mState;
	float mVx;  //X軸速度
	float mVy;  //Y軸速度
	float mVz;  //Z軸速度

public:
	//コンストラクタ
	CCharacter(int priority);
	//デストラクタ
	~CCharacter();
	//状態を取得する
	EState State();

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
	virtual void Update() = 0;
};