#include "DxLib.h"
#include <math.h>

/*　マクロ定義　*/
#define SCREEN_WIDTH	(1280)
#define SCREEN_HEIGHT	(720)

/* 列挙型の宣言 */
enum mode
{
	INIT,
	MAIN
};

/* 関数のプロトタイプ宣言 */
void Init(void);		//初期化処理
void Main(void);		//ゲームメイン
void Player(void);		//プレイヤー処理

/* 変数宣言 */
int gOldKey;				//前回の入力キー
int gNowKey;				//今回の入力キー
int gKeyFlg;				//入力キー情報

float player_x;				//プレイヤー座標(横軸)
float player_y;				//プレイヤー座標(縦軸)
float move_x;				//プレイヤーの移動量(横軸)
float move_y;				//プレイヤーの移動量(縦軸)
//float player_angle;		//プレイヤーの角度
float gravity_accele;		//重力加速度
float V0;					//初速度
float timer;				//タイマー
float sita;					//θ用変数
float t;					//タイマー用変数
float pi;					//円周率

float rad;					//ラジアン値

mode gGameMode = INIT;		//ゲームモード

int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	//タイトルを設定
	SetMainWindowText("Summer_Special_Class");

	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);		//フルスクリーンモードで起動

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//ウィンドウサイズを設定

	if (DxLib_Init() == -1)
	{
		return -1;				//DXライブラリの初期化処理
	}

	//裏画面に描画する
	SetDrawScreen(DX_SCREEN_BACK);

	//ゲーム開始時のマウスの位置を固定する
	SetMousePoint(300, 300);

	//マウスを表示状態にする
	SetMouseDispFlag(TRUE);

	while (ProcessMessage() == 0 && gGameMode!=99)
	{
		//入力キー取得
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

		//裏画面の内容を表画面に反映する
		ScreenFlip();
	}

	DxLib_End();		//Dxライブラリ使用の終了処理
	return 0;			//プログラムの終了
}
void Init(void)
{
	/*　プレイヤー初期設定　*/
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

	//ゲームメイン処理へ
	gGameMode = MAIN;
}
void Main(void)
{
	//プレイヤー制御とゲーム状態表示
	Player();
}
void Player(void)
{
	//if (gKeyFlg)
	{
		t = timer;
		/* 移動量の計算 */
		move_x = (V0 * ((float)cos(rad) * t));
		move_y = (-V0 * ((float)sin(rad) * t) + (gravity_accele * t * t) / 2);

		/* プレイヤーの移動処理 */
		player_x = player_x + move_x;
		player_y = player_y + move_y;

		/* プレイヤーの移動制限 */
		if (player_x > 1280)
		{
			player_x = 1280;
		}

		t += timer;
	}

	DrawCircleAA(player_x, player_y, 6, 10, 0xffffff, TRUE);
}