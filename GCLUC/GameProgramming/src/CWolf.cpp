#include "CWolf.h"
#include "CApplication.h"

//�ړ��P
#define WOLFMOVEL 408,595,174,38
#define WOLFMOVER 595,408,174,38
//�ړ��Q�@//�ړ��P�̌�Ɉړ��Q��\������
#define WOLFMOVEL2 622,781,177,36
#define WOLFMOVER2 781,622,177,36
//�_���[�W
#define WOLFCRYL 237,383,190,46
#define WOLFCRYR 383,237,190,46
//�U���P
#define WOLFATL 1005,1198,182,33
#define WOLFATR 1198,1005,182,33
//�U���Q�@//�U���P�̌�ɍU���Q��\������
#define WOLFATL 1225,1398,181,33
#define WOLFATR 1398,1225,181,33
//���S
#define WOLFDTL 843,987,185,49
#define WOLFDTR 987,843,185,49

#define WOLFHP 100 

int CWolf::sWEhp = 0;

int CWolf::sNum = 0;

CWolf* CWolf::spInstance2 = nullptr;

CWolf* CWolf::Instance2()
{
	return spInstance2;
}

int CWolf::WEhp()
{
	return sWEhp;
}

void CWolf::Num(int num)
{
	sNum = num;
}

int CWolf ::Num()
{
	return sNum;
}

void CWolf::Collision()
{
	//CApplication::CharacterManager()->Collision(this);
}

void CWolf::Collision(CCharacter* m, CCharacter* o)
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

CWolf::CWolf(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::ECharacter)
{
	mTexture7.Load("�q�T.png");
	Set(x, y, w, h);
	Texture(pt, WOLFMOVEL); //�J�n���̗����G
	mState = EState::EMOVE;
	sWEhp = WOLFHP; //�I�I�J�~��HP
	//X��Y�����x�̏����l���ړ����x�ɂ���
	mWVx = WOLFX;
	mWVy = WOLFY;
	spInstance2 = this;
}

void CWolf::Update()
{
	//�v���C���[��ǔ�����
	if (X() < CPlayer::Instance()->X())
	{
		if (mWVx < 0)
			mWVx = -mWVx;
	}
	else
	{
		if (mWVx > 0)
			mWVx = -mWVx;
	}
	if (Y() < CPlayer::Instance()->Y())
	{
		if (mWVy < 0)
			mWVy = -mWVy;
	}
	else
	{
		if (mWVy > 0)
			mWVy = -mWVy;
	}
	switch (mState)
	{
	case EState::EDEATH: //���S��
		//HP���O�ɂȂ������b��ɏ��ł�����
		if (mWolfTime > 0)
		{
			mWolfTime--;
		}
		if (mWolfTime == 50)
		{
			if (mWVx < 0) { Texture(Texture(), WOLFDTL); }
			if (mWVx > 0) { Texture(Texture(), WOLFDTR); }
		}
		if (mWolfTime == 0)
		{
			mEnabled = false;
		}
		break;
	case EState::ESTOP: //��~���A�N�[���^�C����
	case EState::EAT: //�U����
	case EState::EDA: //�_���[�W��
	case EState::EMOVE:
	X(X() + mWVx);
	Y(Y() + mWVy);
	const int PITCH = 32;//�摜��؂�ւ���Ԋu
	if ((int)X() % PITCH < PITCH / 2)
	{
		if (mWVx < 0)
			{
				Texture(Texture(), WOLFMOVEL);
			}
			else
			{
				Texture(Texture(), WOLFMOVER2);
			}
		}
		else
		{
			if (mWVx > 0)
			{
				Texture(Texture(), WOLFMOVER);
			}
			else
			{
				Texture(Texture(), WOLFMOVEL2);
			}
		}
	}
}

CTexture* CWolf::Texture7()
{
	return &mTexture7;
}
CTexture CWolf::mTexture7;