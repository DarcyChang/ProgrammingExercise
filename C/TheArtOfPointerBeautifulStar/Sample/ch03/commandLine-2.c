/* commandLine-2.c */
#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[])
{
	if (argc == 2) {
		switch(*(argv[1]+1)) 
        {
		   case 'd':
			   system("dir/w c:\\");
			   break;
		   case 't':
			   system("type c:\\commandLine.c");
               break;
		   default:
			   printf("Using commandLine -d or -t");
		}
	}
	else
        printf("Using commandLine -d or -t");
	printf("\n");
	getch();
	return 0;
}
