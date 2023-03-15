#include "CSlime.h"
#include "CApplication.h"
#include "CCharacter.h"

//�����G
#define SLIMENTL 37,163,176,63
#define SLIMENTR 163,37,176,63
//�W�����v
#define SLIMEJPL 629,775,189,29
#define SLIMEJPR 775,629,189,29
//�~��
#define SLIMEDWL 1036,1175,170,5
#define SLIMEDWR 1175,1036,170,5
//�_���[�W
#define SLIMEDAL 230,369,174,62
#define SLIMEDAR 369,230,174,62
//�U��
#define SLIMEATL 408,589,188,18
#define SLIMEATR 589,408,188,18
//���S
#define SLIMEDTL 812,988,186,89
#define SLIMEDTR 988,812,186,89
#define SLIMEDTL2 812,988,186,69
#define SLIMEDTR2 988,812,186,69
#define SLIMEDTL3 812,988,186,49
#define SLIMEDTR3 988,812,186,49
#define SLIMEDTL4 812,988,186,29
#define SLIMEDTR4 988,812,186,29
#define SLIMEDTL5 812,988,186,9
#define SLIMEDTR5 988,812,186,9

#define GRAVITY (TIPSIZE / 250.0f)	
#define GRAVITY2 (TIPSIZE / 120.0f)//�d�͉����x
#define JUMPV0 (TIPSIZE / 8.0f)	//�W�����v�̏���

#define SLIMEHP 300 //�X���C����HP

int CSlime::sSEhp = 0;

int CSlime::sNum = 0;

CSlime* CSlime::spInstance2 = nullptr;

CSlime* CSlime::Instance2()
{
	return spInstance2;
}

int CSlime::SEhp()
{
	return sSEhp;
}

void CSlime::Num(int num)
{
	sNum = num;
}

int CSlime::Num()
{
	return sNum;
}

void CSlime::Collision()
{
	//CApplication::CharacterManager()->Collision(this);
}

void CSlime::Collision(CCharacter* m, CCharacter* o)
{
	////�߂荞�ݒ����ϐ���錾����
	//float x, y;
	//switch (o->Tag())
	//{
	//case ETag::ETURN:
	//	//�܂�Ԃ��ɓ���������
	//	if (CRectangle::Collision(o, &x, &y))
	//	{
	//		//�߂荞�܂Ȃ��ʒu�܂Ŗ߂�
	//		X(X() + x);
	//		Y(Y() + y);
	//		//X�����x�𔽓]������
	//		mVx = -mVx;
	//	}
	//	break;
	//case ETag::EENEMY:
	//	break;
	//case ETag::EPLAYER:
	//	if (CRectangle::Collision(o))
	//	{
	//		if (o->State() == EState::EJUMP)
	//		{
	//			if (mState != EState::ECRY)
	//			{
	//				mSuraTime = 90;
	//				sEHp--;
	//			}
	//			mState = EState::ECRY;
	//		}
	//	}
	//	break;
	//case ETag::EBLOCK:
	//	if (CRectangle::Collision(o, &x, &y))
	//	{
	//		X(X() + x);
	//		Y(Y() + y);
	//		//���n������
	//		if (y != 0.0f)
	//		{
	//			//Y�����x��0�ɂ���
	//			mVy = 0.0f;
	//			if (y > 0.0f)
	//			{
	//				if (mState != EState::ECRY && mState != EState::EDEATH)
	//				{
	//					mState = EState::EMOVE;
	//				}
	//			}
	//		}
	//	}
	//	break;
	//}
}

CSlime::CSlime(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::ECharacter)
{
	mTexture6.Load("�X���C��.png");
	Set(x, y, w, h);
	Texture(pt, SLIMENTL); //�e�X�g�p�̊J�n���̗����G
	mState = EState::EMOVE;
	sSEhp = SLIMEHP;
	//X��Y�����x�̏����l���ړ����x�ɂ���
	mSVx = SLIMEX;
	mSVy = SLIMEY;
	spInstance2 = this;
}

void CSlime::Update()
{
	CCharacter::Update();
	//�e�X�g�p���̓L�[
	if (mInput.Key('4'))
	{
		mSlimeTime = 11;
		mState = EState::EDAMAGE;
	}
	if (mInput.Key('5'))
	{
		mSlimeTime3 = 40;
		mState = EState::EATTACK;
	}
	if (mInput.Key('8'))
	{
		if (mState != EState::EDAMAGE)
		{
			mSlimeTime = 11;
			sSEhp = sSEhp - 100;
			mState = EState::EDAMAGE;
		}
	}
	switch (mState)
	{
	case EState::EMUTEKI:
		break;
	case EState::EDEATH: //���S��
		//mVy -= GRAVITY;
		//�����̃X���C���^�C���̓e�X�g�p�B��
		//��Ɏ��S�p�ƃ_���[�W�p�ɕʁX�ɂ���
		if (mSlimeTime4 > 0)
		{
			mSlimeTime4--;
		}
		if (mSlimeTime4 == 40)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDTL); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDTR); }
		}
		if (mSlimeTime4 == 30)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDTL2); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDTR2); }
		}
		if (mSlimeTime4 == 20)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDTL3); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDTR3); }
		}
		if (mSlimeTime4 == 10)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDTL4); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDTR4); }
		}
		if (mSlimeTime4 == 5)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDTL5); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDTR5); }
		}
		if (mSlimeTime4 == 0)
		{
		}
		break;
	case EState::ESTOP: //��~���A�N�[���^�C����
		if (mSVx < 0) { Texture(Texture(), SLIMENTL); }
		if (mSVx > 0) { Texture(Texture(), SLIMENTR); }
		break;
	case EState::EATTACK: //�U����
		if (mSlimeTime3 > 0)
		{
			mSlimeTime3--;
		}
		if (mSlimeTime3 == 29)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMENTL); }
			if (mSVx > 0) { Texture(Texture(), SLIMENTR); }
		}
		if (mSlimeTime3 == 10)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEATL); }
			if (mSVx > 0) { Texture(Texture(), SLIMEATR); }
		}
		if (mSlimeTime3 == 0)
		{
			mState = EState::EMOVE;
		}
		break;
	case EState::EDAMAGE: //�_���[�W��
		//�e�X�g�p�Ɏ��S�܂łȂ���悤�ɂ��Ă���
		if (sSEhp <= 0)
		{
			mSlimeTime4 = 41;
			mState = EState::EDEATH;
		}
		if (mSlimeTime > 0)
		{
			mSlimeTime--;
		}
		if (mSlimeTime == 10)
		{
			if (mSVx < 0) { Texture(Texture(), SLIMEDAL); }
			if (mSVx > 0) { Texture(Texture(), SLIMEDAR); }
		}
		if (mSlimeTime <= 0)
		{
			mState = EState::EMOVE;
		}
		break;
	case EState::EJUMP:
		mSlimeTime2--;
		X(X() + mSVx);
		if (X() != CPlayer::Instance()->X())
		{
			//X(X() + mSVx);
			Y(Y() + mSVy);
			if (mSlimeTime2 > 0)
			{
				mSVy -= GRAVITY2;
			}
			if (mSlimeTime2 < 0)
			{
				mSlimeTime2 = 40;
				mState = EState::EMOVE;
			}
			if (mSVy > 0)
			{
				if (mSVx < 0.0f)
				{
					Texture(Texture(), SLIMEJPL);
				}
				if (mSVx > 0.0f)
				{
					Texture(Texture(), SLIMEJPR);
				}
			}
			if (mSVy < 0)
			{
				if (mSVx < 0.0f)
				{
					Texture(Texture(), SLIMEDWL);
				}
				if (mSVx > 0.0f)
				{
					Texture(Texture(), SLIMEDWR);
				}
			}
		}
		break;
	case EState::EMOVE:
		mSlimeTime2--;
		X(X() + mSVx);
		if (X() != CPlayer::Instance()->X())
		{
			Y(Y() + mSVy);
			if (X() < CPlayer::Instance()->X())
			{
				if (mSVx < 0)
					mSVx = -mSVx;
				Texture(Texture(), SLIMEDWR);
			}
			else
			{
				if (mSVx > 0)
					mSVx = -mSVx;
				Texture(Texture(), SLIMEDWL);
			}
			if (Y() < CPlayer::Instance()->Y())
			{
				if (mSVy < 0)
				{
					mSVy = -mSVy;
				}
			}
			else
			{
				if (mSVy > 0)
				{
					mSVy = JUMPV0;
					mSVy = -mSVy;
				}
			}
			if (mState != EState::EJUMP && mSlimeTime2 < 30)
			{
				mSVy = JUMPV0;
				mState = EState::EJUMP;
			}
		}
	}
}

CTexture* CSlime::Texture6()
{
	return &mTexture6;
}
CTexture CSlime::mTexture6;
