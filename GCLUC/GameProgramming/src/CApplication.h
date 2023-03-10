#pragma once
#include <vector>
#include "CRectangle.h"
#include "CCharacter.h"
#include "CCharacterManager.h"
#include "CTexture.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CInput.h"
#include "CFont.h"
#include "CGame.h"
#include "CSound.h"
#include "CBackGround.h"


class CApplication
{
private:
	enum class EState
	{
		ESTART,	//ゲーム開始
		EPLAY,	//ゲーム中
		ECLEAR,	//ゲームクリア
		EOVER,	//ゲームオーバー
	};

	CGame* mpGame;      //ゲームクラスのポインタ
	CPlayer* mpPlayer;  //プレイヤークラスのポインタ
	CEnemy* mpEnemy;    //敵クラスのポインタ
	static CTexture mTexture2;
	static CTexture mTexture3;
	static CTexture mTexture4;
	EState mState;
	CInput mInput;
	CFont mFont;
	CBackGround* mpBackGround;

	static CCharacterManager mCharacterManager;
	static CTexture mTexture;
	//ta
public:
	static CCharacterManager* CharacterManager();
	static CTexture* Texture();
	static CTexture* Texture2();
	static CTexture* Texture3();
	static CTexture* Texture4();
	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
};