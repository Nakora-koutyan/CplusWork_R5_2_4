#pragma once

class POS
{
private://アクセス指定子:外部に非公開
	int x;	//メンバ変数ｘ：外部に非公開
	int y;	//メンバ変数ｙ：外部に非公開


public:	//アクセス指定子:外部に完全公開
	/**
	*関数名:SetPos
	* 引数:
	* int tempX メンバ変数xに代入する数
	* int tempY メンバ変数yに代入する数
	* 処理内容：
	* 引数で受け取った値でメンバ変数を更新する
	*/
	int setPos(int tmpx, int tmpy);
	void print();
};