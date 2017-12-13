/* threePointer.c */
#include <stdio.h>
#include <conio.h>
int main()
{
    int x = 100;
	int *p1 = &x;
	int **p2 = &p1;
	int ***p3 = &p2;

	printf("變數定義如下: \n");
	printf("int x=100;\nint *ptr=&x;\nint **p2=&p1;\nint ***p3=&p2\n\n");
    
    printf("&x=%p\n", &x);
	printf("&p1=%p, p1=%p\n", &p1, p1);
    printf("&p2=%p, p2=%p\n", &p2, p2);
    printf("&p3=%p, p3=%p\n\n", &p3, p3);

	printf("以下的方法可得到 100: \n");
    printf("***p3=%d, **p2=%d, *p1=%d, x=%d\n", ***p3, **p2, *p1, x);
    getch();
    return 0;
}
