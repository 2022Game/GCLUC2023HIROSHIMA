#ifndef CCOLLIDERLINE_H
#define CCOLLIDERLINE_H
#include "CCollider.h"
/*
�����R���C�_�̒�`
*/
class CColliderLine : public CCollider
{
public:
	//�D��x�̕ύX
	void ChangePriority();
	CColliderLine() {}
	//�R���X�g���N�^(�����R���C�_)
	//CColliderLine(�e�A�e�s��A���_1�A���_2)
	CColliderLine(CCharacter3* parent, CMatrix* matrix, const CVector& v0, const CVector& v1);
	//�e���R���C�_�̐ݒ�
	//Set(�e�A�e�s��A���_1�A���_2)
	void Set(CCharacter3* parent, CMatrix* matrix, const CVector& v0, const CVector& v1);
	//�`��
	void Render();
};
#endif