#include "CApplication.h"
#include "CRectangle.h"

CTexture CApplication::mTexture;
CCharacterManager CApplication::mCharacterManager;

CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

CTexture* CApplication::Texture()
{
	return &mTexture;
}

void CApplication::Start()
{
	mTexture2.Load("�w�i(��) .png");
	mTexture3.Load("(��).png");
	mTexture4.Load("(��)2.png");
	mTexture5.Load("(��)3.png");
	mFont.Load("FontWhite.png", 1, 64);
	mState = EState::ESTART;
	mpGame = new CGame();
}
//ta

void CApplication::Update()
{
	switch (mState)
	{
	case EState::ESTART:	//��Ԃ��X�^�[�g
		mpGame->Start();	//�X�^�[�g��ʕ\��
		//Enter�L�[�������ꂽ��
		mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 0, 1919, 1079, 0, &mTexture3);
		mCharacterManager.Add(mpBackGround);
		if (mInput.Key(VK_RETURN))
		{	//��Ԃ��v���C���ɂ���
			mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 0, 1279, 719, 0, &mTexture2);
			mCharacterManager.Add(mpBackGround);
			mState = EState::EPLAY;
		}
		break;

	case EState::EPLAY:
		mpGame->Update();
		if (mInput.Key(VK_SPACE))
		{
			mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 2, 2665, 1564, 68, &mTexture4);
			mCharacterManager.Add(mpBackGround);
				mState = EState::EOVER;
		}
		if (mInput.Key(VK_BACK))
		{

			mpBackGround = new CBackGround(640.0f, 400.0f, 640.0f, 400.0f, 2, 2665, 1564, 68, &mTexture5);
			mCharacterManager.Add(mpBackGround);
			mState = EState::ECLEAR;
		}
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