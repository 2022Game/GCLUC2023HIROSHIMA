#include "CBackGround.h"
#include "CApplication.h"
void CBackGround::Update()
{
	/*float x = X() - 0.5f;
	X(x);*/
}
CBackGround::CBackGround(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt)
	: CCharacter((int)ETaskPriority::EBackGround)
{
	Set(x, y, w, h);
	Texture(pt, l, r, b, t);
}
//ta