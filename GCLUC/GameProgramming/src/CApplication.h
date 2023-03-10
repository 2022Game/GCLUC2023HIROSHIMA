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


class CApplication
{
private:
	enum class EState
	{
		ESTART,	//�Q�[���J�n
		EPLAY,	//�Q�[����
		ECLEAR,	//�Q�[���N���A
		EOVER,	//�Q�[���I�[�o�[
	};

	CGame* mpGame;      //�Q�[���N���X�̃|�C���^
	CPlayer* mpPlayer;  //�v���C���[�N���X�̃|�C���^
	CEnemy* mpEnemy;    //�G�N���X�̃|�C���^
	static CTexture mTexture2;
	EState mState;
	CInput mInput;
	CFont mFont;
	CBackGround* mpBackGround;

	static CCharacterManager mCharacterManager;
	static CTexture mTexture;

public:
	static CCharacterManager* CharacterManager();
	static CTexture* Texture();
	static CTexture* Texture2();
	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
};