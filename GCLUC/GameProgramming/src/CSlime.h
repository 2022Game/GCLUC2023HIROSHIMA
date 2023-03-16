#pragma once
#include "CCharacter.h"
#include "CTexture.h"
#include "CInput.h"

//���̃C���X�g
#define SLIME "�X���C��.png"
#define SLIMEX 1.5f 
#define SLIMEY 1.5f

class CSlime : public CCharacter
{
public:
	enum class EState	//���
	{
		EMOVE,	//�ړ�
		ESTOP,	//��~
		EMOVE2,	//�W�����v
		EDAMAGE,	//�_���[�W
		EDEATH, //���S
		EATTACK,    //�U��
		EMUTEKI,
	};
protected:
public:
	EState State();	//��Ԃ��擾����
	static CSlime* Instance2();
	int SEhp();
	//�G�̐���ݒ�
	static void Num(int num);
	//�G�̐����擾
	static int Num();
	//�Փˏ���2
	void Collision();
	//�Փˏ���4
	void Collision(CCharacter* m, CCharacter* o);
	//CEnemy2(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CSlime(float x, float y,float w, float h, CTexture* pt);
	//�X�V����
	void Update();
	static CTexture mTexture6;
	static CTexture* Texture6();
private:
	static CSlime* spInstance2;
	int sSEhp; //�X���C����HP
	static int sNum;	//�G�̐�
	int mSlimeTime; //�_���[�W�̃X���C���p�̎���
	int mSlimeTime2; //�ړ��̃X���C���p�̎���
	int mSlimeTime3; //�U���̃X���C���p�̎���
	int mSlimeTime4; //���S�̃X���C���p�̎���
	int mSlimeInvincible; //���G�p�̃X���C���p�̎���
	EState mState; //���
	float mSVx;	//X�����x
	float mSVy;	//Y�����x
	CInput mInput;
};