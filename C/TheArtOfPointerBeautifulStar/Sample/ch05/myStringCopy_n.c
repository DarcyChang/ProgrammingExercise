/* myStringCopy_n.c */

#include <stdio.h>
#include <string.h>
void myStringCopy_n(char *, char *, int n);

int main()
{
	int length=0;
	char str2[80];
	char *str1 = "Apple iPod";
	char str3[80];

	printf("呼叫字串庫存函數: strncpy()...\n");
	strncpy(str2, str1, 5);
	str2[5]='\0';
	printf("str2=%s\n\n", str2);
 
	/* using my method */
	myStringCopy_n(str3, str1, 5);
	str3[5]='\0';
	printf("呼叫使用者自定函數: myStringCopy_n()...\n");
	printf("str3=%s\n", str3);
	system("PAUSE");
	return 0;
}

void myStringCopy_n(char *dest, char *source, int n)
{
	int i=1;
	while( (i <= n) && (*dest = *source) != '\0' ) {		
		source++;
		dest++;
		i++;
	}
}
