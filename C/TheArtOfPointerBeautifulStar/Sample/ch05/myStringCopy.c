/* myStringCopy.c */
#include <stdio.h>
#include <string.h>
void myStringCopy(char *, char *);

int main()
{
	int length=0;
	char str2[80];
	char *str1 = "Apple iPod";

	printf("呼叫字串庫存函數: strcpy()...\n");
	strcpy(str2, str1);
	printf("str2=%s\n\n", str2);
 
	/* using my method */
	myStringCopy(str2, str1);
	printf("呼叫使用者自定函數: myStringnCopy()...\n");
	printf("str2=%s\n", str2);
	system("PAUSE");
	return 0;
}

void myStringCopy(char *dest, char *source)
{
	while((*dest = *source) != '\0') {
		source++;
		dest++;
	}
}
