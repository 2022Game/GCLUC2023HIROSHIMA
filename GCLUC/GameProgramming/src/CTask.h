#pragma once
#include<string>
 
class CTaskManager;
class CCharacter;

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
	enum class ETag
	{
		EZERO,
		EPLAYER,
		EENEMY,
	};
	ETag Tag();
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
	//衝突処理
	virtual void Collision(CCharacter* m, CCharacter* o) {}
	//衝突処理2
	virtual void Collision() {};
protected:
	ETag mTag;
};