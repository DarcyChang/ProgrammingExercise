/* 
	Name : Factor_i.c
	Description : Factorial numbers count unsing iterative 
	�Q�ΰj�鰵N�������p��
*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

/* ��ƭ쫬�ŧi */
long Factorial(long);

void main()
{
	char ch;
	long n;

	printf("-----Factorial counting using Iterative-----");

	do
	{
		printf("\nEnter a number(0 <= n <= 12) to count n! : ");
		scanf("%ld",&n);
		if ( n < 0 || n > 12)
			printf("Input out of range!\n");
		else
			printf("%ld! = %ld\n",n,Factorial(n));

		printf("Continue (y/n)? ");
		ch = toupper(getche());
	} while ( ch == 'Y');
}

long Factorial(long n)
{
	long sum = 1;
	int  i;

	if ( n == 0 || n ==1)  /*��n=0��n=1��,0!=1,1!=1 */
		return (1);  /*�G�����Ǧ^1 */
	else
	{
		for ( i = 2; i<= n; i++ ) /*sum�O���ثe�������M*/
			sum *= i;  /*sum �Pi�ۭ����M��^sum��*/
	}
	return (sum);
}
