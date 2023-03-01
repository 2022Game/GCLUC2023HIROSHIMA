#ifndef CCHARACTER3_H
#define CCHARACTER3_H
//�ϊ��s��N���X�̃C���N���[�h
#include "CTransform.h"
//���f���N���X�̃C���N���[�h
#include "CModel.h"
#include"CTask.h"
/*
�L�����N�^�[�N���X
�Q�[���L�����N�^�̊�{�I�ȋ@�\���`����
*/
//�R���C�_�N���X�̐錾
class CCollider;
class CCharacter3 : public CTransform, public CTask
{
public:
	enum ETag
	{
		EZERO,          //�����l
		EPLAYER,        //�v���C���[
		EENEMY,         //�G
		EBULLETPLAYER,  //�v���C���[�e
		EBULLETENEMY,   //�G�e
	};
	//�^�O�̎擾
	ETag Tag();
	//�R���X�g���N�^
	CCharacter3(int priority);
	//�Փˏ���
	virtual void Collision(CCollider* m, CCollider* o) {}
	//�R���X�g���N�^
	CCharacter3();
	//�f�X�g���N�^
	~CCharacter3();
	//���f���̐ݒ�
	//Model(���f���N���X�̃|�C���^)
	void Model(CModel* m);
	//�`�揈��
	void Render();
protected:
	ETag mTag; //�^�O
	CModel* mpModel; //���f���̃|�C���^
};

#endif