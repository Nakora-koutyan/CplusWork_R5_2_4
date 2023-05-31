#pragma once
class Person
{
private:
	char* name;
public:
	Person();
	Person(char*);
	~Person();

	Person& operator=(const Person& psn);
	char* GetName();
};