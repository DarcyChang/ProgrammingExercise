/* sumOfArray1-2.c */
#include <stdio.h>
#include <conio.h>
int sum(int *, int);

int main()
{
	int i;
	int arr[]={10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int elements=sizeof(arr)/sizeof(arr[0]);
	int total = sum(arr, elements);

	printf("Sum(");
	for(i=0; i<elements; i++)
		printf("%d ", arr[i]);
	printf(") is %d\n", total);
    getch();
	return 0;
}
	
int sum(int *x, int n)
{
	int j, t=0;
	for(j=0; j<n; j++)
		t += *(x+j);
	return t;
}
