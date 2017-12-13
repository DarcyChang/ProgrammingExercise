/* string10.c */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *str1 = "Learning pointer now!";
	char str2[] = "Go ahead";
	char *str3;
	char str4[20];

    str3 = "I want to buy a iPod\n";
	printf("c or C++: ");
	scanf("%s", str4);

	printf("\n%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	printf("Learning %s now\n", str4);
	system("PAUSE");
	return 0;
}
