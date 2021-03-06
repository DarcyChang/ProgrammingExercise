/* stringCompare_n.c */
#include <stdio.h>
#include <string.h>
int stringCompare_n(char *, char *, int);

int main()
{
	char *str1 = "Honda Civic";
	char *str2 = "Honda Accord";
    int value;

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("\n使用庫存函數 strncmp(str1, str2, 5)....\n");
	value=strncmp(str1, str2, 5);
	switch(value) {
	    case 0: 
			printf("str1 與 str2 相等\n");
            break;
	    case 1: 
			printf("str1 大於 str2\n");
            break;
	    case -1: 
			printf("str1 小於 str2\n");
            break;
	} 
 
	/* using my method */	
	value=stringCompare_n(str1, str2, 5);
	printf("\n呼叫使用者自定函數 stringCompare_n(str1, str2, 5)....\n");
	if(value==0) 
		printf("str1 與 str2 相等\n");
    else if(value>0) 
		     printf("str1 大於 str2\n");
         else 
			 printf("str1 小於 str2\n");
    system("PAUSE");
	return 0;
}

int stringCompare_n(char *x, char *y, int n)
{
	int i;
	for(i=1; (*x == *y) || i<=n; x++, y++) 
	   if(*x == '\0')
	      return 0;
    return *x-*y;	
}
