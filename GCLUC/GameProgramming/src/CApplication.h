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

	EState mState;
	CInput mInput;
	CFont mFont;

	static CCharacterManager mCharacterManager;
	static CTexture mTexture;

public:
	static CCharacterManager* CharacterManager();
	static CTexture* Texture();

	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
};