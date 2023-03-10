#pragma once
#include"CTask.h"
#include"CRectangle.h"
#include"CTexture.h"
/*
�L�����N�^�[�N���X
�Q�[���L�����N�^�̊�{�I�ȋ@�\���`����
*/
class CCharacter : public CRectangle, public CTask
{
private:
	CTask* mptask;
	CTexture* mpTexture;
	int mLeft,
		mRight,
		mBottom,
		mTop;
	bool mEnabled;
public:
	//�R���X�g���N�^
	CCharacter(int priority);
	//�f�X�g���N�^
	~CCharacter();

	//�`�揈��
	void Render();
	CTexture* Texture();
	void Texture(CTexture* pTexture,
		int left, int right, int bottom, int top);

	//�Փˏ���
	virtual void Collision(CCharacter* m, CCharacter* o) {}
	//�Փˏ���2
	virtual void Collision() {};

	bool Enabled();
	void Update();
};