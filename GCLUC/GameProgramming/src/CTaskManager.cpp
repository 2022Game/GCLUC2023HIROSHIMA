#include "CTaskManager.h"

CTaskManager* CTaskManager::mpinstance = nullptr;

//�R���X�g���N�^
CTaskManager::CTaskManager()
	:mhead(nullptr)
	,mCharacterCount(0)
{

}

//�f�X�g���N�^
CTaskManager::~CTaskManager()
{
	CTask* next = mhead;
	while (next != nullptr)
	{
		CTask* deleteTask = next;
		next = next->mpnext;
		delete deleteTask;
	}
}

//�C���X�^���X���擾
CTaskManager* CTaskManager::Instance()
{
	if (mpinstance == nullptr)
	{
		mpinstance = new CTaskManager;
	}
	return mpinstance;
}

//�C���X�^���X��j��
void CTaskManager::ClearInstance()
{
	if (mpinstance != nullptr)
	{
		delete mpinstance;
		mpinstance = nullptr;
	}
}

//���X�g�ɒǉ�
void CTaskManager::Add(CTask* task)
{
	if (task->mpriority == 1)
	{
		mCharacterCount++;
	}
	//���X�g�Ƀ^�X�N���Ȃ���
	if (mhead == nullptr)
	{
		mhead = task;
	}
	else  //���X�g�ɂ��łɃ^�X�N���ǉ�����Ă��鎞
	{
		CTask* prev = nullptr;
		CTask* next = mhead;
		while (next != nullptr)
		{
			//�D��x���r
			if (next->mpriority < task->mpriority)
			{
				break;
			}
			prev = next;
			next = next->mpnext; //���̃^�X�N��
		}

		task->mpprev = prev;
		task->mpnext = next;
		if (prev != nullptr)
		{
			/*�ǉ�����^�X�N���D��x�������^�X�N��
			mpnext�ɒǉ�����^�X�N��ݒ�*/
			prev->mpnext = task;
		}
		else
		{
			mhead = task;
		}
		if (next != nullptr)
		{
			next->mpprev = task;
		}
	}
}

//���X�g����폜
void CTaskManager::Remove(CTask* task)//task(��菜���^�X�N)
{
	if (task->mpriority == 1)
	{
		mCharacterCount--;
	}
	//��菜���^�X�N���擪�̏ꍇ
	if (mhead == task)
	{
		mhead = task->mpnext;
	}

	//��菜���^�X�N�̑O���ڑ�����
	CTask* prev = task->mpprev;
	CTask* next = task->mpnext;
	if (prev != nullptr)
	{
		prev->mpnext = task->mpnext;
	}
	if (next != nullptr)
	{
		next->mpprev = task->mpprev;
	}

	//��菜���^�X�N�̐ڑ���͋�ɂ���
	task->mpprev = nullptr;
	task->mpnext = nullptr;
}

//�^�X�N���폜
void CTaskManager::Delete(CTask* task)
{
	delete task;
}

//�`�揈��
void CTaskManager::Render()
{
	CTask* next = mhead;
	while (next != nullptr)
	{
		next->Render();
		next = next->mpnext;
	}
}

//�X�V����
void CTaskManager::Update()
{
	CTask* next = mhead;
	while (next != nullptr)
	{
		next->Update();
		next = next->mpnext;
	}
}

void CTaskManager::Sort()
{
	//�L�����N�^�[���X�g���\�[�g������ɁA
	//�`��D��x��ύX���Ă��
	CTask* next = mhead;
	while (next != nullptr)
	{
		//�D��x�������ꍇ�A�ォ��ǉ������^�X�N�������ɒǉ������̂ŁA
		//�ݒ肷��D��x���Ԃ͓����l��OK
		next->Setpriority((int)ETaskPriority::ECharacter);
		next = next->mpnext;
	}
}