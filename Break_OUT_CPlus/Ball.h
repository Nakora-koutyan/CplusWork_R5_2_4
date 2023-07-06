#pragma once

struct LocationBall
{
	int x;
	int y;
};
class Ball
{
private:
	int speed;					//ボールの速度
	int ball_flg;				//ボールの状態(0.移動中　1.バー接触　2.スタート状態)
	int ball_angle;
	LocationBall location;

public:
	Ball();						//コンストラクタ
	~Ball();					//デストラクタ
	bool InitBallLocation();	//ボールの初期座標
	void StartBall();			//ボールの動作開始
	void Update();				//描画以外に関することを実装する
	void Draw()const;			//描画に関することを実装する
};

