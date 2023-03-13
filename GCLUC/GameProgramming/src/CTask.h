#pragma once
#include<string>
 
class CTaskManager;

enum class ETaskPriority
{
	ETITLE,             //タイトル画面
	ECharacter,         //キャラクター
	ECharacterManager,  //キャラクターマネージャー
	EBackGround = 1000, //背景
	EUI = 0,             //ハート
};

class CTask
{
	friend CTaskManager;

private:
	CTask* mpprev;   //前のタスクへのポインタ
	CTask* mpnext;   //次のタスクへのポインタ
	int mpriority;   //優先度

public:
	//コンストラクタ
	CTask(int priority);
	//~デストラクタ
	~CTask();

	//優先度を設定
	void Setpriority(int priority);
	//優先度を取得
	int GetPriority() const;

	//タスクを削除
	void Delete();

	//描画処理
	virtual void Render() {};
	//更新処理
	virtual void Update() {};
};