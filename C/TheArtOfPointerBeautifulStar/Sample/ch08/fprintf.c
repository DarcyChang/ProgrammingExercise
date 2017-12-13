/*  fprintf.c  */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char id[10];
	int score;
	FILE *fptr;
	if((fptr = fopen("score.dat", "w")) == NULL)  {
		printf("�L�k�}�� score.dat");
		exit(1);
	}
	/* �Q�Τ��w�ưj��A��id �M score �� -1 �P -1 �ɪ�ܵ��� */ 
	printf("�п�J id �P score (��J -1 -1 ����):\n");
    do  {
	    printf("�п�J id: ");
		scanf("%s", id);
		printf("�п�J score: ");
		scanf("%d", &score);
		printf("\n");
		if(strcmp(id, "-1") != 0 && score != -1)
			fprintf(fptr, "%s %d\n", id, score);
	} while(strcmp(id, "-1") != 0 && score != -1);
 
	fclose(fptr);
	system("PAUSE");
	return 0;
}
