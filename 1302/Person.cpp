#include<stdio.h>
#include"Person.h"

Person::Person(char* name, int age)
{
	this->name = name;
	this->age = age;
}

Person::~Person()
{
}
void Person::Show()
{
	printf("%sさんの年齢は%d歳です。\n", this->name, this->age);
}