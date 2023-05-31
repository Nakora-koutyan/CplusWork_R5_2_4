#include<stdio.h>
#include<string.h>
#include"Person.h"

Person::Person()
{
	name = NULL;
}
Person::Person(char* name)
{
	int len = (int)strlen(name);
	this->name = new char[len + 1];

	strcpy_s(this->name, len + 1, name);
	printf("%s\n", this->GetName());
}
Person::~Person()
{
	printf("%s\n", this->GetName());
	delete[]name;
}
Person& Person::operator=(const Person& psn)
{
	if (this == &psn)
	{
		return *this;
	}

	delete[] name;
	unsigned int len = (int)strlen(psn.name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, psn.name);

	return *this;
}
char* Person::GetName()
{
	return this->name;
}