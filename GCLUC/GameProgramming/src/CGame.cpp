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
	//�e�N�X�`���̓���
	CApplication::Texture()->Load(TEXTURE);
	//�G���L�����N�^�}�l�[�W���ɒǉ�����
		mpEnemy = new CEnemy(TIPSIZE * 15, TIPSIZE * 4.5, TIPSIZE, TIPSIZE, CApplication::Texture());
		//�v���C���[���L�����N�^�}�l�[�W���ɒǉ�����
		mpPlayer = new CPlayer(TIPSIZE * 10, TIPSIZE * 5, TIPSIZE, TIPSIZE, CApplication::Texture());

		mpEnemy2 = new CEnemy2(TIPSIZE * 20, TIPSIZE * 7, TIPSIZE, TIPSIZE, CApplication::Texture());
}

//�f�X�g���N�^
CGame::~CGame()
{
	//�S�ẴC���X�^���X�폜
	CApplication::CharacterManager()->AllDelete();
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
	CameraSet();
	//�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	CCamera::End();
	//UI����
//	mpUi->Hp(CPlayer::Hp());
	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
	mpUi->Clear();
}

//�Q�[���I�[�o�[����
//bool CGame::IsOver()
//{	//HP��0�ȉ������茋�ʂ�߂�
//	return CPlayer2::Hp() <= 0;
//}

//�Q�[���I�[�o�[����
void CGame::Over()
{
	CameraSet();
	//�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	CCamera::End();
	//UI����
//	mpUi->Hp(CPlayer::Hp());
	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
	mpUi->Over();
}

//�X�^�[�g����
void CGame::Start()
{
//	CameraSet();
	//�Q�[���̕`��
	CApplication::CharacterManager()->Render();
//	CCamera::End();
	//UI����
//	mpUi->Hp(CPlayer::Hp());
	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
	mpUi->Start();
}

//�X�V����
void CGame::Update()
{
	//�X�V�A�ՓˁA�폜�A�`��
	CApplication::CharacterManager()->Update();
	CApplication::CharacterManager()->Collision();
//	CApplication::CharacterManager()->Delete();
	CApplication::CharacterManager()->Render();
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
