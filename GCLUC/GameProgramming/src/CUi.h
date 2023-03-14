#pragma once
#include "CFont.h"
#include "CHeart.h"
/*
* CUi
* ���[�U�[�C���^�t�F�[�X�N���X
*/
class CUi:public CRectangle
{
private:
	CHeart* mpHeart;
	int mEnemy;	//�G�̐�
	int mHp;    //�v���C���[��HP
	int mTime;	//�o�ߎ���
	CFont mFont;

public:
	CTexture mTexture100;
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
