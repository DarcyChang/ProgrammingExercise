#include <stdio.h>
#include <string.h>
#include <time.h>

#define boujour_find "./txt"
//#define boujour_find "./txt01"
#define boujour_none "./txt2"
#define boujour_err "./txt3"


int main(void)
{
    char s[100]="";
    char tmp[512]="";
    char buf[512]="";
    char delim[]="\n";
    char *tmp2="NULL";
    char hostname[512]="";
    FILE *rf;
    int found = 0;

	
    /* bonjour - mDNSIdentify protocol test */    
//	rf = fopen(boujour_find, "r");  // is correct
    rf = fopen(boujour_none, "r"); // is none find
//    rf = fopen(boujour_err, "r"); // is error
   	if(rf)
    {
    	while((fgets(tmp, sizeof(tmp), rf)) != NULL)
        {
        	if(tmp[strlen(tmp)-1] == '\n')tmp[strlen(tmp)-1] = '\0';
        	if(strstr(tmp,"ANY"))
            {
				printf("tmp = %s\n", tmp);
//				strcpy(hostname,strtok(strtok(tmp,"ANY"),"."));    
				strcpy(hostname,strtok(strtok(tmp," "),"."));    
            	printf("HostName is %s\n", hostname);
            	found = 1;
            	break;
            }
        }      
        if(found == 0)printf("Bonjour query Failure!\n");
     }   
	return 0;
}
