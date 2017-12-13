/* pointer&++.c */
#include <stdio.h>
#include <conio.h>

int main()
{
	int i[] = {100, 200, 300, 400, 500};
	int *pi = i;
	printf("i=%p, pi=%p\n", i, pi);
	printf("i[0]=%d\n", i[0]);
	printf("*pi=%d\n\n", *pi);
	
	pi+1;
	printf("After pi+1, pi=%p\n", pi);;
	printf("*pi=%d\n\n", *pi);
	
	pi++;
    printf("After pi++, pi=%p\n", pi);
	printf("*pi =%d\n", *pi);
 
	getch();
	return 0;
}
