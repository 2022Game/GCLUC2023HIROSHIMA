#include "CPlayer.h"
#include "CApplication.h"

//�ړ��e�N�X�`��(�E����)
#define MOVETEXTURE   12,  201,199, 2
#define MOVETEXTURE2 202, 399, 186, 7
#define MOVETEXTURE3 401, 599, 193,10
#define MOVETEXTURE4 600, 796, 193, 8
#define MOVETEXTURE5 798, 997, 189,17
//�ړ��e�N�X�`��(������)
#define MOVETEXTURE6  201,  12, 199, 2
#define MOVETEXTURE7  399, 202, 186, 7
#define MOVETEXTURE8  599, 401, 193,10
#define MOVETEXTURE9  796, 600, 193, 8
#define MOVETEXTURE10 997, 798, 189,17
//�A�C�h�����O�e�N�X�`��(�E����)
#define IDLINGTEXTURE  200, 330, 402, 218
#define IDLINGTEXTURE2 437, 561, 402, 218
#define IDLINGTEXTURE3 635, 763, 402, 218
//�A�C�h�����O�e�N�X�`��(������)
#define IDLINGTEXTURE4 332, 201, 405, 213
#define IDLINGTEXTURE5 561, 437, 402, 218
#define IDLINGTEXTURE6 763, 635, 402, 218
//�W�����v�e�N�X�`��(�E����)
#define JUMPTEXTURE   26, 185, 798, 607
#define JUMPTEXTURE2 218, 382, 800, 603
//�W�����v�e�N�X�`��(������)
#define JUMPTEXTURE3 185,  26, 798, 607
#define JUMPTEXTURE4 382, 218, 800, 603
//�U���e�N�X�`��(�E����)
#define ATTACKTEXTURE  832, 961, 402, 218
#define ATTACKTECTURE2  30, 181, 606, 418 
//�U���e�N�X�`��(������)
#define ATTACKTEXTURE  916, 832, 402, 218
#define ATTACKTECTURE2  181, 30, 606, 418 
//�_���[�W�e�N�X�`��
#define DAMAGETEXTURE 217, 381, 602, 421
//���S�e�N�X�`��
#define DEATHTEXTURE  635, 775, 599, 421
#define DEATHTEXTURE2 798, 995, 593, 492


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
	,mIdlingcount(0)
	, mJumpY(0.0f)
{
	Set(x, y, w, h*1.5);
	Texture(pt, IDLINGTEXTURE);
	spinstance = this;
	mState = EState::EMOVE;
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
		//�U��
		if (mInput.Key('K'))
		{
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
			if (mIdlingcount <= 0)
			{
				mIdlingcount = 20;
			}
			mIdlingcount--;
			if (mIdlingcount <= 10)
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
				mInvincible = 25;
				mState = EState::EJUMP;
			}
		}
		break;

	case EState::EJUMP:
		mInvincible--;
		//Y�����x�ɏd�͂����Z����
		mVy -= GRAVITY;
		Y(Y() + mVy);
		if (mJumpY >= Y())
		{
			//���G�J�E���^��0�ɂȂ������Ԃ�MOVE�ɂ���
			if (mInvincible <= 0)
			{
				mState = EState::EMOVE;
			}
		}
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
		}
		if (mIdlingcount <= 0)
		{
			mIdlingcount = 72;
		}
		else
		{
			mIdlingcount--; 
		}
		if (mIdlingcount == 72)
		{
			if (mVx >= 0) { Texture(Texture(), IDLINGTEXTURE); }
			if (mVx < 0) { Texture(Texture(), IDLINGTEXTURE4); }
		}
		if (mIdlingcount == 54)
		{
			if (mVx >= 0) { Texture(Texture(), IDLINGTEXTURE2); }
			if (mVx < 0) { Texture(Texture(), IDLINGTEXTURE5); }
		}
		if (mIdlingcount == 36)
		{
			if (mVx >= 0) { Texture(Texture(), IDLINGTEXTURE3); }
			if (mVx < 0) { Texture(Texture(), IDLINGTEXTURE6); }
		}
		if (mIdlingcount == 18)
		{
			if (mVx >= 0) { Texture(Texture(), IDLINGTEXTURE2); }
			if (mVx < 0) { Texture(Texture(), IDLINGTEXTURE5); }
		}
		break;
	case EState::EATTACK:
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

