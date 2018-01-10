/* 插入排序 */
#include <stdio.h>
void insertion_sort(int[], int);
void main()
{
	int data[20];
	int size = 0, i;
	printf("\nPlease enter number to sort ( enter 0 when end ):\n");
	printf("Number : ");
	do    /* 要求輸入資料直到輸入為零 */
	{
		scanf("%d", &data[size]);
	}  while(data[size++] != 0);
	for(i = 0; i < 60; i++) printf("-");
	printf("\n");
	insertion_sort(data, --size);
	for(i = 0; i < 60; i++) printf("-");
	printf("\nSorting: ");
	for(i = 0; i < size; i++)
		printf("%d  ", data[i]);
}
void insertion_sort(int data[], int size)
{
	int base, compare, temp, i;
	for(base = 1; base < size; base++)
	/* 當資料小於第一筆，則插於前方，否則與後面資料比對找出插入位置 */
	{
		temp = data[base];
		compare = base;
		while(compare > 0 && data[compare-1] > temp)
		{
			data[compare] = data[compare-1];
			compare--;
		}
		data[compare] = temp;
		printf("Access : ");
		for(i = 0; i < size; i++)
			printf("%d  ", data[i]);
		printf("\n");
	}
}