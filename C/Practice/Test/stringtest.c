#include <stdio.h>
#include <string.h>

#define NetBIOS_find "./nbtscan_find_txt"
#define NetBIOS_vh_find "./nbtscan_vh_find_txt"
#define NetBIOS_none "./nbtscan_none_txt"
#define NetBIOS_vh_none "./nbtscan_vh_nono_txt"
#define NetBIOS_err "./nbtscan_err_txt"
#define NetBIOS_vh_err "./nbtscan_vh_err_txt"


#define boujour_find "./txt"
#define boujour_none "./txt2"

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


	/* NetBIOS nbtscan test */
	 
//	rf = fopen(NetBIOS_find, "r");  // found
	rf = fopen(NetBIOS_vh_find, "r");  // vh found
//	rf = fopen(NetBIOS_none, "r");  // none find
	rf = fopen(NetBIOS_vh_none, "r");  // vh none find
//	rf = fopen(NetBIOS_err, "r");  // error for linux samba
//	rf = fopen(NetBIOS_vh_err, "r");  // vh error for linux samba


    if(rf)
    {
        while((fgets(tmp, sizeof(tmp), rf)) != NULL)
        {
        	if(strstr(tmp,"Workstation Service"))
            {
            	strcpy(hostname,strtok(tmp," "));    
                found = 1;
        		while((fgets(tmp, sizeof(tmp), rf)) != NULL)
				{
					if(strstr(tmp,"00-00-00-00-00-00")){
						found = 0;
						break;
					}
				}
				break;
            }
		} 
		if(found == 1)
		{
			printf("HostName is %s\n", hostname);
		} 
        else
			printf("NetBIOS query Failure!\n");
    } 

	/* bonjour - mDNSIdentify protocol test*/	
//	rf = fopen(boujour_find, "r");  // is correct
	rf = fopen(boujour_none, "r"); // is wrong
#if 0
	if(rf)
	{
		while((fgets(tmp, sizeof(tmp), rf)) != NULL)
        {
//			if(tmp[strlen(tmp)-1] == '\n')tmp[strlen(tmp)-1] = '\0';
                if(strstr(tmp,"ANY"))
                {
                    strcpy(hostname,strtok(strtok(tmp," ANY"),"."));	
                    printf("HostName is %s\n", hostname);
					found = 1;
                    break;
                }
		}	
		if(found == 0)printf("Bonjour query Failure!\n");
	}	
#endif
	return 0;
}

