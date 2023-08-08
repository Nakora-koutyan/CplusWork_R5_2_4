#pragma once

struct LocationBall				/* 中心座標 */
{
	int x;						//ボールのｘ座標
	int y;						//ボールのｙ座標
};
class Ball
{
private:
	int speed;					//ボールの速度
	int ball_flg;				//ボールの状態(0.移動中　1.バー接触　2.スタート状態)
	int moveball_x;				//ボールの動く距離
	int moveball_y;				//ボールの動く距離
	LocationBall location_ball;		

public:
	Ball();						//コンストラクタ
	~Ball();					//デストラクタ
	void MoveBall();			//ボールの移動処理
	void StartBall();			//ボールの動作開始
	void ReflectionBall();		//ボールの反射
	void Update();				//描画以外に関することを実装する
	void Draw()const;			//描画に関することを実装する
};

