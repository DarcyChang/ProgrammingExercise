/* ���J�Ƨ� */
#include <stdio.h>
void insertion_sort(int[], int);
void main()
{
	int data[20];
	int size = 0, i;
	printf("\nPlease enter number to sort ( enter 0 when end ):\n");
	printf("Number : ");
	do    /* �n�D��J��ƪ����J���s */
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
	/* ���Ƥp��Ĥ@���A�h����e��A�_�h�P�᭱��Ƥ���X���J��m */
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