#pragma once
#include "CFont.h"
#include "CHeart.h"
#include "CStamina.h"
#include "CGage.h"
#include "CBossHp.h"
/*
* CUi
* ���[�U�[�C���^�t�F�[�X�N���X
*/
class CUi:public CRectangle
{
private:
	//CBossHp mBossHp;
	CStamina mStamina;
	CGage mGage;
	CHeart mHeart;
	int mEnemy;	//�G�̐�
	int mHp;    //�v���C���[��HP
	int mStaminagage; //�v���C���[�̃X�^�~�i
	int mTime;	//�o�ߎ���
	CFont mFont;

public:
	CTexture mTexture100;
	CTexture mTexture101;
	CTexture mTexture102;
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
	//Hp(�̗�)
	void Hp(int hp);
	//Stamina(�X�^�~�i)
	void Stamina(int stamina);
	//BossHp(�{�XHP)
	void BEhp(int behp);
	//Time(����)
	void Time(int time);
	void Render();
};
