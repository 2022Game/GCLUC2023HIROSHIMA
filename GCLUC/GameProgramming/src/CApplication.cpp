#include "CApplication.h"
#include "CRectangle.h"

CTexture CApplication::mTexture;

CApplication::CApplication()
	:mRb(0)
{
}

CTexture* CApplication::Texture()
{
	return &mTexture;
}

void CApplication::Start()
{
	mTexture.Load("PlayerImage.png");
	mTexture2.Load("�w�i(��) .png");
	mTexture3.Load("(��).png");
	mTexture4.Load("(��)2.png");
	mTexture5.Load("(��)3.png");
	mTexture6.Load("�w�i.png");
	mTexture7.Load("�w�i2.png");
	mTexture8.Load("�w�i3.png");
	mTexture100.Load("�v���C���[HP.png");
	mTexture101.Load("MP�Q�[�W.png");
	mTexture102.Load("�v���C���[MP.png");
	mFont.Load("FontWhite.png", 1, 64);
	mState = EState::ESTART;
	mpGame = new CGame();
}

void CApplication::Update()
{
	mRb--;
	switch (mState)
	{
	case EState::ESTART:	//��Ԃ��X�^�[�g
		mpGame->Start();	//�X�^�[�g��ʕ\��
		//mCharacterManager.Add(mpBackGround);
		if (mRb < 0)
		{
			if (mInput.Key(VK_RETURN))
			{	//��Ԃ��v���C���ɂ���
				mState = EState::ESTAGE1;
			}
		}
		break;
	case EState::ESTAGE1:
		mpGame->Stage1();
		mState = EState::EPLAY;
	break;
	case EState::EPLAY:
		mpGame->Update();
		if (CGame::Num() == 0)
		{
			mpGame->Clear();
			mState = EState::ECLEAR;
		}
		if (CPlayer::HP() == 0)
		{
			mpGame->Over();
			mState = EState::EOVER;
		}
		/*if (mInput.Key(VK_SPACE))
		{
			mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 2, 2665, 1564, 68, &mTexture4);
				mState = EState::EOVER;
		}
		if (mInput.Key(VK_BACK))
		{
			mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 2, 2665, 1564, 68, &mTexture5);
			mState = EState::ECLEAR;
		}*/
		////�Q�[���I�[�o�[������
		//if (mpGame->IsOver())
		//{	//��Ԃ��Q�[���I�[�o�[�ɂ���
		//	mState = EState::EOVER;
		//	//�Q�[���I�[�o�[
		//	mSoundOver.Play();
		//}
		//�Q�[���N���A������
		//if (mpGame->IsClear())
		//{	//��Ԃ��Q�[���N���A�ɂ���
		//	mState = EState::ECLEAR;
		//}
		break;

	case EState::EOVER:
		//�Q�[���I�[�o�[����
		mpGame->Over();
		//�G���^�[�L�[���͎�
		if (mInput.Key(VK_RETURN))
		{	//�Q�[���̃C���X�^���X�폜
			delete mpGame;
			//�Q�[���̃C���X�^���X����
			mpGame = new CGame();
			//��Ԃ��X�^�[�g�ɂ���
			mState = EState::ESTART;
			mRb = 10;
		}
		break;

	case EState::ECLEAR:
		//�Q�[���N���A����
		mpGame->Clear();
		if (mInput.Key(VK_RETURN))
		{
			delete mpGame;
			mpGame = new CGame();
			mState = EState::ESTART;
			mRb = 10;
		}
		break;
	}
}
CTexture CApplication::mTexture2;
CTexture* CApplication::Texture2()
{
	return &mTexture2;
}
CTexture CApplication::mTexture3;
CTexture* CApplication::Texture3()
{
	return &mTexture3;
}
CTexture CApplication::mTexture4;
CTexture* CApplication::Texture4()
{
	return &mTexture4;
}
CTexture CApplication::mTexture5;
CTexture* CApplication::Texture5()
{
	return &mTexture5;
}
CTexture CApplication::mTexture6;
CTexture* CApplication::Texture6()
{
	return &mTexture6;
}
CTexture CApplication::mTexture7;
CTexture* CApplication::Texture7()
{
	return &mTexture7;
}
CTexture CApplication::mTexture8;
CTexture* CApplication::Texture8()
{
	return &mTexture8;
}
CTexture CApplication::mTexture100;
CTexture* CApplication::Texture100()
{
	return &mTexture100;
}
CTexture CApplication::mTexture101;
CTexture* CApplication::Texture101()
{
	return &mTexture101;
}
CTexture CApplication::mTexture102;
CTexture* CApplication::Texture102()
{
	return &mTexture102;
}