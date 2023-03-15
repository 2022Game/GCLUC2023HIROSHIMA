#include "CPlayer.h"
#include "CApplication.h"

//�A�C�h�����O�e�N�X�`��(�E����)
#define DEFAULT  0, 200, 400, 200

#define JUMPV0 30               	//�W�����v�̏���
#define GRAVITY 2.0f	            //�d�͉����x

#define PLAYERHP 10                 //�v���C���[��HP
#define STAMINA 100                 //�v���C���[�̃X�^�~�i

CPlayer* CPlayer::spinstance = nullptr;
int CPlayer::sHp = 0;
int CPlayer::sStamina = 0;

//�R���X�g���N�^
CPlayer::CPlayer(float x, float y, float w, float h, CTexture* pt)
	: CCharacter((int)ETaskPriority::ECharacter)
	, mInvincible(0)
	, mIdlingcount(0)
	, mJumpcount(0)
	, mMovecount(0)
	, mAttackcount(0)
	, mJumpY(0.0f)
{
	Set(x, y, w, h * 1.5);
	Texture(pt, DEFAULT);
	spinstance = this;
	mState = EState::EIDLING;
	sHp = PLAYERHP;
	sStamina = STAMINA;
}

//�f�X�g���N�^
CPlayer::~CPlayer()
{
}

//�C���X�^���X�쐬
CPlayer* CPlayer::Instance()
{
	return spinstance;
}

//HP���擾
int CPlayer::HP()
{
	return sHp;
}

//�X�^�~�i���擾
int CPlayer::Stamina()
{
	return sStamina;
}

//�X�V����
void CPlayer::Update()
{
	float left;
	float right;
	switch (State())
	{
	case EState::EMOVE:
		//X�������ړ�
		if (mInput.Key('A'))
		{
			mVx = -VELOCITY - 1;
			X(X() + mVx);
			mIdlingcount = 0;
		}
		if (mInput.Key('D'))
		{
			mVx = VELOCITY + 1;
			X(X() + mVx);
			mIdlingcount = 0;
		}
		//Y�������ړ�
		if (mInput.Key('W'))
		{
			mVy = VELOCITY + 1;
			Y(Y() + mVy);
			mIdlingcount = 0;
		}
		if (mInput.Key('S'))
		{
			mVy = VELOCITY - 1;
			Y(Y() - mVy);
			mIdlingcount = 0;
		}

		mMovecount %= 48;
		left = (mMovecount / 8) * 200;
		right = left + 200;
		mMovecount++;
		if (mVx >= 0)
		{
			Texture(Texture(), left, right, 200, 0);
		}
		if (mVx < 0)
		{
			Texture(Texture(), right, left, 200, 0);
		}
		//�U��
		if (mInput.Key('K'))
		{
			mAttackcount = 0;
			mState = EState::EATTACK;
		}
		//�L�[���͂�����Ă��Ȃ����J�E���g��0�ȏ�̎�
		if (mInput.Key('W') != true ||
			mInput.Key('A') != true ||
			mInput.Key('S') != true ||
			mInput.Key('D') != true ||
			mInput.Key('J') != true ||
			mInput.Key('K') != true)
		{
			mIdlingcount--;
			if (mIdlingcount <= -10)
			{
				mState = EState::EIDLING;
			}
		}
		if (mState != EState::EJUMP)
		{
			if (mInput.Key('J'))
			{
				mJumpY = Y();
				mVy = JUMPV0;
				mInvincible = 20;
				mState = EState::EJUMP;
			}
		}
		break;

	case EState::EJUMP:
		mInvincible--;
		//Y�����x�ɏd�͂����Z����
		mVy -= GRAVITY;
		Y(Y() + mVy);

		mJumpcount %= 30;
		left = (mJumpcount / 10) * 200;
		right = left + 200;
		mJumpcount++;
		if (mVx >= 0)
		{
			Texture(Texture(), left, right, 800, 600);
		}
		else
		{
			Texture(Texture(), right, left, 800, 600);
		}

		if (mJumpY >= Y())
		{
			//���G�J�E���^��0�ɂȂ������Ԃ�IDLING�ɂ���
			if (mInvincible <= 0)
			{
				mState = EState::EIDLING;
			}
			else if (mJumpcount < 29)
			{
				mState = EState::EIDLING;
			}
		}
		//X�������ړ�
		if (mInput.Key('A'))
		{
			mVx = -VELOCITY;
			X(X() + mVx);
		}
		if (mInput.Key('D'))
		{
			mVx = VELOCITY;
			X(X() + mVx);
		}
		break;

	case EState::EIDLING:
		if (mInput.Key('W') || mInput.Key('A') ||
			mInput.Key('S') || mInput.Key('D') ||
			mInput.Key('J') || mInput.Key('K'))
		{
			mState = EState::EMOVE;
			mIdlingcount = 0;
		}
		mIdlingcount %= 72;
		left = (mIdlingcount / 18) * 200;
		right = left + 200;
		if (mVx >= 0)
		{
			Texture(Texture(), left, right, 400, 200);
		}
		else
		{
			Texture(Texture(), right, left, 400, 200);
		}
		mIdlingcount++;
		break;

	case EState::EATTACK:
		mAttackcount++;
		mAttackcount %= 24;
		left = (mAttackcount / 12) * 200;
		right = left + 200;
		if (mVx >= 0)
		{
			Texture(Texture(), left, right, 600, 400);
		}
		else
		{
			Texture(Texture(), right, left, 600, 400);
		}
		if (mAttackcount >= 23)
		{
			mState = EState::EIDLING;
		}
		break;

	case EState::EDAMAGE:
		break;

	case EState::EDEATH:
		break;

	}
	//�f�o�b�O�p
	if (mInput.Key('L'))
	{
		mVx = -VELOCITY - 1;
		X(X() + mVx);
	}
	CCharacter::Update();
}