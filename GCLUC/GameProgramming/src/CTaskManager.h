#pragma once
#include "CTask.h"

class CTaskManager
{
private:
	static CTaskManager* mpinstance;  //CTaskManager�̃C���X�^���X
	CTask* mhead;                     //�擪�^�X�N�̃|�C���^
	int mCharacterCount;              //�L�����N�^�[�̐�

public:
	//�R���X�g���N�^
	CTaskManager();
	//�f�X�g���N�^
	~CTaskManager();

	//�C���X�^���X���擾
	static CTaskManager* Instance();
	//�C���X�^���X��j��
	static void ClearInstance();

	//���X�g�ɒǉ�
	void Add(CTask* task);
	//���X�g����폜
	void Remove(CTask* task);
	//�^�X�N���폜
	void Delete(CTask* task);

	//�`�揈��
	void Render();
	//�X�V����
	void Update();
};