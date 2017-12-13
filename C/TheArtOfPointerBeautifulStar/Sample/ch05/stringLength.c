/* stringLength.c */
#include <stdio.h>
#include <string.h>
int stringLength(char *);

int main()
{
	int length=0;
	char *str = "Apple iPod";
	printf("The length of \"%s\" is %d\n\n", str, strlen(str));

    /* using my method */
	length = stringLength(str);
	printf("The length of \"%s\" is %d\n", str, length);
	system("PAUSE");
	return 0;
}

int stringLength(char *p)
{
	int t=0;
	while(*p !='\0') {
		t++;
		p++;
	}
	return t;
}
