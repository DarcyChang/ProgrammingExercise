#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//#include <gtk_shiner_log.h>
//#define DNS_RESULT  "/tmp/hostnamelookup_result" 


void print_usage(char *program)
{
    fprintf(stderr, "Usage: ");
    fprintf(stderr, "%s [options] \n\n", program);
    fprintf(stderr, " options :\n");
    fprintf(stderr, "  add <ip address>\n");
    fprintf(stderr, "  del <ip address>\n");
    fprintf(stderr, "  list\n");
    fprintf(stderr, "  delall\n");
    fprintf(stderr, "  -h help\n");
    fprintf(stderr, "\n");
}

/*
int host(int argc, char** argv)
{
    if(argc < 3){
        print_usage(argv[0]);
        exit(0);
    }

    char* const opt = argv[1];
printf(" opt = %s\n",opt[1]);
printf(" opt = %c\n",opt[1]);
      
    switch (opt[1])
    {
        case 'a':   //add ip address      
                printf("this is add\n");
                break;
        case 'd':   //del ip address
                printf("this is del\n");
                break;
        case 'l':   //list all from database
                printf("this is list\n");
                break;
        case 'o':   //del_all 
                printf("this is del all\n");
                break;

        default:
                print_usage(argv[0]);
                exit(0);
                break;
    }
    return 0;
}
*/
void test(char *ip)
{
	printf("ip is %s\n",ip);
}

int main(int argc, char ** argv)
{
    int i;
    for (i=0; i < argc; i++)
    { 
	   printf("Argument %d is %s.\n", i, argv[i]);
		test(argv[i]);
	}
    return 0;
}
