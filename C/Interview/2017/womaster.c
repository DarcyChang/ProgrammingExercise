#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *pointer= (char*) malloc(1);

	printf("pointer: %d\n", pointer);
	*pointer = 'b';
	printf("%c\n", *pointer);

	return 0;
}
