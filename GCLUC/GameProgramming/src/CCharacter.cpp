#include "CCharacter.h"
#include "CApplication.h"
#include "CTaskManager.h"

//コンストラクタ
CCharacter::CCharacter(int priority)
	: CTask(priority)
	, mpTexture(nullptr)
	, mLeft(0)
	, mRight(0)
	, mBottom(0)
	, mTop(0)
	, mEnabled(false)
{
}

//デストラクタ
CCharacter::~CCharacter()
{
}


void CCharacter::Texture(CTexture* pTexture,
	int left, int right, int bottom, int top)
{
	mpTexture = pTexture;
	mLeft = left;
	mRight = right;
	mBottom = bottom;
	mTop = top;
}

CTexture* CCharacter::Texture()
{
	return mpTexture;
}

//描画処理
void CCharacter::Render()
{
	mpTexture->DrawImage(
		X() - W(),
		X() + W(),
		Y() - H(),
		Y() + H(),
		mLeft, mRight, mBottom, mTop);
}

bool CCharacter::Enabled()
{
	return mEnabled;
}

void CCharacter::Update()
{

}