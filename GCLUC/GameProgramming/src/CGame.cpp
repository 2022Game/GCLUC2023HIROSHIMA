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
{
	mpUi = new CUi();
}

//�f�X�g���N�^
CGame::~CGame()
{
	//�S�ẴC���X�^���X�폜
	//CApplication::CharacterManager()->AllDelete();
	//UI�𐶐����Ă��鎞
	if (mpUi != nullptr)
	{	//UI���폜���A������
		delete mpUi;
		mpUi = nullptr;
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
	CameraSet();
	CCamera::End();
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
	CameraSet();
	CCamera::End();
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
	mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 0, 799, 0, 1279, CApplication::Texture3());
//	CameraSet();
	//�Q�[���̕`��
//	CApplication::CharacterManager()->Render();
//	CCamera::End();
	//UI����
	//mpUi->Hp(CPlayer::Hp());
	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
	mpUi->Start();
	if (mInput.Key(VK_RETURN))
	{	//��Ԃ��v���C���ɂ���
		mpEnemy = new CEnemy(TIPSIZE * 15, TIPSIZE * 4.5, TIPSIZE, TIPSIZE, CApplication::Texture());
		mpPlayer = new CPlayer(TIPSIZE * 10, TIPSIZE * 5, TIPSIZE, TIPSIZE, CApplication::Texture());
		mpEnemy2 = new CEnemy2(TIPSIZE * 20, TIPSIZE * 7, TIPSIZE, TIPSIZE, CApplication::Texture());
		mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 0, 1919, 1079, 0, CApplication::Texture3());
		mpHeart = new CHeart(95.0f, 750.0f, 90.0f, 40.0f, 0, 210, 73, 0, CApplication::Texture100());
	}
}

//�X�V����
void CGame::Update()
{
	//�X�V�A�ՓˁA�폜�A�`��
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
