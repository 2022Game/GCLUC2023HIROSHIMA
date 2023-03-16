#include "CStamina.h"
#include "CApplication.h"

#define Texture101 41,207,75,24

void CStamina::Update()
{
}

CStamina::CStamina(float x, float y, float w, float h, CTexture* pt)
	: mLeft(41)
	, mRight(207)
	, mBottom(75)
	, mTop(24)
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