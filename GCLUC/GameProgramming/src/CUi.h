#pragma once
#include "CFont.h"
/*
* CUi
* ���[�U�[�C���^�t�F�[�X�N���X
*/
class CUi
{
private:
	int mEnemy;	//�G�̐�
	int mHp;    //�v���C���[��HP
	int mTime;	//�o�ߎ���
	CFont mFont;

public:
	//�R���X�g���N�^
	CUi();
	//�f�X�g���N�^
	~CUi();

	//�Q�[���N���A�\��
	void Clear();
	//�Q�[���I�[�o�[�\��
	void Over();
	//�X�^�[�g�\��
	void Start();

	//Enemy(�G�̐�)
	void Enemy(int enemy);
	void Hp(int hp);
	//Time(����)
	void Time(int time);
	void Render();
};
