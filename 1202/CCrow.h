#pragma once
#include"CBird.h"

class CCrow :public CBird
{
public:
	//「鳴く」関数(仮想関数)
	void sing();
	//「飛ぶ」関数
	void fly();
};
