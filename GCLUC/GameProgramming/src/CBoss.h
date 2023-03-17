#pragma once
#include "CCharacter.h"
#include "CTexture.h"
#include "CInput.h"
#include "CEattack.h"

#define BOSSX 1.0f 
#define BOSSY 1.0f

class CBoss : public CCharacter
{
	friend CEattack;
public:
	enum class EState	//���
	{
		EMOVE,	//�ړ�
		ESTOP,	//��~
		EDAMAGE,	//�_���[�W
		EDEATH, //���S
		EBACK, //����
		EATTACK,    //�U��
		EMUTEKI,
	};
protected:
public:
	EState State();	//��Ԃ��擾����
	bool Enabled(); //����
	static CBoss* Instance4();
	static int BEhp(); //�I�I�J�~��HP
	//�G�̐���ݒ�
	static void Num(int num);
	//�G�̐����擾
	static int Num();
	//�Փˏ���2
	void Collision();
	//�Փˏ���4
	void Collision(CCharacter* m, CCharacter* o);
	//CWolf(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CBoss(float x, float y, float w, float h, CTexture* pt);
	//�X�V����
	void Update();
	static CTexture mTexture8;
	static CTexture* Texture8();
private:
	CEattack* mpEattack;
	static CBoss* spInstance4;
	static int sBEhp; //�{�X��HP
	static int sNum;	//�G�̐�
	int mBossEattack; //�U����������
	int mBossTime; //�U���̃{�X�p�̎���
	int mBossTime2; //�_���[�W�̃{�X�p�̎���
	int mBossTime3; //���S�̃{�X�p�̎���
	int mBossInvincible; //���G�p�̃{�X�p�̎���
	EState mState; //���
	bool mEnabled; //����
	float mBVx;	//X�����x
	float mBVy;	//Y�����x
	float mBLR;
	CInput mInput;
};