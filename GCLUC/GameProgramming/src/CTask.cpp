#include "CTask.h"
#include "CTaskManager.h"
#include "CCharacter.h"

CTask* CTask::mpinstance = nullptr;

//コンストラクタ
CTask::CTask(int priority)
	: mpprev(nullptr)
	, mpnext(nullptr)
	, mpriority(priority)
{
	CTaskManager::Instance()->Add(this);
}

//デストラクタ
CTask::~CTask()
{
	CTaskManager::Instance()->Remove(this);
}

CTask* CTask::Instance()
{
	return mpinstance;
}

//優先度を設定
void CTask::Setpriority(int priority)
{
	//優先度を設定
	mpriority = priority;
	//新しい優先度の位置にタスクを配置
	CTaskManager::Instance()->Remove(this);
	CTaskManager::Instance()->Add(this);
}

//優先度を取得
int CTask::GetPriority() const
{
	return mpriority;
}

void CTask::Delete()
{
	CTaskManager::Instance()->Delete(this);
}
