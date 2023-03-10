#include "CTaskManager.h"

CTaskManager* CTaskManager::mpinstance = nullptr;

//コンストラクタ
CTaskManager::CTaskManager()
	:mhead(nullptr)
	,mCharacterCount(0)
{

}

//デストラクタ
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

//インスタンスを取得
CTaskManager* CTaskManager::Instance()
{
	if (mpinstance == nullptr)
	{
		mpinstance = new CTaskManager;
	}
	return mpinstance;
}

//インスタンスを破棄
void CTaskManager::ClearInstance()
{
	if (mpinstance != nullptr)
	{
		delete mpinstance;
		mpinstance = nullptr;
	}
}

//リストに追加
void CTaskManager::Add(CTask* task)
{
	if (task->mpriority == 1)
	{
		mCharacterCount++;
	}
	//リストにタスクがない時
	if (mhead == nullptr)
	{
		mhead = task;
	}
	else  //リストにすでにタスクが追加されている時
	{
		CTask* prev = nullptr;
		CTask* next = mhead;
		while (next != nullptr)
		{
			//優先度を比較
			if (next->mpriority < task->mpriority)
			{
				break;
			}
			prev = next;
			next = next->mpnext; //次のタスクへ
		}

		task->mpprev = prev;
		task->mpnext = next;
		if (prev != nullptr)
		{
			/*追加するタスクより優先度が高いタスクの
			mpnextに追加するタスクを設定*/
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

//リストから削除
void CTaskManager::Remove(CTask* task)//task(取り除くタスク)
{
	if (task->mpriority == 1)
	{
		mCharacterCount--;
	}
	//取り除くタスクが先頭の場合
	if (mhead == task)
	{
		mhead = task->mpnext;
	}

	//取り除くタスクの前後を接続する
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

	//取り除くタスクの接続先は空にする
	task->mpprev = nullptr;
	task->mpnext = nullptr;
}

//タスクを削除
void CTaskManager::Delete(CTask* task)
{
	delete task;
}

//描画処理
void CTaskManager::Render()
{
	CTask* next = mhead;
	while (next != nullptr)
	{
		next->Render();
		next = next->mpnext;
	}
}

//更新処理
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
	//キャラクターリストをソートした後に、
	//描画優先度を変更してやる
	CTask* next = mhead;
	while (next != nullptr)
	{
		//優先度が同じ場合、後から追加したタスクが末尾に追加されるので、
		//設定する優先度事態は同じ値でOK
		next->Setpriority((int)ETaskPriority::ECharacter);
		next = next->mpnext;
	}
}