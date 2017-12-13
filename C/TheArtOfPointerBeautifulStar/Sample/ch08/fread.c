/*  fread.c  */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct node  {
		char name[10];
		int score;
	};
	struct node student;
	FILE *fptr;
	if((fptr = fopen("student.rec", "rb")) == NULL)  {
		printf("µLªk¶}±Ò student.rec");
		system("PAUSE");
		exit(1);
	}
	printf("%-10s %-10s\n", "name", "score");
	printf("================\n");
	while(fread(&student, sizeof(student), 1, fptr) == 1)
		printf("%-10s %3d\n", student.name, student.score);
	fclose(fptr);
	system("PAUSE");
	return 0;
}
