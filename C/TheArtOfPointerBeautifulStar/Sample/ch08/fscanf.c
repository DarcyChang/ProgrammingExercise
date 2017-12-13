/*  fscanf.c  */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr;
	char id[10];
	int score;
	if((fptr = fopen("score.dat", "r")) == NULL)  {
		printf("µLªk¶}±Ò score.dat");
		exit(1);
	}
	printf("%-10s %-10s\n", "id", "score");
	printf("================\n");
	while(fscanf(fptr, "%s %d", id, &score) != EOF)
		printf("%-10s %3d\n", id, score);
	fclose(fptr);
	system("PAUSE");
	return 0;
}
