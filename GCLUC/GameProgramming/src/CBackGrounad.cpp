#include "CBackGround.h"
#include "CApplication.h"
void CBackGround::Update()
{
	if(CGame::mTime <= 2 && CGame::mTime > 0)
	{
		float x = X() - 0.5f;
		X(x);
	}
	if (CGame::mTime <= 10 && CGame::mTime > 5)
	{
		float x = X() - 0.5f;
		X(x);
	}
}
CBackGround::CBackGround(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt)
	: CCharacter((int)ETaskPriority::EBackGround)
{
	Set(x, y, w, h);
	Texture(pt, l, r, b, t);
}
//ta
