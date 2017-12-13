/*  fgetpos-2.c  */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
	FILE *fptr;
	fpos_t curpos;
	char buffer1[81], buffer2[81], buffer3[3];
	if ((fptr = fopen("bufferArea.dat", "r")) == NULL){
        printf("檔案無法開啟\n");
        system("PAUSE");
        exit(1);
    }
    if(fgetpos(fptr, &curpos) != 0)
       perror("fgetpos 失敗\n");
    printf("curpos 目前指向的位址是: %d\n", curpos);
    printf("fptr 目前指向的位址是: %d\n\n", ftell(fptr)); 
    
    fgets(buffer1, 10, fptr); 
    printf("curpos 目前指向的位址是: %d\n", curpos);  
    printf("fptr 目前指向的位址是: %d\n", ftell(fptr));
    printf("Buffer1: %s\n\n", buffer1);
    
    fgets(buffer2, 8, fptr); 
    printf("curpos 目前指向的位址是: %d\n", curpos);   
    printf("fptr 目前指向的位址是: %d\n", ftell(fptr));
    printf("Buffer2: %s\n\n", buffer2);
     
    printf("Reset fptr 指標: \n");
    if(fsetpos(fptr, &curpos) != 0)
       perror("fsetpos 失敗\n"); 
    printf("curpos 目前指向的位址是: %d\n", curpos);   
    printf("fptr 目前指向的位址是: %d\n\n", ftell(fptr));
    fgets(buffer3, 27, fptr);  
    printf("讀取27字元後....\n");   
    printf("curpos 目前指向的位址是: %d\n", curpos);   
    printf("fptr 目前指向的位址是: %d\n", ftell(fptr));
    printf("Buffer3: %s\n\n", buffer3);
            
	fclose(fptr);
    system("PAUSE");
	return 0;
}
