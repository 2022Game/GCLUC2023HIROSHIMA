#include "CBackGround3.h"
#include "CApplication.h"
void CBackGround3::Update()
{
	float x = X() - 0.6f;
	X(x);
}
CBackGround3::CBackGround3(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt)
	: CCharacter((int)ETaskPriority::EBackGround3)
{
	Set(x, y, w, h);
	Texture(pt, l, r, b, t);
}