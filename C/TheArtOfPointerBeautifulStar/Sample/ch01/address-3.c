/* address-3.c */
#include <stdio.h>
#include <conio.h>
int main()
{
	int x=100, y=200, z=300;
	printf("x �ܼƪ���}�O %p\n", &x);	
	printf("y �ܼƪ���}�O %p\n", &y);
	printf("z �ܼƪ���}�O %p\n\n", &z);

	printf("x �ܼƪ����e�O %d\n", x);
	printf("y �ܼƪ����e�O %d\n", y);
	printf("z �ܼƪ����e�O %d\n", z);
    getch();
	return 0;
}


