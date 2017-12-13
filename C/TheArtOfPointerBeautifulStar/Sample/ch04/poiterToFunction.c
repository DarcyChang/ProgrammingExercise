/* pointerToFunction.c  */
#include <stdio.h>
#include <conio.h>

int add(int, int);
int sub(int, int);
int multiply(int, int);
int divide(int, int);
int (*operation)(int, int);

int main()
{
	int x, y, output;
	printf("½Ğ¿é¤J x »P y: ");
	scanf("%d %d", &x, &y);
	operation = add;
	output = (*operation)(x, y);
	printf("%d + %d = %d\n", x, y, output);

	operation = sub;
	output = (*operation)(x, y);
	printf("%d - %d = %d\n", x, y, output);

	operation = multiply;
	output = (*operation)(x, y);
	printf("%d * %d = %d\n", x, y, output);
	
	operation = divide;
	output = (*operation)(x, y);
	printf("%d / %d = %d\n", x, y, output);
    getch();
	return 0;
}

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int multiply(int a, int b)
{
	return a*b;
}

int divide(int a, int b)
{
	return a/b;
}
