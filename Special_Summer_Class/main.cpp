#include "DxLib.h"
#include <math.h>

/*�@�}�N����`�@*/
#define SCREEN_WIDTH	(1280)
#define SCREEN_HEIGHT	(720)

/* �񋓌^�̐錾 */
enum mode
{
	INIT,
	MAIN
};

/* �֐��̃v���g�^�C�v�錾 */
void Init(void);		//����������
void Main(void);		//�Q�[�����C��
void Player(void);		//�v���C���[����

/* �ϐ��錾 */
int gOldKey;				//�O��̓��̓L�[
int gNowKey;				//����̓��̓L�[
int gKeyFlg;				//���̓L�[���

float player_x;				//�v���C���[���W(����)
float player_y;				//�v���C���[���W(�c��)
float move_x;				//�v���C���[�̈ړ���(����)
float move_y;				//�v���C���[�̈ړ���(�c��)
//float player_angle;		//�v���C���[�̊p�x
float gravity_accele;		//�d�͉����x
float V0;					//�����x
float timer;				//�^�C�}�[
float sita;					//�Ɨp�ϐ�
float t;					//�^�C�}�[�p�ϐ�
float pi;					//�~����

float rad;					//���W�A���l

mode gGameMode = INIT;		//�Q�[�����[�h

int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	//�^�C�g����ݒ�
	SetMainWindowText("Summer_Special_Class");

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

	while (ProcessMessage() == 0 && gGameMode!=99)
	{
		//���̓L�[�擾
		gOldKey = gNowKey;
		gNowKey = CheckHitKey(KEY_INPUT_A);
		gKeyFlg = gNowKey & ~gOldKey;

		ClearDrawScreen();
		switch (gGameMode)
		{
			case INIT:
				Init();
				break;
			case MAIN:
				Main();
				break;
		}

		//����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();
	}

	DxLib_End();		//Dx���C�u�����g�p�̏I������
	return 0;			//�v���O�����̏I��
}
void Init(void)
{
	/*�@�v���C���[�����ݒ�@*/
	player_x = 300.f;
	player_y = 690.f;
	move_x = 0;
	move_y = 0;
	gravity_accele = 980.f;
	//player_angle = 45.f;
	V0 = 700.0f;
	timer = 0.004175f;
	sita = 60;
	pi = 3.1415f;
	rad = sita * (pi / 180);

	//�Q�[�����C��������
	gGameMode = MAIN;
}
void Main(void)
{
	//�v���C���[����ƃQ�[����ԕ\��
	Player();
}
void Player(void)
{
	//if (gKeyFlg)
	{
		t = timer;
		/* �ړ��ʂ̌v�Z */
		move_x = (V0 * ((float)cos(rad) * t));
		move_y = (-V0 * ((float)sin(rad) * t) + (gravity_accele * t * t) / 2);

		/* �v���C���[�̈ړ����� */
		player_x = player_x + move_x;
		player_y = player_y + move_y;

		/* �v���C���[�̈ړ����� */
		if (player_x > 1280)
		{
			player_x = 1280;
		}

		t += timer;
	}

	DrawCircleAA(player_x, player_y, 6, 10, 0xffffff, TRUE);
}