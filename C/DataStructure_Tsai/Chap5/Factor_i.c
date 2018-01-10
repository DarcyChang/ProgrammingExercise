/* 
	Name : Factor_i.c
	Description : Factorial numbers count unsing iterative 
	利用迴圈做N階乘的計算
*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

/* 函數原型宣告 */
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

	if ( n == 0 || n ==1)  /*當n=0或n=1時,0!=1,1!=1 */
		return (1);  /*故直接傳回1 */
	else
	{
		for ( i = 2; i<= n; i++ ) /*sum記錄目前階乘之和*/
			sum *= i;  /*sum 與i相乘之和放回sum中*/
	}
	return (sum);
}
