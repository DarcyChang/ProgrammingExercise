/* 插補搜尋 */
#include <stdio.h>
void main()
{
	int data[11] = {0, 12, 23, 29, 38, 44, 57, 64, 75, 82, 98};
	int i, l = 0, n = 10, m, cnt = 0, input, ok = 0;
	printf("\n<< Interpolation search >>\n");
	printf("\nSorted data: ");
	for(i = 1; i < 11; i++)
		printf("%d  ", data[i]);
	puts("");
	printf("\nPlease enter a number from data: ");
	scanf("%d", &input);
	printf("\nSearch.....\n");
	while((n - l) > 1 && ok == 0)
	{	/* 為排除資料最前面的0，故算式最後加1 */
		m = l + (input-data[l])*(n-l-1) / (data[n]-data[l]) + 1;
		if(m > n || m < l) break;
		printf("\nData when searching %2d time(s) is %d !", ++cnt, data[m]);
		if(data[m] > input)
		{
			n = m;
			printf(" ---> Choice number is Smaller than %d", data[m]);
		}
		else
			if(data[m] < input)
			{
				l = m;
				printf(" ---> Choice number is bigger than %d", data[m]);
			}
			else
			{
				printf("\n\nFound, %d is the %dth record in data !", input, m);
				ok = 1;
			}
	}
	if(ok == 0)
		printf("\n\nSorry, %d not found !", input);
}
