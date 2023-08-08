#pragma once
#include "DxLib.h"
#include "MouseControll.h"
class PlayerBar
{
public:
	static int bar_x;
	static int bar_y;

public:
	PlayerBar();			//コンストラクタ
	~PlayerBar();			//デストラクタ
	void Update();			//描画以外に関することを実装する
	void Draw()const;		//描画に関することを実装する
	void ReflectionBar();	//バーの反射
};

