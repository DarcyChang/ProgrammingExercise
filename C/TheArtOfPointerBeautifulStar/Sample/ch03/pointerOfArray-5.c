	/* pointerOfArray-5.c  */
	#include <stdio.h>
	#include <stdlib.h>
	
	int main()
	{
	     char *parr[] = {"Department", "of", "Information", "Management"};
	     printf("*parr[3] = %c\n", *parr[3]);
	     printf("**(parr+3) = %c\n", **(parr+3));
	     printf("parr[3][0] = %c\n", parr[3][0]);
	     printf("parr[2] = %s\n", parr[2]);
	     printf("*(parr+2) = %s\n", *(parr+2));
	     system("PAUSE");
	     return 0;
	}
