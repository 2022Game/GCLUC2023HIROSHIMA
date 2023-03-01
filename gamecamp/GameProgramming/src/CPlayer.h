#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�X�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CInput.h"
#include "CBullet.h"
#include "CColliderLine.h"
/*
�v���C���[�N���X
�L�����N�^�X���p��
*/
class CPlayer : public CCharacter3
{
public:
	//�C���X�^���X�̃|�C���^�̎擾
	static CPlayer* Instance();
	void Collision();
	//�Փˏ���
	void Collision(CCollider* o, CCollider* m);
	CPlayer();
	//CPlayer(�ʒu,��],�X�P�[��)
	CPlayer(const CVector& pos, const CVector& rot, const CVector& scale);
	//�X�V����
	void Update();
private:
	//�v���C���[�̃C���X�^���X
	static CPlayer* spInstance;
	CColliderLine mLine; //�e���R���C�_
	CColliderLine mLine2; //�e���R���C�_
	CColliderLine mLine3; //�e���R���C�_
	CInput mInput;
};
#endif