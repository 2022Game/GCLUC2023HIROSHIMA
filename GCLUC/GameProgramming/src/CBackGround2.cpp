#include "CBackGround2.h"
#include "CApplication.h"
void CBackGround2::Update()
{
	float x = X() - 0.4f;
	X(x);
}
CBackGround2::CBackGround2(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt)
	: CCharacter((int)ETaskPriority::EBackGround2)
{
	Set(x, y, w, h);
	Texture(pt, l, r, b, t);
}