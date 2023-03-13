#pragma once
#include "CCharacter.h"
#include "CTexture.h"

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
		EJUMP,	//�W�����v
		EDA,	//�_���[�W
		EDEATH, //���S
		EAT,    //�U��
	};
protected:
public:
	EState State();	//��Ԃ��擾����
	bool Enabled(); //����
	static CSlime* Instance2();
	static int SEhp();
	//�G�̐���ݒ�
	static void Num(int num);
	//�G�̐����擾
	static int Num();
	//�Փˏ���2
	void Collision();
	//�Փˏ���4
	void Collision(CCharacter* m, CCharacter* o);
	//CEnemy2(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CSlime(float x, float y, float w, float h, CTexture* pt);
	//�X�V����
	void Update();
	static CTexture mTexture6;
	static CTexture* Texture6();
private:
	static CSlime* spInstance2;
	static int sSEhp; //�X���C����HP
	static int sNum;	//�G�̐�
	int mSlimeTime; //�X���C���p�̎���
	int mSlimeTime2; //�\���̃X���C���p�̎���
	EState mState; //���
	bool mEnabled; //����
	float mVx;	//X�����x
	float mVy;	//Y�����x
};