#pragma once
#include <vector>
#include "CRectangle.h"
#include "CCharacter.h"
#include "CCharacterManager.h"
#include "CTexture.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CInput.h"
#include "CFont.h"
#include "CGame.h"
#include "CSound.h"
#include "CBackGround.h"
#include "CHeart.h"


class CApplication
{
private:
	enum class EState
	{
		ESTART,	//�Q�[���J�n
		EPLAY,	//�Q�[����
		ESTAGE1,
		ECLEAR,	//�Q�[���N���A
		EOVER,	//�Q�[���I�[�o�[
	};

	CGame* mpGame;      //�Q�[���N���X�̃|�C���^
	CPlayer* mpPlayer;  //�v���C���[�N���X�̃|�C���^
	CEnemy* mpEnemy;    //�G�N���X�̃|�C���^
	EState mState;
	CInput mInput;
	CFont mFont;
	CBackGround* mpBackGround;

	static CTexture mTexture;  //�v���C���[�e�N�X�`��
	static CTexture mTexture2; //�w�i�e�N�X�`��
	static CTexture mTexture3; //�X�^�[�g��ʃe�N�X�`��
	static CTexture mTexture4; //�Q�[���I�[�o�[��ʃe�N�X�`��
	static CTexture mTexture5; //�Q�[���N���A��ʃe�N�X�`��
	static CTexture mTexture6;
	static CTexture mTexture7;
	static CTexture mTexture8;
	static CTexture mTexture100; //�n�[�g�\���e�N�X�`��
	int mRb;

public:
	static CTexture* Texture();
	static CTexture* Texture2();
	static CTexture* Texture3();
	static CTexture* Texture4();
	static CTexture* Texture5();
	static CTexture* Texture6();
	static CTexture* Texture7();
	static CTexture* Texture8();
	static CTexture* Texture100();
	CApplication();
	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
};