#pragma once
#include<string>
 
class CTaskManager;

enum class ETaskPriority
{
	ETITLE,             //�^�C�g�����
	ECharacter,         //�L�����N�^�[
	ECharacterManager,  //�L�����N�^�[�}�l�[�W���[
	EBackGround = 1000, //�w�i
	EUI = 0             //�n�[�g
};

class CTask
{
	friend CTaskManager;

private:
	CTask* mpprev;   //�O�̃^�X�N�ւ̃|�C���^
	CTask* mpnext;   //���̃^�X�N�ւ̃|�C���^
	int mpriority;   //�D��x

public:
	//�R���X�g���N�^
	CTask(int priority);
	//~�f�X�g���N�^
	~CTask();

	//�D��x��ݒ�
	void Setpriority(int priority);
	//�D��x���擾
	int GetPriority() const;

	//�^�X�N���폜
	void Delete();

	//�`�揈��
	virtual void Render() {};
	//�X�V����
	virtual void Update() {};
};