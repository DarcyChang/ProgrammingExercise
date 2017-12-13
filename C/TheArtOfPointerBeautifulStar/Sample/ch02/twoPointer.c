/* twoPointer.c */
#include <stdio.h>
#include <conio.h>
int main()
{
    int x = 100;
	int *p1 = &x;
	int **p2 = &p1;

	printf("變數定義如下: \n");
	printf("int x = 100;\nint *p1 = &x;\nint **p2 = &p1;\n\n");
    
    printf("&x=%p\n", &x);
	printf("&p1=%p, p1=%p\n", &p1, p1);
    printf("&p2=%p, p2=%p\n\n", &p2, p2);
    
    printf("**p2=%d, *ptr=%d\n", **p2, *p1);
    getch();
    return 0;
}
