#include"Human.h"
#include"Japanese.h"

void action(Human& human)
{
	human.speak();
}

int main()
{
	Human john;
	Japanese taro;

	action(john);
	action(taro);

	return 0;
}