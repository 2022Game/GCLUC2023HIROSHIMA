#include "CSlime.h"
#include "CApplication.h"

//�����G
#define SLIMENTL 69,189,193,78
#define SLIMENTR 189,69,193,78
//�W�����v
#define SLIMEJPL 795,980,1462,1286
#define SLIMEJPR 980,795,1462,1286
//�~��
#define SLIMEDWL 1276,1470,1463,1269
#define SLIMEDWR 1470,1276,1463,1269
//�_���[�W
#define SLIMECRYL 236,173,363,63
#define SLIMECRYR 173,236,363,63
//�U��
#define SLIMEATL 420,188,567,27
#define SLIMEATR 188,420,567,27
//���S
#define SLIMEDTL 1031,1228,1491,1350
#define SLIMEDTR 1228,1031,1491,1350
#define SLIMEDTL2 1031,1228,1491,1300
#define SLIMEDTR2 1228,1031,1491,1300
#define SLIMEDTL3 1031,1228,1491,1250
#define SLIMEDTR3 1228,1031,1491,1250
#define SLIMEDTL4 1031,1228,1491,1150
#define SLIMEDTR4 1228,1031,1491,1150
#define SLIMEDTL5 1031,1228,1491,1050
#define SLIMEDTR5 1228,1031,1491,1050

#define GRAVITY (TIPSIZE / 20.0f)	//�d�͉����x
#define JUMPV0 (TIPSIZE / 2.0f)		//�W�����v�̏���

#define SLIMEHP 100 //�X���C����HP

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
	mVx = SLIMEX;
	mVy = SLIMEY;
	spInstance2 = this;
}

void CSlime::Update()
{
	switch (mState)
	{
	case EState::EDEATH: //���S��
		mVy -= GRAVITY;
		if (mSlimeTime > 0)
		{
			mSlimeTime--;
		}
		if (mSlimeTime == 50)
		{
			if (mVx < 0) { Texture(Texture(), SLIMEDTL); }
			if (mVx > 0) { Texture(Texture(), SLIMEDTR); }
		}
		if (mSlimeTime == 40)
		{
			if (mVx < 0) { Texture(Texture(), SLIMEDTL2); }
			if (mVx > 0) { Texture(Texture(), SLIMEDTR2); }
		}
		if (mSlimeTime == 30)
		{
			if (mVx < 0) { Texture(Texture(), SLIMEDTL3); }
			if (mVx > 0) { Texture(Texture(), SLIMEDTR3); }
		}
		if (mSlimeTime == 20)
		{
			if (mVx < 0) { Texture(Texture(), SLIMEDTL4); }
			if (mVx > 0) { Texture(Texture(), SLIMEDTR4); }
		}
		if (mSlimeTime == 10)
		{
			if (mVx < 0) { Texture(Texture(), SLIMEDTL5); }
			if (mVx > 0) { Texture(Texture(), SLIMEDTR5); }
		}
		if (mSlimeTime == 0)
		{
			mEnabled = false;
		}
		break;
	case EState::EAT: //�U����
	case EState::EDA: //�_���[�W��
		/*if (mSlimeTime > 0)
		{
			{mState = EState::EDEATH; }
		}
		Y(Y() + mVy);
		mVy -= GRAVITY;
		if (mVx < 0)
		{
			Texture(Texture(), SLIMECRYL);
		}
		if (mVx > 0)
		{
			Texture(Texture(), SLIMECRYR);
		}
		break;*/
	case EState::EJUMP:
		X(X() + mVx);
		Y(Y() + mVy);
		//mVy -= GRAVITY;
		//mVy = JUMPV0;
		if (mVy > 0)
		{
			if (mVx < 0.0f)
			{
				Texture(Texture(), SLIMEJPL);
			}
			if (mVx > 0.0f)
			{
				Texture(Texture(), SLIMEJPR);
			}
		}
		if (mVy < 0)
		{
			if (mVx < 0.0f)
			{
				Texture(Texture(), SLIMEDWL);
			}
			if (mVx > 0.0f)
			{
				Texture(Texture(), SLIMEDWR);
			}
		}
		break;
	case EState::EMOVE:
		//mVy -= GRAVITY;
		X(X() + mVx);
		Y(Y() + mVy);
		if (X() < CPlayer::Instance()->X())
		{
			if (mVx < 0)
				mVx = -mVx;
			Texture(Texture(), SLIMENTR);
		}
		else
		{
			if (mVx > 0)
				mVx = -mVx;
			Texture(Texture(), SLIMENTL);
		}
		if (Y() < CPlayer::Instance()->Y())
		{
			if (mVy < 0)
				mVy = -mVy;
		}
		else
		{
			if (mVy > 0)
				mVy = -mVy;
		}
		if (mState != EState::EJUMP)
		{
			/*mVy = JUMPV0;
			mState = EState::EJUMP;*/
		}
		break;
	}
}

CTexture* CSlime::Texture6()
{
	return &mTexture6;
}
CTexture CSlime::mTexture6;