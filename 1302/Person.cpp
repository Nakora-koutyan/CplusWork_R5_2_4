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
	printf("%s‚³‚ñ‚Ì”N—î‚Í%dÎ‚Å‚·B\n", this->name, this->age);
}