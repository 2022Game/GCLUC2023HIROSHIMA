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
	//�v���C���[�̃C���X�^���X
	static CPlayer* mpinstance;
	CInput mInput;

public:
	//�R���X�g���N�^
    //CPlayer(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CPlayer(float x, float y, float w, float h, CTexture* pt);
	//~�f�X�g���N�^
	~CPlayer();

	//�C���X�^���X�̃|�C���^�̎擾
	static CPlayer* Instance();

	//�X�V����
	void Update();

	static int sHp;	//HP

	//HP���擾
	static int Hp();
};