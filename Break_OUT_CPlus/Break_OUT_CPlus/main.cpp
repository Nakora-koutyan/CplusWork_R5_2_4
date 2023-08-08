#include"DxLib.h"
#include "SceneManager.h"
#include"AbstractScene.h"
#include"Title.h"
#include"MouseControll.h"
#include"common.h"


int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);		//�t���X�N���[�����[�h�ŋN��

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//�E�B���h�E�T�C�Y��ݒ�

	if (DxLib_Init() == -1)
	{
		return -1;				//DX���C�u�����̏���������
	}

	//����ʂɕ`�悷��
	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[���J�n���̃}�E�X�̈ʒu���Œ肷��
	SetMousePoint(300, 300);

	//�}�E�X��\����Ԃɂ���
	SetMouseDispFlag(TRUE);

	//�Q�[�����[�v
	SceneManager SceneMng(dynamic_cast<AbstractScene*>(new TitleScene()));
	while(SceneMng.Update()!=nullptr && ProcessMessage() == 0)
	{

		ClearDrawScreen();
		MouseControll::Update();
		SceneMng.Draw();
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();
	}

	DxLib_End();		//Dx���C�u�����g�p�̏I������
	return 0;			//�v���O�����̏I��
}