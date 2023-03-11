#pragma once
#include<string>
 
class CTaskManager;

enum class ETaskPriority
{
	ECharacter,         //�L�����N�^�[
	ECharacterManager,  //�L�����N�^�[�}�l�[�W���[
	ENum,
	EBackGround = 1000,        //�w�i
};

class CTask
{
	friend CTaskManager;

private:
	static CTask* mpinstance;
	CTask* mpprev;   //�O�̃^�X�N�ւ̃|�C���^
	CTask* mpnext;   //���̃^�X�N�ւ̃|�C���^
	int mpriority;   //�D��x

public:
	//�R���X�g���N�^
	CTask(int priority);
	//~�f�X�g���N�^
	~CTask();
	static CTask* Instance();

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