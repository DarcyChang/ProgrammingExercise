/* string4.c */
#include <stdio.h>
#include <conio.h> 
int main()
{
	char *str = "Apple iPod";
    int i; 
 	printf("¦r¦êstr¬°: ");
    for(i=0; str[i]!='\0'; i++)
       printf("%c", str[i]);
    getch();
	return 0;
}
