#pragma once
#include "CCharacter.h"
#include "CTexture.h"

//���̃C���X�g
#define WOLFX 2.0f 
#define WOLFY 2.0f

class CWolf : public CCharacter
{
public:
	enum class EState	//���
	{
		EMOVE,	//�ړ�
		ESTOP,	//��~
		EDA,	//�_���[�W
		EDEATH, //���S
		EAT,    //�U��
	};
protected:
public:
	EState State();	//��Ԃ��擾����
	bool Enabled(); //����
	static CWolf* Instance2();
	static int WEhp(); //�I�I�J�~��HP
	//�G�̐���ݒ�
	static void Num(int num);
	//�G�̐����擾
	static int Num();
	//�Փˏ���2
	void Collision();
	//�Փˏ���4
	void Collision(CCharacter* m, CCharacter* o);
	//CWolf(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CWolf(float x, float y, float w, float h, CTexture* pt);
	//�X�V����
	void Update();
	static CTexture mTexture7;
	static CTexture* Texture7();
private:
	static CWolf* spInstance2;
	static int sWEhp; //�I�I�J�~��HP
	static int sNum;	//�G�̐�
	int mWolfTime; //�I�I�J�~�p�̎���
	int mWolfTime2; //�\���̃I�I�J�~�p�̎���
	EState mState; //���
	bool mEnabled; //����
	float mWVx;	//X�����x
	float mWVy;	//Y�����x
};