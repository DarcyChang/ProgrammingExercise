/*  fgetpos-1.c  */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
	FILE *fptr;
	fpos_t curpos;
	char buffer1[81], buffer2[81];
	if ((fptr = fopen("bufferArea.dat", "r")) == NULL){
        printf("檔案無法開啟\n");
        system("PAUSE");
        exit(1);
    }
    if(fgetpos(fptr, &curpos) != 0)
       perror("fgetpos 失敗\n");
    fgets(buffer1, 27, fptr);
    if(fsetpos(fptr, &curpos) != 0)
       perror("fsetpos 失敗\n"); 
    fgets(buffer2, 27, fptr);  
    
    printf("以下是buffer1和buffer2緩衝區的資料:\n");
    printf("Buffer1: %s\n", buffer1);
    printf("Buffer2: %s\n", buffer2);        
	fclose(fptr);
    system("PAUSE");
	return 0;
}
