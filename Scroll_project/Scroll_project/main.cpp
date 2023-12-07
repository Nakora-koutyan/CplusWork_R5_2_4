#include<stdio.h>
#include<Dxlib.h>

//�}�N����`(��ʃT�C�Y)
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

//���[���h���W�̉�ʃT�C�Y
#define WORLD_LOCATION_X 0
#define WORLD_LOCATION_Y 0

//�J�������W�̌��_
#define CAMERA_LOCATION_X 320
#define CAMERA_LOCATION_Y 180

#define WORLD_WIDTH 3000
#define WORLD_HEIGHT 2000

#define PLAYER_POS_X 300
#define PLAYER_POS_Y 600

//�񋓌^�̐錾
enum mode
{
	INIT,
	MAIN
};

//�ϐ��錾(�O���[�o���ϐ�)
char now[256];
char old[256];

int stage_img;		//�X�e�[�W�摜(�w�i)

float pos_x, pos_y;	//�v���C���[�̍��W
int move_x, move_y;	//�v���C���[�̈ړ���

float camera_x;		//�J�������W��X���W
float camera_y;		//�J�������W��Y���W

float world_screen_x;		//���[���h���W��X���W
float world_screen_y;		//���[���h���W��Y��

mode GameMode = INIT;	//�Q�[�����[�h

//�֐��̃v���g�^�C�v�錾
int LoadImages(void);			//�摜�Ǎ�����
void GameMain(void);			//�Q�[�����C���V�[������
void GameInit(void);			//�Q�[���̏���������
void PlayerControll(void);		//�v���C���[����
void ObjectControll(void);		//�I�u�W�F�N�g����
void ScreenScroll(void);		//��ʃX�N���[������


struct Vec2
{
	double x;
	double y;

	Vec2(double _x, double _y)
		:x(_x)
		,y(_y){}
};

//�J����
static Vec2 g_CameraPos{ (WORLD_WIDTH / 2.0f),(WORLD_HEIGHT / 2.0f) };

//�v���O�����̊J�n
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// �^�C�g����ݒ�
	SetMainWindowText("pick up apples");

	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y�ݒ�	
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);

	// DX���C�u�����̏���������
	if (DxLib_Init() == -1)return -1;

	// �`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�Ǎ��֐��̌Ăяo��
	if (LoadImages() == -1)
	{
		return -1;
	}

	// �Q�[�����[�v
	while (ProcessMessage() == 0) 
	{
		//���̓L�[�擾
		memcpy(old, now, (sizeof(char) * 256));
		GetHitKeyStateAll(now);

		// ��ʂ̏�����
		ClearDrawScreen();

		switch (GameMode)
		{
			case INIT:
				GameInit();
				break;
			case MAIN:
				GameMain();
				break;
		}

		//����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();
	}
	// �v���O�����̏I��
	return 0;
}
//�摜�Ǎ�
int LoadImages(void)
{
	//�X�N���[���摜���ϐ����
	stage_img = LoadGraph("images/SampleStage2.jpg");
	//�摜�ϐ���-1�Ȃ�G���[��Ԃ�
	if (stage_img == -1)
	{
		return -1;
	}

	//����l��Ԃ�
	return 0;
}
//�Q�[��������
void GameInit(void)
{
	//�v���C���[�������W
	pos_x = PLAYER_POS_X;
	pos_y = PLAYER_POS_Y;

	//�v���C���[�ړ���
	move_x = 0;

	//�v���C���[�㏸��
	move_y = 0;

	//�J�������W�̏������W�ݒ�
	camera_x = CAMERA_LOCATION_X;
	camera_y = CAMERA_LOCATION_Y;

	//�Q�[�����C��������
	GameMode = MAIN;
}
//�Q�[�����C������
void GameMain(void)
{
	//��ʃX�N���[������
	ScreenScroll();

	//�v���C���[����
	PlayerControll();

	//�I�u�W�F�N�g����
	ObjectControll();

	//�J�����̍X�V����
	void UpdateCamera(Vec2 pos);
}
//�v���C���[����
void PlayerControll()
{
	//�v���C���[�̕`��
	DrawCircleAA(pos_x, pos_y, 10, 10, 0xff0000, TRUE, 1.0);

}
//�I�u�W�F�N�g����
void ObjectControll()
{
	if (now[KEY_INPUT_LEFT])	//X���Z
	{
		move_x -= 6;
	}
	if (now[KEY_INPUT_RIGHT])	//X���Z
	{
		move_x += 6;
	}
	if (now[KEY_INPUT_UP])		//Y���Z
	{
		move_y -= 6;
	}
	if (now[KEY_INPUT_DOWN])	//Y���Z
	{
		move_y += 6;
	}
	pos_x += move_x;
}
//��ʃX�N���[������
void ScreenScroll()
{
	//�ŏ��̃��C����ʕ\��
	DrawGraph(0, 0, stage_img, FALSE);

	//���C����ʂ̃X�N���[������
	if (g_CameraPos.x - (SCREEN_WIDTH / 2) <= 0.0f)
	{
		g_CameraPos.x = (SCREEN_WIDTH / 2);
	}
	else if (g_CameraPos.x + (SCREEN_WIDTH / 2) >= WORLD_WIDTH)
	{
		g_CameraPos.x = WORLD_WIDTH - SCREEN_WIDTH;
	}
}
void UpdateCamera(Vec2 pos)
{
	g_CameraPos = pos;

	//�J�������W����X�N���[�����W�̌��_�ɕϊ�����
	Vec2 screen_origin_position =
	{
		g_CameraPos.x - (SCREEN_WIDTH / 2.0f),
		g_CameraPos.y - (SCREEN_HEIGHT / 2.0f)
	};
	
	//���[���h���W����X�N���[�����W�ɕϊ�����
	Vec2 screen_position = Vec2(pos.x - screen_origin_position.x, world_screen_y - screen_origin_position.y);
}