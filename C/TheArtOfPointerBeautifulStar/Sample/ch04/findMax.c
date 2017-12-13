/* findMax.c*/
#include <stdio.h>
#include <conio.h>
int findmax(int [], int);

int main()
{
	int i;
	int arr[]={20, 10, 100, 40, 60, 80, 90};
	int elements=sizeof(arr)/sizeof(arr[0]);
	int maxNumber = findmax(arr, elements);

	printf("Max( ");
	for(i=0; i<elements; i++)
		printf("%d ", arr[i]);
	printf(") is %d\n", maxNumber);
    getch();
	return 0;
}

int findmax(int x[], int n)
{
	int j;
	int max=x[0];
	for(j=1; j<n; j++)
		if(x[j] > max)
			max=x[j];
	return max;
}


