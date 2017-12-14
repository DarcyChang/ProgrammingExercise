/* 9x9 table */

#include <stdio.h>

int main(void)
{
	int c,r;
	for(c=1;c<=9;c++)
	{
		for(r=1;r<=9;r++)
		{
			printf("%d x %d = %d\n",c, r, c*r);
		}
		printf("\n");
	}
	return 0;
}

