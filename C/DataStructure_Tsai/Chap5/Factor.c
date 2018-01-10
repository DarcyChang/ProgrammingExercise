/*
	Name : Factor.c
	Description : 利用遞迴函數呼叫計算N 階乘

	ex : n = 3 時,遞迴函數執行如下 :

			if  ( n == 1)
				return (1);
			else
				return( 3* Factorial(3-1) );
							↙
				return( 2* Factorial(2-1) );
							↙
				return(1) ;
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


	printf("-----Factorial counting Using Recursive----");
	do
	{
		printf("\nEnter a number( 0<=n<=12 ) to count n!: ");
		scanf("%ld",&n);

		/* n 值在一般系統中超過13會產生overflow 得到不正確的值*/
		if ( n < 0 || n >12 )
			printf("input out of range !\n");
		else
			printf("%ld! = %ld\n",n,Factorial(n) );
			
		printf("Continue (y/n) ? ");
		ch = toupper(getche());
	} while (ch == 'Y' );
}

/* 利用遞迴呼叫自己計算N 階乘*/
long Factorial(long n)
{
	if ( n == 1 || n== 0)
		return (1);
	else
		return( n * Factorial(n-1));
}
