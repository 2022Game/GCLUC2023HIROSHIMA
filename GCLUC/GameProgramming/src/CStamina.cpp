#include "CStamina.h"
#include "CApplication.h"

void CStamina::Update()
{
}

CStamina::CStamina(float x, float y, float w, float h, CTexture* pt)

{
	Set(x, y, w, h);
	mpTexture = pt;
}

void CStamina::Render()
{
	mpTexture->DrawImage(
		X() - W(),
		X() + W(),
		Y() - H(),
		Y() + H(),
		mLeft, mRight, mBottom, mTop);
}