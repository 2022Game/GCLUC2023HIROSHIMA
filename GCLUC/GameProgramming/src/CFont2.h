#pragma once
#include "CTexture.h"

class CFont2
{
private:
	CTexture mTexture;
public:
	//コンストラクタ
	CFont2();
	//デストラクタ
	~CFont2();

	//Load(ファイル名, 行数, 列数)
	void Load(const char* file, int row, int col);
	//Draw(X座標, Y座標, 幅, 高さ, 文字)
	void Draw(float x, float y, float w, float h, char c);
	//Draw(X座標, Y座標, 幅, 高さ, 文字列)
	void Draw(float x, float y, float w, float h, char c[]);

	//更新処理
	void Update();
};
