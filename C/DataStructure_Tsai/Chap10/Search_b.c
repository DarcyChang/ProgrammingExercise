/* �G���j�M */
#include <stdio.h>
void main()
{
	int data[11] = {0, 12, 23, 29, 38, 44, 57, 64, 75, 82, 98};
	int i, l = 1, n = 10, m, cnt = 0, input, ok = 0;
	printf("\n<< Binary search >>\n");
	printf("\nSorted data: ");
	for(i = 1; i < 11; i++)
		printf("%d  ", data[i]);
	puts("");
	printf("\nPlease enter a number from data: ");
	scanf("%d", &input);
	printf("\nSearch.....\n");
	m = (l + n)/2;     /* ��Ȧb��M�� */
	while(l <= n && ok == 0)
	{
		printf("\nData when searching %2d time(s) is %d !", ++cnt, data[m]);
		if(data[m] > input) /* ���j�M����Ƥp����ȡA�h��Ʀb��Ȫ��e�� */
		{
			n = m - 1;
			printf(" ---> Choice number is smaller than %d", data[m]);
		}
		else                /* �_�h��Ʀb��Ȫ��᭱ */
			if(data[m] < input)
			{
				l = m + 1;
				printf(" ---> Choice number is bigger than %d", data[m]);
			}
			else
			{
				printf("\n\nFound, %d is the %dth record in data !", input, m);
				ok = 1;
			}
		m = (l + n)/2;
	}
	if(ok == 0)
		printf("\n\nSorry, %d not found !", input);
}
