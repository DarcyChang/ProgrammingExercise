#include <stdio.h>
#define a 300
#define b 200
#define c 100

int main(void)
{
	char ch;
	int aa;
	double bb;

//	printf("a is %d\n", a);

	while(scanf("%c", &ch)==1)
	{
		switch(ch)
		{
			case 'a' :
				printf("you can buy an apple.");
				break;
			case 'b' :
				printf("you can buy a boy.");
				break;
			case 'c' :
				printf("you can buy a cat.");
				break;
//			default :
//				printf("again!");
		}
		printf("jump!");
	}

	return 0;
}//end of main

