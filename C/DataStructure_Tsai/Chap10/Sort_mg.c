/* 合併排序 */
#include <stdio.h>
void select_sort(int[], int);
void merge_sort(int[], int[], int[], int, int);
void main()
{
	int data1[10], data2[10], data3[20];
	int size1 = 0, size2 = 0, i;
	/* 要求輸入兩個數列作合併 */
	printf("\nPlease enter data 1 to sort ( enter 0 when end ):\n");
	printf("Number : ");
	do
	{
		scanf("%d", &data1[size1]);
	}  while(data1[size1++] != 0);
	printf("Please enter data 2 to sort ( enter 0 when end ):\n");
	printf("Number : ");
	do
	{
		scanf("%d", &data2[size2]);
	}  while(data2[size2++] != 0);
	/* 先使用選擇排序將兩數列排序，再作合併 */
	select_sort(data1, --size1);
	select_sort(data2, --size2);
	for(i = 0; i < 60; i++) printf("-");
	printf("\nData 1 : ");
	for(i = 0; i < size1; i++)
		printf("%d  ", data1[i]);
	printf("\n");
	printf("Data 2 : ");
	for(i = 0; i < size2; i++)
		printf("%d  ", data2[i]);
	printf("\n");
	for(i = 0; i < 60; i++) printf("-");
	printf("\n");
	merge_sort(data1, data2, data3, size1, size2);
	for(i = 0; i < 60; i++) printf("-");
	printf("\nSorting: ");
	for(i = 0; i < size1+size2; i++)
		printf("%d  ", data3[i]);
}
void select_sort(int data[], int size)
{
	int base, compare, min, temp;
	for(base = 0; base < size-1; base++)
	{
		min = base;
		for(compare = base+1; compare < size; compare++)
			if(data[compare] < data[min])
				min = compare;
		temp = data[min];
		data[min] = data[base];
		data[base] = temp;
	}
}
void merge_sort(int data1[], int data2[], int data3[], int size1, int size2)
{
	int arg1, arg2, arg3, i;
	data1[size1] = 32767;
	data2[size2] = 32767;
	arg1 = 0;
	arg2 = 0;
	for(arg3 = 0; arg3 < size1+size2; arg3++)
	{
		/* 比較兩數列，資料小的先存於合併後的數列 */
		if(data1[arg1] < data2[arg2])
		{
			data3[arg3] = data1[arg1];
			arg1++;
		}
		else
		{
			data3[arg3] = data2[arg2];
			arg2++;
		}
		printf("Access : ");
		for(i = 0; i < arg3+1; i++)
			printf("%d  ", data3[i]);
		printf("\n");
	}
}
