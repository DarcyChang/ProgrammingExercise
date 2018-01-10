/* 
	Name : Fib_i.c
	Description : Fibonacci numbers count using iterative
	�Q�ΰj��k�p��O��ƦC

	�O��ƦC��0,1,1,2,3,5,8,13,21,�K
	�䤤�Y�@�����e�G�����M,�B��0����0,��1����1
*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>

/* ��ƭ쫬�ŧi */
long Fibonacci(long);

void main()
{
	char ch;
	long n;

	printf("-----Fibonacci numbers Using Iterative-----");
	do
	{
		printf("\nEnter a number(n >=0) : ");
		scanf("%ld",&n);
		/* n �Ȥj�� 0 */
		if ( n < 0 )
			printf("Input number must be > 0!\n");
		else
			printf("Fibonacci(%ld) = %ld\n",n,Fibonacci(n));

		printf("Continue (y/n) ? ");
		ch = toupper(getche());
	} while (  ch == 'Y');
}

long Fibonacci(long n)
{
	long backitem1;    /*�e�@����*/
	long backitem2;    /*�e�G����*/
	long thisitem;     /*�ثe���ƭ�*/
	long i;

	if (n == 0)    /* �O��ƦC��0����0 */
		return (0);
	else if (n == 1)    /* �ĤG����1 */
		return (1);
	else
	{
		backitem2 = 0;
		backitem1 = 1;

		/* �Q�ΰj��N�e�G���ۥ[���J�ثe�� */
		/* ������ܫe�G�����Ȧܨ��n���D�o */
		for ( i = 2; i <= n; i++ )
		{
			/* F(i) = F(i-1) + F(i-2) */
			thisitem = backitem1 + backitem2;
			/*���ܫe�G������*/
			backitem2 = backitem1;
			backitem1 = thisitem;
		}

		return (thisitem);
	}
}
