/* P. 117, Do stricmp function. */
/* stringCompare.c */
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

int stricmp(char *, char *);

int main()
{
	char *str1 = "HONDA CIVICIII0";
	char *str2 = "honda civiciii1";
    int value = 100;

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);

	value=strcasecmp(str1, str2);
	printf("\n strcasecmp(str1, str2)....\n");

    if(value==0)
        printf("str1 =  str2 \n");
    else if(value>0)
        printf("str1 > str2\n");
    else
        printf("str1 < str2\n");

    /* using my method */
	value=stricmp(str1, str2);
	printf("\n stricmp(str1, str2)....\n");

    if(value==0)
        printf("str1 =  str2 \n");
    else if(value>0)
        printf("str1 > str2\n");
    else
        printf("str1 < str2\n");
	return 0;
}

int stricmp(char *x, char *y)
{

	for( ; tolower(*x) == tolower(*y); x++, y++)
        if(*x == '\0')
           return 0;
    return *x-*y;
}
