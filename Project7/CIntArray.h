#pragma once
class CIntArray
{
private:	//アクセス指定子：外部に非公開
	int* m_pnum;	//メンバ変数 *m_pnum：外部に非公開
	int m_NumOf;	//メンバ変数 m_NumOf：外部に非公開

public:		//アクセス指定子：外部に公開
	/**
	*　関数名：CIntArray コンストラクタ
	* 引数：
	* const int nNumOf 作成する配列の要素数
	* 処理内容：
	* メンバ変数m_pnumに引数NumOfの分だけ配列をnewで作成する
	* メンバ変数m_NumOfを作成した配列の要素数：外部に公開
	*/
	CIntArray(const int nNumOf);
	~CIntArray();

public:
	int Get(const int index);
	void Set(const int index, const int value);

private:
	void CheckIndex(const int index);
};
