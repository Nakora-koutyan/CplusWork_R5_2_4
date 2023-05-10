#pragma once

class Hoge {
private:
	int num1 = 0;//優先度：低
	int num2 = 0;//絶対呼ばれる
	int num3 = 0;
public:
	Hoge(int i) :num2(i) //優先度：中
	{
		num2 = 0;//代入
	}

	Hoge(int i) :num3(i) //優先度：中
	{
		num3 = 0;//代入
	}
};
