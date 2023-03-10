#include "CApplication.h"
#include "CRectangle.h"

CTexture CApplication::mTexture;

CTexture* CApplication::Texture()
{
	return &mTexture;
}

void CApplication::Start()
{
	mTexture.Load("PlayerImage.png");
	mTexture2.Load("背景(仮) .png");
	mTexture3.Load("(仮).png");
	mTexture4.Load("(仮)2.png");
	mTexture5.Load("(仮)3.png");
	mTexture100.Load("プレイヤーHP.png");
	mFont.Load("FontWhite.png", 1, 64);
	mState = EState::ESTART;
	mpGame = new CGame();
}

void CApplication::Update()
{
	switch (mState)
	{
	case EState::ESTART:	//状態がスタート
		mpGame->Start();	//スタート画面表示
		//mCharacterManager.Add(mpBackGround);
		if (mInput.Key(VK_RETURN))
		{	//状態をプレイ中にする
			mState = EState::ESTAGE1;
		}
		break;
	case EState::ESTAGE1:
		mpGame->Stage1();
		mState = EState::EPLAY;
	break;
	case EState::EPLAY:
		mpGame->Update();
		if (mInput.Key(VK_SPACE))
		{
			mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 2, 2665, 1564, 68, &mTexture4);
				mState = EState::EOVER;
		}
		if (mInput.Key(VK_BACK))
		{
			mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 2, 2665, 1564, 68, &mTexture5);
			mState = EState::ECLEAR;
		}
		////ゲームオーバーか判定
		//if (mpGame->IsOver())
		//{	//状態をゲームオーバーにする
		//	mState = EState::EOVER;
		//	//ゲームオーバー
		//	mSoundOver.Play();
		//}
		//ゲームクリアか判定
		//if (mpGame->IsClear())
		//{	//状態をゲームクリアにする
		//	mState = EState::ECLEAR;
		//}
		break;

	case EState::EOVER:
		//ゲームオーバー処理
		mpGame->Over();
		//エンターキー入力時
		if (mInput.Key(VK_RETURN))
		{	//ゲームのインスタンス削除
			delete mpGame;
			//ゲームのインスタンス生成
			mpGame = new CGame();
			//状態をスタートにする
			mState = EState::ESTART;
		}
		break;

	case EState::ECLEAR:
		//ゲームクリア処理
		mpGame->Clear();
		if (mInput.Key(VK_RETURN))
		{
			delete mpGame;
			mpGame = new CGame();
			mState = EState::ESTART;
		}
		break;
	}
}
CTexture CApplication::mTexture2;
CTexture* CApplication::Texture2()
{
	return &mTexture2;
}
CTexture CApplication::mTexture3;
CTexture* CApplication::Texture3()
{
	return &mTexture3;
}
CTexture CApplication::mTexture4;
CTexture* CApplication::Texture4()
{
	return &mTexture4;
}
CTexture CApplication::mTexture5;
CTexture* CApplication::Texture5()
{
	return &mTexture5;
}

CTexture CApplication::mTexture100;
CTexture* CApplication::Texture100()
{
	return &mTexture100;
}