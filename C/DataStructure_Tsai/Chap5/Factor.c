/*
	Name : Factor.c
	Description : �Q�λ��j��ƩI�s�p��N ����

	ex : n = 3 ��,���j��ư���p�U :

			if  ( n == 1)
				return (1);
			else
				return( 3* Factorial(3-1) );
							��
				return( 2* Factorial(2-1) );
							��
				return(1) ;
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


	printf("-----Factorial counting Using Recursive----");
	do
	{
		printf("\nEnter a number( 0<=n<=12 ) to count n!: ");
		scanf("%ld",&n);

		/* n �Ȧb�@��t�Τ��W�L13�|����overflow �o�줣���T����*/
		if ( n < 0 || n >12 )
			printf("input out of range !\n");
		else
			printf("%ld! = %ld\n",n,Factorial(n) );
			
		printf("Continue (y/n) ? ");
		ch = toupper(getche());
	} while (ch == 'Y' );
}

/* �Q�λ��j�I�s�ۤv�p��N ����*/
long Factorial(long n)
{
	if ( n == 1 || n== 0)
		return (1);
	else
		return( n * Factorial(n-1));
}
