/* Page. 95, Exercise 4-8-02.c */
#include <stdio.h>


void input(int arr[2][4])
{
    int i = 0, j = 0;
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 4 ; j++)
        {
            printf("Please input [%d][%d]\n", i, j);
            scanf("%d",&arr[i][j]);
        }
    }
}

int total2(int arr[2][4], int *sum)
{
    int i = 0, j = 0;
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 4 ; j++)
            *sum += arr[i][j];
    }

    return 0;
}

int main()
{
	int num[2][4] = {}, sum = 0;
	input(num);
	total2(num, &sum);
	printf("total number = %d\n", sum);
	return 0;
}

