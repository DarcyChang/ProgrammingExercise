/* fwrite.c */
#include <stdio.h>
#include <conio.h>

int main()
{
	struct node  {
		char name[10];
		int score;
	};
	struct node student;
	FILE *fptr;
	char scorebuf[81];
	if((fptr = fopen("student.rec", "wb")) == NULL)  {
		printf("µLªk¶}±Ò student.rec");
		exit(1);
	}
	do  {
		printf("\n\nEnter name: ");
		gets(student.name);
		printf("Enter score: ");
		student.score = atoi(gets(scorebuf));
		fwrite(&student, sizeof(student), 1, fptr);
		printf("One more(y/n)? ");
	} while(getche() == 'y');
	fclose(fptr);
    getch();
	return 0;
}
