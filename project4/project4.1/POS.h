#pragma once
class POS
{
private://アクセス指定子：外部非公開
	int x;	//メンバ変数x:外部非公開
	int y;	//メンバ変数y:外部に非公開

public:	//アクセス指定子：外部に完全公開
	/**
	*関数名:POS 引数なしコンストラクタ
	*引数：なし
	* 処理内容：メンバ変数の初期化
	*/
	POS();

	/*
	* 関数名:POS 引数ありコンストラクタ
	* 引数：
	* int tmpx,int tmpy
	* 処理内容：
	* メンバ変数x をtmpx,
	* メンバ変数y をtmpy で初期化する
	*/
	POS(int tmpx, int tmpy);

	void print();
};