/* stringConcate_n.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void stringConcate_n(char *, char *, int);

int main()
{
	char str2[80]="I want to buy a ";
	char *str1 = "Apple iPod";
	char str3[80]="I want to buy a ";

	printf("Using strncat()....\n");
	strncat(str2, str1, 5);
	printf("str2 = %s\n\n", str2);
 
	/* using my method */	
	stringConcate_n(str3, str1, 5);
	printf("Using stringConcat_n()....\n");
	printf("str3 = %s\n", str3);
	system("PAUSE");
	return 0;
}

void stringConcate_n(char *dest, char *source, int n)
{
	int i=1;
	while(*dest != '\0') 
		dest++;
	while( i<=n && (*dest=*source) != '\0' ) {
		source++;
		dest++;
		i++;
	}
}
