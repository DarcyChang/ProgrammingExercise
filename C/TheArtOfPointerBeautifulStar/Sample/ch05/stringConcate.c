/* stringConcate.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void stringConcate(char *, char *);

int main()
{
	char str2[80]="I want to buy a ";
	char *str1 = "Apple iPod";
	char str3[80]="I want to buy a ";

	printf("�ϥήw�s��� strcat()....\n");
	strcat(str2, str1);
	printf("str2 = %s\n\n", str2);
 
	/* using my method */	
	stringConcate(str3, str1);
	printf("�I�s�ϥΪ̦۩w��� stringConcat()....\n");
	printf("str3 = %s\n", str3);
	system("PAUSE");
	return 0;
}

void stringConcate(char *dest, char *source)
{
	while(*dest != '\0') 
		dest++;
	while((*dest=*source) != '\0') {
		source++;
		dest++;
	}
}
