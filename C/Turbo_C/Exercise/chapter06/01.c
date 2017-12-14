#include <stdio.h>
#include <string.h>

void FigureOutMaxNumber(int *number, int *max_number)
{	
	int i = 0;

	for(i = 0; i<20; i++){
		printf("Address %p number[%d]: %d\n", number+i, i, number[i]); // For test.
	}

	
}

int main()
{
	int i = 0;
	int number[20];
	int *max_number = number;

	printf("\nPlease input twenty number:\n");
	for(i = 0; i<20; i++){
		printf("Number %d: ", i+1);
		scanf("%d", number+i);
		if(number[i] > *max_number)
			max_number = number+i;
		
		printf("Address %p number[%d]: %d\n", number+i, i, number[i]); // For test.
	}
	
//	FigureOutMaxNumber(number, &max_number);

	printf("Max number is %d and address is %p\n", *max_number, max_number);
}
