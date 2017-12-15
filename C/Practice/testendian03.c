#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	short int a = 0x1234;
	char *p = (char *)&a;
			    
	printf("p=%#hhx\n",*p);
	if(*p == 0x34) 
		printf("Little endian \n");
	else if(*p == 0x12) 
		printf("Big endian \n");
	else 
		printf("Unknow endian \n");
	
	return 0;
}
