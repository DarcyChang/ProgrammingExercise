/* Exercise 01.c */
#include <stdio.h>

#define MAX 10

void input(int *num)
{
	int i;
	for(i=0; i<10; i++){	
		scanf("%d", num+i);
//		printf("%d\n", *(num+i));
	}
}

int sum(int* num)
{
	int total = 0, i;
	for(i=0; i<10; i++){	
		total += *(num+i);
	}
	return total;
}

int main()
{
	int num[MAX], total=0;
	input(num);	
	total = sum(num);
	printf("total number = %d\n", total);
	return 0;
}
	
