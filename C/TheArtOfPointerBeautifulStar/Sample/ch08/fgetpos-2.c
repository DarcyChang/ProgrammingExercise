/*  fgetpos-2.c  */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
	FILE *fptr;
	fpos_t curpos;
	char buffer1[81], buffer2[81], buffer3[3];
	if ((fptr = fopen("bufferArea.dat", "r")) == NULL){
        printf("�ɮ׵L�k�}��\n");
        system("PAUSE");
        exit(1);
    }
    if(fgetpos(fptr, &curpos) != 0)
       perror("fgetpos ����\n");
    printf("curpos �ثe���V����}�O: %d\n", curpos);
    printf("fptr �ثe���V����}�O: %d\n\n", ftell(fptr)); 
    
    fgets(buffer1, 10, fptr); 
    printf("curpos �ثe���V����}�O: %d\n", curpos);  
    printf("fptr �ثe���V����}�O: %d\n", ftell(fptr));
    printf("Buffer1: %s\n\n", buffer1);
    
    fgets(buffer2, 8, fptr); 
    printf("curpos �ثe���V����}�O: %d\n", curpos);   
    printf("fptr �ثe���V����}�O: %d\n", ftell(fptr));
    printf("Buffer2: %s\n\n", buffer2);
     
    printf("Reset fptr ����: \n");
    if(fsetpos(fptr, &curpos) != 0)
       perror("fsetpos ����\n"); 
    printf("curpos �ثe���V����}�O: %d\n", curpos);   
    printf("fptr �ثe���V����}�O: %d\n\n", ftell(fptr));
    fgets(buffer3, 27, fptr);  
    printf("Ū��27�r����....\n");   
    printf("curpos �ثe���V����}�O: %d\n", curpos);   
    printf("fptr �ثe���V����}�O: %d\n", ftell(fptr));
    printf("Buffer3: %s\n\n", buffer3);
            
	fclose(fptr);
    system("PAUSE");
	return 0;
}
