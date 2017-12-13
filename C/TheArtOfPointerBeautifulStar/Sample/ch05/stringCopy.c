/*  stringCopy.c  */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char *s = "iPhone";
	char t[80] = " ";
	printf("Before strcpy(t, s)\n");
	printf("s = %s\n", s);
	printf("t = %s\n", t);
	printf("After strcpy(t, s)\n");
	strcpy(t, s);
	printf("s = %s\n", s);
	printf("t = %s\n", t);
	system("PAUSE");
	return 0;
}
