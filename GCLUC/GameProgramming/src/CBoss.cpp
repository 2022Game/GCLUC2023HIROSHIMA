#include "CBoss.h"
#include "CApplication.h"

//�����G
#define BOSSNTL 2442,2984,500,0
#define BOSSNTR 2984,2442,500,0
//�U����
#define BOSSATL 43,583,500,21
#define BOSSATR 583,43,500,21
#define BOSSAT1L 626,1182,488,23
#define BOSSAT2R 1182,626,488,23
//�_���[�W
#define BOSSDAL 1842,2384,500,0
#define BOSSDAR 2384,1842,500,0
//���S
#define BOSSDTL 1206,1796,433,133
#define BOSSDTR 1796,1206,433,133

#define BOSSHP 100

int CBoss::sBEhp = 0;

int CBoss::sNum = 0;

CBoss* CBoss::spInstance4 = nullptr;

CBoss* CBoss::Instance4()
{
	return spInstance4;
}

int CBoss::BEhp()
{
	return sBEhp;
}

void CBoss::Num(int num)
{
	sNum = num;
}

int CBoss::Num()
{
	return sNum;
}

void CBoss::Collision()
{
	//CApplication::CharacterManager()->Collision(this);
}

void CBoss::Collision(CCharacter* m, CCharacter* o)
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

CBoss::CBoss(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::ECharacter)
{
	mTexture8.Load("�{�X.png");
	Set(x, y, w, h);
	Texture(pt, BOSSNTL);
	mState = EState::EMOVE;
	sBEhp = BOSSHP;
	//X��Y�����x�̏����l���ړ����x�ɂ���
	mBVx = BOSSX;
	mBVy = BOSSY;
	spInstance4 = this;
}

void CBoss::Update()
{
	//CCharacter::Update();
	switch (mState)
	{
	case EState::EDEATH: //���S��
		break;
	case EState::ESTOP: //��~���A�N�[���^�C����
		break;
	case EState::EATTACK: //�U����
		break;
	case EState::EDAMAGE: //�_���[�W��
		break;
	case EState::EBACK: //���
		break;
	case EState::EMOVE: //�ړ�
		CCharacter::Update();
		if (X() < CPlayer::Instance()->X())
		{
			if (mBVx < 0)
				mBVx = -mBVx;
			Texture(Texture(), BOSSNTR);
		}
		else
		{
			if (mBVx > 0)
				mBVx = -mBVx;
			Texture(Texture(), BOSSNTL);
		}
		if (Y() < CPlayer::Instance()->Y())
		{
			if (mBVy < 0)
			{
				mBVy = -mBVy;
			}
		}
		else
		{
			if (mBVy > 0)
			{
				mBVy = -mBVy;
			}
		}
		X(X() + mBVx);
		Y(Y() + mBVy);
	}
}

CTexture* CBoss::Texture8()
{
	return &mTexture8;
}
CTexture CBoss::mTexture8;