#include "CHeart.h"
#include "CApplication.h"

void CHeart::Update()
{
}

CHeart::CHeart(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt)
	: CCharacter((int)ETaskPriority::EUI)
{
	Set(x, y, w, h);
	Texture(pt, l, r, b, t);
}