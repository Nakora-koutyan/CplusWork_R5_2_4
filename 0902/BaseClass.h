#pragma once
class BaseClass
{
protected:  //アクセス指定子:一部公開
			//オブジェクト外部からの
			//アクセスを禁止する
			//派生先に公開

	const char* str;
};
