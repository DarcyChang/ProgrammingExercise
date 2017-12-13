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
		printf("無法開啟 score.dat");
		exit(1);
	}
	/* 利用不定數迴圈，當id 和 score 為 -1 與 -1 時表示結束 */ 
	printf("請輸入 id 與 score (輸入 -1 -1 結束):\n");
    do  {
	    printf("請輸入 id: ");
		scanf("%s", id);
		printf("請輸入 score: ");
		scanf("%d", &score);
		printf("\n");
		if(strcmp(id, "-1") != 0 && score != -1)
			fprintf(fptr, "%s %d\n", id, score);
	} while(strcmp(id, "-1") != 0 && score != -1);
 
	fclose(fptr);
	system("PAUSE");
	return 0;
}
