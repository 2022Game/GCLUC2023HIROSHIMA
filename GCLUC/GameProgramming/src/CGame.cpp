#include "CGame.h"
#include "CApplication.h"
#include "CCamera.h"
#include "CTaskManager.h"
#include "main.h"

//コンストラクタ
CGame::CGame()
	: mpUi(nullptr)    
	, mTime(0)
	, mCdx(0)
	, mCdy(0)
{
	mpUi = new CUi();
	//テクスチャの入力
	CApplication::Texture()->Load(TEXTURE);
}

//デストラクタ
CGame::~CGame()
{
	//全てのインスタンス削除
	//CApplication::CharacterManager()->AllDelete();
	//UIを生成している時
	if (mpUi != nullptr)
	{	//UIを削除し、初期化
		delete mpUi;
		mpUi = nullptr;
	}
}


//ゲームクリア判定
//bool CGame::IsClear()
//{
//	return CEnemy2::Num() <= 0;
//}

//ゲームクリア処理
void CGame::Clear()
{
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()->Render();
	CameraSet();
	CCamera::End();
	//UI処理
//	mpUi->Hp(CPlayer::Hp());
}

//ゲームオーバー判定
//bool CGame::IsOver()
//{	//HPが0以下か判定結果を戻す
//	return CPlayer2::Hp() <= 0;
//}

//ゲームオーバー処理
void CGame::Over()
{
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()->Render();
	CameraSet();
	CCamera::End();
	//UI処理
//	mpUi->Hp(CPlayer::Hp());
	/*mpUi->Enemy(CEnemy2::Num());*/
	/*mpUi->Render();*/
	/*mpUi->Over();*/
}

//スタート処理
void CGame::Start()
{
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()-> Render();
//	CameraSet();
	//ゲームの描画
//	CApplication::CharacterManager()->Render();
//	CCamera::End();
	//UI処理
//	mpUi->Hp(CPlayer::Hp());
	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
	mpUi->Start();
	if (mInput.Key(VK_RETURN))
	{	//状態をプレイ中にする
		mpEnemy = new CEnemy(TIPSIZE * 15, TIPSIZE * 4.5, TIPSIZE, TIPSIZE, CApplication::Texture());
		mpPlayer = new CPlayer(TIPSIZE * 10, TIPSIZE * 5, TIPSIZE, TIPSIZE, CApplication::Texture());
		mpEnemy2 = new CEnemy2(TIPSIZE * 20, TIPSIZE * 7, TIPSIZE, TIPSIZE, CApplication::Texture());
		mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 0, 1919, 1079, 0, CApplication::Texture3());
		mpHeart = new CHeart(95.0f, 750.0f, 90.0f, 40.0f, 0, 210, 73, 0, CApplication::Texture100());
	}
}

//更新処理
void CGame::Update()
{
	//更新、衝突、削除、描画
	//CApplication::CharacterManager()->Update();
	//CApplication::CharacterManager()->Collision();
    //CApplication::CharacterManager()->Delete();
	//CApplication::CharacterManager()->Render();
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()->Render();

	CameraSet();
	CCamera::End();
	//UI
	mpUi->Time(mTime++);
	//mpUi->Hp(CPlayer::Hp());
	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
}

void CGame::CameraSet()
{
	//float x = mpPlayer->X() + mCdx;
	//float y = mpPlayer->Y() + mCdy;
	//CCamera::Start(x - WINDOW_WIDTH / 2
	//	, x + WINDOW_WIDTH / 2
	//	, y - WINDOW_HEIGHT / 2
	//	, y + WINDOW_HEIGHT / 2
	//);
}
