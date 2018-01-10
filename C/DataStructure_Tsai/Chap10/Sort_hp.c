/* 堆積排序 */
#include <stdio.h>

void adjust(int, int);
int data[11] = {0, 75, 23, 98, 44, 57, 12, 29, 64, 38, 82};

void main()
{
	int i, k, temp;
	printf("\n<< Heap sort >>\n");
	printf("\nNumber : ");
	for(k = 1; k <= 10; k++)
		printf("%d  ", data[k]);
	puts("");
	for(k = 0; k < 60; k++) printf("-");
	for(i = 10/2; i > 0; i--)
		adjust(i, 10);
	printf("\nHeap   : ");
	for(k = 1; k <= 10; k++)
		printf("%d  ", data[k]);
	for(i = 9; i > 0; i--)
	{
		temp = data[i+1];
		data[i+1] = data[1];
		data[1] = temp;    /* 將樹根和最後的節點交換 */
		adjust(1, i);      /* 再重新調整為堆積樹 */
		printf("\nAccess : ");
		for(k = 1; k <= 10; k++)
			printf("%d  ", data[k]);
	}
	puts("");
	for(k = 0; k < 60; k++) printf("-");
	printf("\nSorting: ");
	for(k = 1; k <= 10; k++)
		printf("%d  ", data[k]);
}

void adjust(int i, int n)   /* 將資料調整為堆積樹 */
{
	int j, k, done = 0;
	k = data[i];
	j = 2*i;
	while((j <= n) && (done == 0))
	{
		if((j < n) && (data[j] < data[j+1])) j++;
		if(k >= data[j]) done = 1;
		else
		{
			data[j/2] = data[j];
			j *= 2;
		}
	}
	data[j/2] = k;
}
