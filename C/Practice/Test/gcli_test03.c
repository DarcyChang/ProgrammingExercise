#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PDATA_TX_PORT_LIST_BUF_SIZE 10
#define PDATA_RX_PORT_LIST_BUF_SIZE 10

typedef struct pdata {
    int enable;
    int tx_dest;
    int rx_dest;
    char tx_port_list[PDATA_TX_PORT_LIST_BUF_SIZE];
    char rx_port_list[PDATA_RX_PORT_LIST_BUF_SIZE];
}PDATA_T,*PDATA_P;

int internal_set_interface_gigaethernet_port_mirror_tx_port_list(char *);
int main()
{

	printf("here is 01\n");
	char a[]="101111111";
	char *str1=a;
	char **str=&str1;
/*	
	printf("a[] address = %p\n", a);
	printf("str1 address = %p\n", str1);	
	printf("*str1 = %s\n", str1);
	printf("*str = %s\n", *str);
	
   char tx_tmp[20];
	char rx_tmp[10];
    int i;
    memset(tx_tmp, 0, sizeof(tx_tmp));
    memset(rx_tmp, 0, sizeof(rx_tmp));
for (i = 1; i < 9; i++) {

     strcpy(tx_tmp,"hello world");
        printf("tx_tmp = %s\n",tx_tmp);

}

*/
	internal_set_interface_gigaethernet_port_mirror_tx_port_list(*str);

	return 0;
}//end main

int internal_set_interface_gigaethernet_port_mirror_tx_port_list(char *value)
{
	printf("here is 02\n");
	PDATA_P p;
    p = (struct pdata*)malloc(sizeof(struct pdata))	;	
	printf("*value = %s\n", value);
	sprintf(p->tx_port_list, "%s", value);
	printf("p->tx_port_list = %s\n", p->tx_port_list);
	int i;
	for(i=0;i<sizeof(p->tx_port_list);i++)
	{
	//	if(p->tx_port_list[i] == '0')
	//		printf("p->tx_port_list[%d] = %s\n",i ,p->tx_port_list);
	}
	char tx_tmp[10];
    
    memset(tx_tmp, 0, sizeof(tx_tmp));
	for (i = 1; i <= 9; i++) {
	//	*tx_tmp=p->tx_port_list[i-1];
    // 	strcpy(tx_tmp,p->tx_port_list);
    //    strcpy(tx_tmp,"0");
			
		//strcat(p->tx_port_list+(i-1),"0");
		printf("p->tx_port_list= %s\n", p->tx_port_list);
		char tmp[10];
    	memset(tmp, 0, sizeof(tmp));
		strcpy(tmp,p->tx_port_list);
		//sprintf(tmp,"1234");
		printf("tmp = %s\n",tmp);
		tmp[5]='0';
		strcpy(p->tx_port_list,tmp);
		printf("p->tx_port_list= %s\n", p->tx_port_list);
//		printf("tx_tmp = %s\n",tx_tmp);
	}
	printf("len = %d\n",strlen(p->tx_port_list));
}
