#pragma once
class Person //クラスの宣言
{
private:
	char* name;
	int age;

public:
	Person(char*, int);
	~Person();

	void Show();
};