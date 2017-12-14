#include <stdio.h>

int a=10;
a=a*10;
int fun01();
int fun02();

int main(void)
{
	int b=20;
	a++;
	printf("main a is %d\n",a);
	extern int a;
	printf("main a is %d\n",a);
	fun01();
	fun02();
	return 0;
}
int fun01()
{
	a++;
	extern int a;
	extern int b;
	printf("fun01 a is %d, b is %d\n",a,b);
	//b++;
}
int fun02()
{	
	a++;
	extern int b;
	printf("fun02 a is %d, b is %d\n",a,b);
}
