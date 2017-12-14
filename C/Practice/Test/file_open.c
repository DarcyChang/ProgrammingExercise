#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void write(void)
{
    FILE* rf;
	char tmp[] = "5";
	float tmp2 = atof(tmp);
	int var;
	printf("tmp = %f\n", atof(tmp));
	printf("tmp2 = %f\n", tmp2);
	rf = fopen("./timeout_set1","w");
	fprintf(rf,"%d",tmp2 *60*60);
	fclose(rf);
	rf = fopen("./timeout_set1","r");
	fscanf(rf,"%d",&var);
	printf("var = %d\n",var);
//        printf("NULL");

	
}

int main(void)
{
	
	FILE* rf;
	char ip[64]="./10.5.1.65";
//	char tmp[100] = {"100"};
//	if(rf = fopen("./timeout_set","r"))
	if(rf = fopen(ip,"r")){
		write();
//		printf("tmp = %d\n",atoi(tmp));	
	}
//	fclose(rf);
	printf("\n");
	return 0;
}
