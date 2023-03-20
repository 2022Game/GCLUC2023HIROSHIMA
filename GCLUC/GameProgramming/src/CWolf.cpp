#include "CWolf.h"
#include "CApplication.h"

//��
#define MU 0,0,0,0
//�����G
#define WOLFNTL 2,200,196,12
#define WOLFNTR 200,2,196,12
//�ړ��P
#define WOLFMOVEL 1003,1188,184,18
#define WOLFMOVER 1188,1003,184,18
//�ړ��Q�@//�ړ��P�̌�Ɉړ��Q��\������
#define WOLFMOVEL2 1210,1393,188,28
#define WOLFMOVER2 1393,1210,188,28
//�_���[�W
#define WOLFDAL 205,397,192,35
#define WOLFDAR 397,205,192,35
//�U���O
#define WOLFATL 801,996,196,23
#define WOLFATR 996,801,196,23
//�U���P
#define WOLFATL2 408,599,198,15
#define WOLFATR2 598,408,198,15
//�U���Q�@//�U���P�̌�ɍU���Q��\������
#define WOLFATL3 608,797,198,15
#define WOLFATR3 797,608,198,15
//���S
#define WOLFDTL 1421,1593,194,27
#define WOLFDTR 1593,1421,194,27

#define WOLFHP 300 

//int CWolf::sWEhp = 0;

int CWolf::sNum = 0;

CWolf* CWolf::spInstance3 = nullptr;

CWolf* CWolf::Instance3()
{
	return spInstance3;
}

int CWolf::WEhp()
{
	return sWEhp;
}

void CWolf::Num(int num)
{
	sNum = num;
}

int CWolf::Num()
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
	float x, y;
	switch (o->Tag())
	{
	case ETag::EPLAYER:
		if (mState != EState::EDEATH)
		{
			if (CRectangle::Collision(o, &x, &y))
			{
				if (mWolfInvincible <= 0)
				{
					mWolfInvincible = 60;
					if (mState != EState::EDAMAGE)
					{
						if (mWVx < 0) { Texture(Texture(), MU); }
						if (mWVx > 0) { Texture(Texture(), MU); }
						mWolfTime = 60;
						sWEhp = sWEhp - 100;
						if (sWEhp <= 0)
						{
							mWolfTime3 = 20;
							mState = EState::EDEATH;
						}
						if (mState != EState::EATTACK)
						{
							mState = EState::EDAMAGE;
						}
					}
				}
			}
			//break;
			//case ETag::EMAGIC: //���̖��@
			// if (mState != EState::EDEATH)
			//{
			//	//	if (CRectangle::Collision(o, &x, &y))
			//	//	{
			//	//		if (mWolfInvincible <= 0)
			//	//		{
			//	//			mWolfInvincible = 60;
			//	//			if (mState != EState::EDAMAGE)
			//	//			{
			//	//     if (mWVx < 0) { Texture(Texture(), MU); }
			//	//	   if (mWVx > 0) { Texture(Texture(), MU); }
			//	//              mWolfTime = 60;
			//	//				sWEhp = sWEhp - 100;
			//	// if (sWEhp <= 0)
			//	/*{
			//		mWolfTime3 = 20;
			//		mState = EState::EDEATH;
			//	}*/
			//	//				if (mState != EState::EATTACK)
			//	//				{
			//	//					mState = EState::EDAMAGE;
			//	//				}
			//	//			}
			//	//		}
			//	//	}
			//}
			break;
			//case ETag::EDAGEKI: //���̑Ō�
			// // if (mState != EState::EDEATH)
			//{
		//	if (CRectangle::Collision(o, &x, &y))
		//	{
		//		if (mWolfInvincible <= 0)
		//		{
		//			mWolfInvincible = 60;
		//			if (mState != EState::EDAMAGE)
		//			{
		// //	//     if (mWVx < 0) { Texture(Texture(), MU); }
			//	//	   if (mWVx > 0) { Texture(Texture(), MU); }
		//				mWolfTime = 60;
		//				sWEhp = sWEhp - 25;
		//  if (sWEhp <= 0)
			//	/*{
			//		mWolfTime3 = 20;
			//		mState = EState::EDEATH;
			//	}*/
		//				if (mState != EState::EATTACK)
		//				{
		//					mState = EState::EDAMAGE;
		//				}
		//			}
		//		}
		//	}
		//}
		}
	}
}

CWolf::CWolf(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::ECharacter)
{
	mTexture7.Load("�q�T.png");
	Set(x, y, w, h);
	Texture(pt, WOLFMOVEL); //�J�n���̗����G
	mState = EState::EMOVE;
	mTag = ETag::EENEMY;
	sWEhp = WOLFHP; //�I�I�J�~��HP
	//X��Y�����x�̏����l���ړ����x�ɂ���
	mWVx = WOLFX;
	mWVy = WOLFY;
	spInstance3 = this;
	sNum++;
}

void CWolf::Update()
{
	if (mWolfEattack > 0)
	{
		mWolfEattack--;
		if (mWolfEattack <= 0)
		{
			delete mpWolfAttackBox;
		}
	}
	CCharacter::Update();
	if (mWolfInvincible >= 0)
	{
		mWolfInvincible--;
	}
	//�e�X�g�p���̓L�[
	if (mInput.Key('1'))
	{
		mWolfTime2 = 61;
		mState = EState::EATTACK;
	}
	if (mInput.Key('2'))
	{
		mWolfTime = 11;
		mState = EState::EDAMAGE;
	}
	if (mInput.Key('3'))
	{
		mWolfTime3 = 21;
		mState = EState::EDEATH;
	}

	if (mWolfInvincible != 10 && mInput.Key('9'))
	{
		mWolfInvincible = 10;
		if (mState != EState::EDAMAGE)
		{
			mWolfTime = 31;
			sWEhp = sWEhp - 100;
			mState = EState::EDAMAGE;
		}
	}
	switch (mState)
	{
	case EState::EMUTEKI:
		break;
	case EState::EDEATH: //���S��
		//HP���O�ɂȂ������b��ɏ��ł�����
		//�e�X�g�p
		if (mWolfTime3 >= 0)
		{
			mWolfTime3--;
		}
		if (mWolfTime3 == 19)
		{
			if (mWVx < 0) { Texture(Texture(), WOLFDAL); }
			if (mWVx > 0) { Texture(Texture(), WOLFDAR); }
		}
		if (mWolfTime3 == 9)
		{
			if (mWVx < 0) { Texture(Texture(), WOLFDTL); }
			if (mWVx > 0) { Texture(Texture(), WOLFDTR); }
		}
		if (mWolfTime3 == 0)
		{
			sNum--;
		}
		break;
	case EState::ESTOP: //��~���A�N�[���^�C����
		break;
	case EState::EATTACK: //�U����
		if (mWolfTime2 >= 0)
		{
			mWolfTime2--;
		}
		if (mWolfTime2 == 29)
		{
			if (mWVx < 0) { Texture(Texture(), WOLFATL); }
			if (mWVx > 0) { Texture(Texture(), WOLFATR); }
		}
		if (mWolfTime2 == 22)
		{
			if (mWVx < 0) { Texture(Texture(), WOLFATL); }
			if (mWVx > 0) { Texture(Texture(), WOLFATR); }
		}
		if (mWolfTime2 == 14)
		{
			if (mWVx < 0) { Texture(Texture(), WOLFATL2); }
			if (mWVx > 0) { Texture(Texture(), WOLFATR2); }
		}
		if (mWolfTime2 == 4)
		{
			if (mWVx < 0)
			{
				Texture(Texture(), WOLFATL3);
				mpWolfAttackBox = new CWolfAttackBox(X() - 125, Y(), 80.0f, 80.0f, CWolf::Texture7());
				mWolfEattack = 4;
			}
			if (mWVx > 0)
			{
				Texture(Texture(), WOLFATR3);
				mpWolfAttackBox = new CWolfAttackBox(X() + 125, Y(), 80.0f, 80.0f, CWolf::Texture7());
				mWolfEattack = 4;
			}
		}
		if (mWolfTime2 == 0)
		{
			//delete mpEattack;
			mState = EState::EMOVE;
		}
		break;
	case EState::EDAMAGE: //�_���[�W��
		if (sWEhp == 0)
		{
			mWolfTime3 = 20;
			mState = EState::EDEATH;
		}
		if (mWolfTime > 0)
		{
			mWolfTime--;
		}
		if (mWolfTime == 29)
		{
			/*if (mWVx < 0) { Texture(Texture(), MU); }
			if (mWVx > 0) { Texture(Texture(), MU); }*/
		}
		if (mWolfTime == 59)
		{
			if (mWVx < 0) { Texture(Texture(), WOLFDAL); }
			if (mWVx > 0) { Texture(Texture(), WOLFDAR); }
		}
		if (mWolfTime == 0)
		{
			mState = EState::EMOVE;
		}
		break;
	case EState::EMOVE:
		if (X() < CPlayer::Instance()->X())
		{
			mWLR = 1;
		}
		else
		{
			mWLR = 2;
		}

		//�v���C���[��ǔ�����
		if (mWLR == 1)
		{
			if (X() < CPlayer::Instance()->X() - 125)
			{
				X(X() + mWVx);
				if (X() < CPlayer::Instance()->X())
				{
					if (mWVx < 0)
						mWVx = -mWVx;
				}
			}
		}
		if (mWLR == 2)
		{
			if (X() > CPlayer::Instance()->X() + 125)
			{
				X(X() + mWVx);
				if (X() > CPlayer::Instance()->X())
				{
					if (mWVx > 0)
						mWVx = -mWVx;
				}
			}
		}
		if (X() > CPlayer::Instance()->X() - 125 && X() < CPlayer::Instance()->X() + 125)
		{
			if (Y() > CPlayer::Instance()->Y() - 125 && Y() < CPlayer::Instance()->Y() + 125)
			{
				if (mWolfTime2 <= 0)
				{
					mWolfTime2 = 30;
					mState = EState::EATTACK;
				}
			}
		}
		if (Instance3()->Y() != CPlayer::Instance()->Y())
		{
			Y(Y() + mWVy);
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
		}
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