/* 選擇排序 */
#include <stdio.h>
void select_sort(int[], int);
void main()
{
	int data[20];
	int size = 0, i;
	/* 要求輸入資料直到輸入為零 */
	printf("\nPlease enter number to sort ( enter 0 when end ):\n");
	printf("Number : ");
	do
	{
		scanf("%d", &data[size]);
	}  while(data[size++] != 0);
	for(i = 0; i < 60; i++) printf("-");
	printf("\n");
	select_sort(data, --size);
	for(i = 0; i < 60; i++) printf("-");
	printf("\nSorting: ");
	for(i = 0; i < size; i++)
		printf("%d  ", data[i]);
}
void select_sort(int data[], int size)
{
	int base, compare, min, temp, i;
	for(base = 0; base < size-1; base++)
	{	/* 將目前資料與後面資料中最小的對調 */
		min = base;
		for(compare = base+1; compare < size; compare++)
			if(data[compare] < data[min])
			min = compare;
		temp = data[min];
		data[min] = data[base];
		data[base] = temp;
		printf("Access : ");
		for(i = 0; i < size; i++)
			printf("%d  ", data[i]);
		printf("\n");
	}
}