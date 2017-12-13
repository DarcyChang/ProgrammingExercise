/* stringCompare.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int stringCompare(char *, char *);

int main()
{
	char *str1 = "Honda Civiciii";
	char *str2 = "Honda Civic";
    int value;

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("\nㄏノ畐ㄧ计 strcmp(str1, str2)....\n");
	value=strcmp(str1, str2);
	switch(value) {
	    case 0: 
			printf("str1 籔 str2 单\n");
            break;
	    case 1: 
			printf("str1  str2\n");
            break;
	    case -1: 
			printf("str1  str2\n");
            break;
	} 
 
	/* using my method */	
	value=stringCompare(str1, str2);
	printf("\n㊣ㄏノ﹚ㄧ计 stringCompare(str1, str2)....\n");
	if(value==0) 
		printf("str1 籔 str2 单\n");
    else if(value>0) 
		     printf("str1  str2\n");
         else 
			 printf("str1  str2\n");
    system("PAUSE");
	return 0;
}

int stringCompare(char *x, char *y)
{
	for( ; *x == *y; x++, y++)
        if(*x == '\0')
           return 0; 
    return *x-*y;	
}
