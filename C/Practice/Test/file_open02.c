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
#if 0
    if(rf = fopen(HOSTNAME_REPEAT_IP,"r")){
        fscanf(rf,"%s",tmp);  
        fclose(rf);
        if(0 == strcmp(tmp,ip)){       
            printf("Input IP repeat with last request IP ");
            return;
        }else{
            rf = fopen(HOSTNAME_REPEAT_IP,"w"); 
            fprintf(rf,"%s",ip);           
            fclose(rf);
        }
    }else if(rf = fopen(HOSTNAME_REPEAT_IP,"w")){
        fprintf(rf,"%s",ip);  
        fclose(rf);
    }  
#endif
int main(void)
{
	
	FILE* rf;
	char tmp[64]="";
	char ip[64]="";
	int i=0;
	char newip[64]="";
	printf("please insert an IP:");
	scanf("%s",newip);

	if(rf = fopen("./insertip","r")){
		while(i <= 5 && fgets(tmp, sizeof(tmp), rf)!= NULL){
	        if(0 == strcmp(tmp,newip)){       
            	printf("Input IP repeat with last request IP ");
				fclose(rf);
            	return;
        	}
			i++;
		}	
//		fputs(NULL,rf);	
		fclose(rf);
        rf = fopen("./insertip","a"); 
        fprintf(rf,"%s",newip);           
        fclose(rf);
    }else if(rf = fopen("./insertip","w")){
        fprintf(rf,"%s",newip);  
        fclose(rf);
    }  
//	fclose(rf);
	printf("\n");
	return 0;
}
