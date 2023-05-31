#include<stdio.h>
#include"DxLib.h"

// じゃんけんの結果を判断する
// じゃんけんの結果を表示する
int Result{
DrawFormatString(20, 110, GetColor(255, 255, 255), "結果は・・・");
	if (a == b)
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "引き分けです!!!");
	}
	else if ((a == 0 && b == 1) ||(a == 1 && b == 2) ||(a == 2 && b == 0))
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "あなたの勝ちです!!!");
	}
	else
	{
		DrawFormatString(20, 130, GetColor(255, 255, 255), "あなたの負けです...");
	}
}
