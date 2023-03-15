#pragma once
#include "CCharacter.h"

class CStamina : public CCharacter
{
protected:
public:
	CStamina::CStamina(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt);
	void Update();
};