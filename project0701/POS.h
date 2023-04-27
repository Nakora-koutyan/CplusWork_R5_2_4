#pragma once
class POS
{
private: //アクセス指定子:外部に非公開
	int x; //メンバ変数x
	int y; //メンバ変数y

public:	//アクセス指定子:外部に公開
	/**
	* 関数名：POS() コンストメンバ関数
	* 引数:POS コンストラクタ
	* 処理内容:なし
	* 変数の値の固定化・アドレスの固定化
	* 
	*/
	POS();

	int getX()const; //getXの値の固定化
	int getY()const; //getYの値の固定化

	void setX(int tmpx);
	void setY(int tmpy);


};
