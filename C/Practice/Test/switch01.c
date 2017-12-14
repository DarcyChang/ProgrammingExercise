#include <stdio.h>
#include <stdlib.h>


int test(){
	int d=20;
	return d;
}
int main(){

	int a,b,c;
	int d;
	a=b=c=10;
	d=20;
//	while(1)
//	{
	switch(a ==b)
	{
		case 0:
			printf("0\n");
			break;
		case 1:
			printf("1\n");
			break;
//			continue;
		case -1:
			printf("-1\n");
			break;
		default:
			printf("fuck!\n");

//	}
	}

ret:
	printf("d = %d\n",test());

	return 0;
}
