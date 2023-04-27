#pragma once
class CNum
{
private: //アクセス指定子：外部に非公開
	static int m_num; //static メンバ変数(静的メンバ変数)：m_num

public:

	/**
	* アクセス指定子:外部に完全公開
	*関数：
	*
	*
	*
	*
	*/
	CNum();
	~CNum();
	void Disp();

};
