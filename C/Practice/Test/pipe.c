#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>


static int popen_exec(char *cmd)
{   
    FILE *pp;
    int ret3 = 2;
    int ret = 100;
    int ret2 = 1;
//    char buffer[100]="";
//    printf("cmd = %s\n",cmd);

    if((pp = popen(cmd, "r")) == NULL) {
        printf("`%s' error!\n", cmd);
    } else {
//	    fgets(buffer,sizeof(buffer),pp);
        fscanf(pp, "%d", &ret3);
        fscanf(pp, "%d", &ret);
        fscanf(pp, "%d", &ret2);
        fclose(pp);
    }
	
//	int ii=0;
//    printf("buffer = ");
//    for(ii=0;ii<100;ii++)
//        printf("%c",buffer[ii]);
    
	printf("\nret3 = %d\n",ret3);
    printf("ret = %d\n",ret);
    printf("ret2 = %d\n",ret2);
    
	return ret;
}
int main()
{
	int linkStatus=10;
	char cmd[100]="";
	sprintf(cmd, "cat ~/1.txt");
	linkStatus = popen_exec(cmd);
	printf("linkStatus = %d\n",linkStatus);
}
