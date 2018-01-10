/* 泡沫排序 */
#include <stdio.h>
void bubble_sort(int[], int);
void main(void)
{
	int data[20];
	int size = 0, i;
	printf("\nPlease enter number to sort ( enter 0 when end ):\n");
	printf("Number : ");
	do    /* 要求輸入數字直到輸入數字為零 */
	{
		scanf("%d", &data[size]);
	}  while(data[size++] != 0);
	for(i = 0; i < 60; i++) printf("-");
	printf("\n");
	bubble_sort(data, --size);  /* --size用於將資料為零者排除 */
	for(i = 0; i < 60; i++) printf("-");
	printf("\nSorting: ");
	for(i = 0; i < size; i++)
		printf("%d  ", data[i]);
}
void bubble_sort(int data[], int size)
{
	int i, j, k, temp, flag;
	for(i=0; i<size-1; i++)  /* 讓資料兩兩比較，將小的置於前 */
	{
		flag=0;
		for(j=0; j<size-1; j++)
			if(data[j] > data[j+1])				
			{
				flag=1;
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		printf("Access : ");
		for(k = 0; k < size; k++)
			printf("%d  ", data[k]);
		printf("\n");
		if(flag != 1)
			break;
	}
}