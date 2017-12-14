#include <stdio.h>
#include <string.h>

void BinarySearch(int *number, int *max_number){


}
void SequentialSearch(int *number, int *max_number){


}

void SelectionSort(int *number, int *max_number){

}

void BubbleSort(int *number, int *max_number)
{	
	int i = 0;

	for(i = 0; i<20; i++){
		printf("Address %p number[%d]: %d\n", number+i, i, number[i]); // For test.
	}

	
}

int main()
{
	int i = 0;
	int number[]={53,23,44,38,65,41,55,95,11,12};
	int max_number = 0;
	int *max_number_address;

	printf("Please input twenty number:\n");
	for(i = 0; i<20; i++){
		printf("Number %d: ", i+1);
		scanf("%d", number+i);
		if(number[i]>max_number){
			max_number = number[i];
			max_number_address = number+i;
		}
//		printf("Address %p number[%d]: %d\n", number+i, i, number[i]); // For test.
	}
	
//	FigureOutMaxNumber(number, &max_number);

	printf("Max number is %d and address is %p\n", max_number, max_number_address);
}
