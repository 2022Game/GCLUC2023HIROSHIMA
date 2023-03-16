#pragma once
#include "CTask.h"
#include <vector>
#include "CCharacter.h"

class CTaskManager
{
private:
	static CTaskManager* spinstance;  //CTaskManagerのインスタンス
	CTask* mhead;                     //先頭タスクのポインタ
	int mCharacterCount; 
	std::vector<CTask*> mpTasks;//キャラクターの数

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
	//衝突処理１

	void Collision();
	//衝突処理３
	//Collision(衝突元のポインタ)
	void Collision(CTask* task);
};