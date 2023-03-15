#pragma once
#include "CUi.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CEnemy2.h"
#include "CBackGround.h"
#include "CHeart.h"
#include "CInput.h"
#include "CSlime.h"
#include "CWolf.h"

//�萔�̒�`
#define TEXTURE "image.png"//�e�N�X�`���̃t�@�C����
#define TIPSIZE 40.0f //��{�T�C�Y
/*
* CGame�N���X
* �Q�[���N���X
* �Q�[���̃}�b�v���쐬���A
* �L�����N�^��z�u����
*/
class CGame
{
private:
	CPlayer* mpPlayer; //�v���C���[�̃|�C���^
	CEnemy* mpEnemy;   //�G�̃|�C���^
	CEnemy2* mpEnemy2; //�G�Q�̃|�C���^
	CSlime* mpSlime;
	CWolf* mpWolf;
	CBackGround* mpBackGround;
	CHeart* mpHeart;
	CInput mInput;

	int mCdx, mCdy;    //�J�����ƃv���C���[�̍��W�̍���
	void CameraSet();  //�J�����ݒ�
	int mTime;         //�o�ߎ���
	CUi* mpUi;         //UI�N���X�̃|�C���^

public:
	//�R���X�g���N�^
	CGame();
	//�f�X�g���N�^
	~CGame();

	//�Q�[���N���A����
	//bool IsClear();
	//�Q�[���N���A����
	void Clear();

	//�Q�[���I�[�o�[����
	//bool IsOver();
	//�Q�[���I�[�o�[����
	void Over();

	//�X�^�[�g����
	void Start();
	//Stage1
	void Stage1();

	//�X�V����
	void Update();
};
