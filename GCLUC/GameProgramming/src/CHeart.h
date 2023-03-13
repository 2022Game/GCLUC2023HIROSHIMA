#pragma once
#include "CCharacter.h"
#include "CCharacterManager.h"
class CHeart : public CCharacter
{
protected:
public:
	CHeart::CHeart(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt);
	void Update();
};