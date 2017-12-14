#include <stdio.h>
int test=0;
void fun(void);

int main(void)
{
	test++;
	int test=10;
	printf("test is %d\n", test);
	for(test=0;test<3;test++)
		fun();
	return 0;
}

void fun(void)
{
	int a=0;
	static int b=0;	
	printf("a is %d , b is %d\n", a, b);
	printf("a is %d , b is %d\n", a++, b++);
}

