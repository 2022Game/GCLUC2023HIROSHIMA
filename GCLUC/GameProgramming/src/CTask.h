#pragma once
#include<string>

class CTaskManager;
class CCharacter;

enum class ETaskPriority
{
	EDefault,           //デフォルト
	ECharacter,         //キャラクター
	EBG,                //背景
	EH,
	ECharacterManager,  //キャラクターマネージャー
	ENum
};

class CTask
{
	friend CTaskManager;

private:
	static CTask* mpinstance;
	CTask* mpprev;   //前のタスクへのポインタ
	CTask* mpnext;   //次のタスクへのポインタ
	int mpriority;   //優先度

public:
	//コンストラクタ
	CTask(int priority);
	//~デストラクタ
	~CTask();
	static CTask* Instance();

	//優先度を設定
	void Setpriority(int priority);
	//優先度を取得
	int GetPriority() const;

	//float GetPos();

	//タスクを削除
	void Delete();

	//描画処理
	virtual void Render() {};
	//更新処理
	virtual void Update() {};
};