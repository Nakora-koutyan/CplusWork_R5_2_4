#include<stdio.h>
#include<Dxlib.h>

//マクロ定義(画面サイズ)
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

//ワールド座標の画面サイズ
#define WORLD_LOCATION_X 0
#define WORLD_LOCATION_Y 0

//カメラ座標の原点
#define CAMERA_LOCATION_X 320
#define CAMERA_LOCATION_Y 180

#define WORLD_WIDTH 3000
#define WORLD_HEIGHT 2000

#define PLAYER_POS_X 300
#define PLAYER_POS_Y 600

//列挙型の宣言
enum mode
{
	INIT,
	MAIN
};

//変数宣言(グローバル変数)
char now[256];
char old[256];

int stage_img;		//ステージ画像(背景)

float pos_x, pos_y;	//プレイヤーの座標
int move_x, move_y;	//プレイヤーの移動量

float camera_x;		//カメラ座標のX座標
float camera_y;		//カメラ座標のY座標

float world_screen_x;		//ワールド座標のX座標
float world_screen_y;		//ワールド座標のY軸

mode GameMode = INIT;	//ゲームモード

//関数のプロトタイプ宣言
int LoadImages(void);			//画像読込処理
void GameMain(void);			//ゲームメインシーン処理
void GameInit(void);			//ゲームの初期化処理
void PlayerControll(void);		//プレイヤー処理
void ObjectControll(void);		//オブジェクト処理
void ScreenScroll(void);		//画面スクロール処理


struct Vec2
{
	double x;
	double y;

	Vec2(double _x, double _y)
		:x(_x)
		,y(_y){}
};

//カメラ
static Vec2 g_CameraPos{ (WORLD_WIDTH / 2.0f),(WORLD_HEIGHT / 2.0f) };

//プログラムの開始
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// タイトルを設定
	SetMainWindowText("pick up apples");

	// ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	// ウィンドウサイズ設定	
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);

	// DXライブラリの初期化処理
	if (DxLib_Init() == -1)return -1;

	// 描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);

	//画像読込関数の呼び出し
	if (LoadImages() == -1)
	{
		return -1;
	}

	// ゲームループ
	while (ProcessMessage() == 0) 
	{
		//入力キー取得
		memcpy(old, now, (sizeof(char) * 256));
		GetHitKeyStateAll(now);

		// 画面の初期化
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

		//裏画面の内容を表画面に反映する
		ScreenFlip();
	}
	// プログラムの終了
	return 0;
}
//画像読込
int LoadImages(void)
{
	//スクロール画像→変数代入
	stage_img = LoadGraph("images/SampleStage2.jpg");
	//画像変数が-1ならエラーを返す
	if (stage_img == -1)
	{
		return -1;
	}

	//正常値を返す
	return 0;
}
//ゲーム初期化
void GameInit(void)
{
	//プレイヤー初期座標
	pos_x = PLAYER_POS_X;
	pos_y = PLAYER_POS_Y;

	//プレイヤー移動量
	move_x = 0;

	//プレイヤー上昇量
	move_y = 0;

	//カメラ座標の初期座標設定
	camera_x = CAMERA_LOCATION_X;
	camera_y = CAMERA_LOCATION_Y;

	//ゲームメイン処理へ
	GameMode = MAIN;
}
//ゲームメイン処理
void GameMain(void)
{
	//画面スクロール処理
	ScreenScroll();

	//プレイヤー処理
	PlayerControll();

	//オブジェクト処理
	ObjectControll();

	//カメラの更新処理
	void UpdateCamera(Vec2 pos);
}
//プレイヤー処理
void PlayerControll()
{
	//プレイヤーの描画
	DrawCircleAA(pos_x, pos_y, 10, 10, 0xff0000, TRUE, 1.0);

}
//オブジェクト処理
void ObjectControll()
{
	if (now[KEY_INPUT_LEFT])	//X減算
	{
		move_x -= 6;
	}
	if (now[KEY_INPUT_RIGHT])	//X加算
	{
		move_x += 6;
	}
	if (now[KEY_INPUT_UP])		//Y減算
	{
		move_y -= 6;
	}
	if (now[KEY_INPUT_DOWN])	//Y加算
	{
		move_y += 6;
	}
	pos_x += move_x;
}
//画面スクロール処理
void ScreenScroll()
{
	//最初のメイン画面表示
	DrawGraph(0, 0, stage_img, FALSE);

	//メイン画面のスクロール処理
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

	//カメラ座標からスクリーン座標の原点に変換する
	Vec2 screen_origin_position =
	{
		g_CameraPos.x - (SCREEN_WIDTH / 2.0f),
		g_CameraPos.y - (SCREEN_HEIGHT / 2.0f)
	};
	
	//ワールド座標からスクリーン座標に変換する
	Vec2 screen_position = Vec2(pos.x - screen_origin_position.x, world_screen_y - screen_origin_position.y);
}