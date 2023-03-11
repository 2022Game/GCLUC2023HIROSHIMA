#pragma once
#include "CTask.h"

class CTaskManager
{
private:
	static CTaskManager* mpinstance;  //CTaskManagerのインスタンス
	CTask* mhead;                     //先頭タスクのポインタ
	int mCharacterCount;              //キャラクターの数

public:
	//コンストラクタ
	CTaskManager();
	//デストラクタ
	~CTaskManager();

	//インスタンスを取得
	static CTaskManager* Instance();
	//インスタンスを破棄
	static void ClearInstance();

	//リストに追加
	void Add(CTask* task);
	//リストから削除
	void Remove(CTask* task);
	//タスクを削除
	void Delete(CTask* task);

	//描画処理
	void Render();
	//更新処理
	void Update();
};