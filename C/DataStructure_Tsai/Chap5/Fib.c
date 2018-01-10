/* 
	Name : Fib.c
	Description : Fibonacci numbers 
	利用函數遞迴呼叫做費氏數列計算

	費氏數列為0,1,1,2,3,5,8,12,21,…
	其中某一項為前二項之和,且第0項為0,第1項為1
*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>

/* 函數原型宣告 */
long Fibonacci(long);

void main()
{
	char ch;
	long n;


	printf("-----Fibonacii numbers Using Recursive-----"); 
	do
	{
		printf("\nEnter a number(n>=0) : ");
		scanf("%ld",&n);
		/* n值大於0 */
		if ( n < 0 )
			printf("Number must be > 0\n");
		else
			printf("Fibonacci(%ld) = %ld\n",n,Fibonacci(n));
		printf("Contiune (y/n) ? ");
		ch = toupper(getche());
	} while ( ch == 'Y' );
}

/* 利用遞迴函數呼叫本身函數來計算Fibonacci numbers*/
long Fibonacci(long n)
{
	if ( n == 0)  /*第0項為 0 */
		return (0);
	else if ( n == 1 ) /*第1項為 1 */
		return (1);
	else  /*遞迴呼叫函數 第N項為n-1 跟 n-2項之和*/
		return( Fibonacci(n-1) + Fibonacci(n-2) );
}
