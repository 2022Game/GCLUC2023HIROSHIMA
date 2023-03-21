#include "CGame.h"
#include "CApplication.h"
#include "CCamera.h"
#include "CTaskManager.h"
#include "main.h"

//�R���X�g���N�^
CGame::CGame()
	: mpUi(nullptr)    
	, mTime(0)
	, mCdx(0)
	, mCdy(0)
	, mH(0)
	, mCt(0)
{
	mpUi = new CUi();
}

//�f�X�g���N�^
CGame::~CGame()
{
	//�S�ẴC���X�^���X�폜
	CTaskManager::Instance()->AllDelete();
	//CApplication::CharacterManager()->AllDelete();
	//UI�𐶐����Ă��鎞
	if (mpUi != nullptr)
	{	//UI���폜���A������
		delete mpUi;
		mpUi = 0;
	}
}


//�Q�[���N���A����
//bool CGame::IsClear()
//{
//	return CEnemy2::Num() <= 0;
//}

//�Q�[���N���A����
void CGame::Clear()
{
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()->Render();
	/*CameraSet();
	CCamera::End();*/
	if (mH == 1)
	{
		mpBackGround4 = new CBackGround4(640.0f, 400.0f, 640.0f, 400.0f, 0, 1281, 801, 0, CApplication::Texture5());
		mH = 2;
	}
	//UI����
//	mpUi->Hp(CPlayer::Hp());
}

//�Q�[���I�[�o�[����
//bool CGame::IsOver()
//{	//HP��0�ȉ������茋�ʂ�߂�
//	return CPlayer2::Hp() <= 0;
//}

//�Q�[���I�[�o�[����
void CGame::Over()
{
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()->Render();
	if (mH == 1)
	{
		mpBackGround4 = new CBackGround4(640.0f, 400.0f, 640.0f, 400.0f, 0, 1281, 801, 0, CApplication::Texture4());
		mH = 2;
	}
	/*CameraSet();
	CCamera::End();*/
	//UI����
//	mpUi->Hp(CPlayer::Hp());
	/*mpUi->Enemy(CEnemy2::Num());*/
	/*mpUi->Render();*/
	/*mpUi->Over();*/
}

//�X�^�[�g����
void CGame::Start()
{
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()-> Render();
	if (mH == 0)
	{
		mpBackGround4 = new CBackGround4(640.0f, 400.0f, 640.0f, 400.0f, 0, 1281, 801, 0, CApplication::Texture3());
		mH = 1;
	}
//	CameraSet();
	//�Q�[���̕`��
//	CApplication::CharacterManager()->Render();
//	CCamera::End();
	//UI����
	//mpUi->Hp(CPlayer::HP());
	//mpUi->Enemy(CEnemy2::Num());
	//mpUi->Render();
	//mpUi->Start();
	//if (mInput.Key(VK_RETURN))
	//{	//��Ԃ��v���C���ɂ���
	//	mpWolf = new CWolf(TIPSIZE * 15, TIPSIZE * 4.5, TIPSIZE, TIPSIZE, CWolf::Texture7());
	//	mpPlayer = new CPlayer(TIPSIZE * 10, TIPSIZE * 5, TIPSIZE, TIPSIZE, CApplication::Texture());
	//	mpSlime = new CSlime(TIPSIZE * 20, TIPSIZE * 7, TIPSIZE, TIPSIZE, CSlime::Texture6());
	//	mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 0, 1919, 1079, 0, CApplication::Texture3());
	//	mpHeart = new CHeart(95.0f, 750.0f, 90.0f, 40.0f, 0, 210, 73, 0, CApplication::Texture100());
	//}
}

void CGame::Stage1()
{
	mpWolf = new CWolf( 800.0f ,250.0f ,80.0f, 60.0f, CWolf::Texture7());
	mpPlayer = new CPlayer(400.0f, 250.0f, 110.0f, 110.0f, CApplication::Texture());
	mpSlime = new CSlime(1000.0f, 100.0f, 80.0f, 60.0f, CSlime::Texture6());
	mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 0, 1279, 799, 0, CApplication::Texture6());
	mpBackGround2 = new CBackGround2(640.0f, 400.0f, 640.0f, 400.0f, 0, 1279, 799, 0, CApplication::Texture7());
	mpBackGround3 = new CBackGround3(640.0f, 400.0f, 640.0f, 400.0f, 0, 1279, 799, 0, CApplication::Texture8());
	mpBackGround = new CBackGround(1920.0f, 400.0f, 640.0f, 400.0f, 0, 1279, 799, 0, CApplication::Texture6());
	mpBackGround2 = new CBackGround2(1920.0f, 400.0f, 640.0f, 400.0f, 0, 1279, 799, 0, CApplication::Texture7());
	mpBackGround3 = new CBackGround3(1920.0f, 400.0f, 640.0f, 400.0f, 0, 1279, 799, 0, CApplication::Texture8());
	//mpHeart = new CHeart(95.0f, 750.0f, 90.0f, 40.0f, 0, 49, 49, 0, CApplication::Texture100());
}

//�X�V����
void CGame::Update()
{
	mNum = CWolf::Num() + CSlime::Num();
	//�X�V�A�ՓˁA�폜�A�`��
	//CApplication::CharacterManager()->Update();
	//CApplication::CharacterManager()->Collision();
    //CApplication::CharacterManager()->Delete();
	//CApplication::CharacterManager()->Render();
	CTaskManager::Instance()->Update();
	CTaskManager::Instance()->Collision();
	CTaskManager::Instance()->Render();

	CameraSet();
	CCamera::End();
	//UI
	mCt++;
	if (mCt == 60)
	{
		mpUi->Time(mTime++);
		mCt = 0;
	}
	mpUi->Hp(CPlayer::HP());
	mpUi->Stamina(CPlayer::Stamina());
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
int CGame::mNum = 0;
int CGame::Num()
{
	return mNum;
}
