/* darcy */
/* check ipv4 format */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
 
int main()
{
        char str[]="255.255.255.255.1";
//        in_addr_t r1,r2,r3;
        struct in_addr inp;
		int r3,buf;
#if 0
        r1=inet_addr(str);
        if(r1==-1){
                printf("inet_addr return -1 when 255.255.255.255\n");
        }else{
                printf("inet_addr:ip=%lu\n",ntohl(r1));
        }
        r2=inet_network(str);
        if(r2==-1){
                printf("inet_network return -1 when 255.255.255.255\n");
        }else{
                printf("inet_network:ip=%lu\n",r2);
        }
#endif
        r3=inet_aton(str,&inp);
        if(r3==0){
                printf("inet_aton return -1 when 255.255.255.255\n");
        }else if(sscanf(str, "%d.%d.%d.%d", &buf, &buf, &buf, &buf) != 4){
				printf("error\n");
		}else{
                printf("inet_aton:ip=%lu\n",ntohl(inp.s_addr));
        }
        return 0;
}

