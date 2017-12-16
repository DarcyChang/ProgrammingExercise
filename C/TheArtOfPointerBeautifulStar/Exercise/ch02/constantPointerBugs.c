/* constPointer.c */
#include <stdio.h>
//#include <conio.h> // For windows
#include <curses.h> // For Linux 

int main()
{
	int a=100, b=200;

	const int *p = &a;
	int * const q = &b; 
	printf("a=%d, *p=%d\n", a, *p);
	printf("b=%d, *q=%d\n", b, *q);
	
	p=&b;
	printf("*p=%d\n", *p);
	
	*q=a;
	printf("*q=%d\n", *q);
	printf("b=%d\n", b);
 
//	getch();
	return 0;
}
