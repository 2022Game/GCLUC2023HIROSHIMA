#pragma once
#include "CCharacter.h"
#include "CInput.h"
/*
�v���C���[�N���X
�L�����N�^�X���p��
*/
class CPlayer : public CCharacter
{
private:
	static CPlayer* spinstance; //�v���C���[�̃C���X�^���X
	static int sHp;             //�v���C���[��HP
	static int sStamina;        //�v���C���[�̃X�^�~�i

	int mInvincible;            //���G�J�E���^
	int mIdlingcount;           //�A�j���[�V�����p�J�E���^(�A�C�h�����O)
	int mJumpcount;             //�A�j���[�V�����p�J�E���^(�W�����v)
	int mMovecount;             //�A�j���[�V�����p�J�E���^(�ړ�)
	int mAttackcount;           //�A�j���[�V�����p�J�E���^(�U��)

	float mJumpY;               //�v���C���[�̃W�����v����Y���W
	CInput mInput;              //�L�[���͔���

public:
	//�R���X�g���N�^
	//CPlayer(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CPlayer(float x, float y, float w, float h, CTexture* pt);
	//~�f�X�g���N�^
	~CPlayer();

	//�C���X�^���X�̃|�C���^�̎擾
	static CPlayer* Instance();
	//�v���C���[��HP���擾
	static int HP();
	//�v���C���[�̃X�^�~�i���擾
	static int Stamina();
	//�X�V����
	void Update();
};