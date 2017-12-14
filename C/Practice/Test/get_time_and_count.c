#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void)
{
	int seconds=time((time_t*)NULL);	
	printf("%d\n",seconds);
/*
	time_t timep;
	strcut tm *p;
	time(&timep);
	printf(“time() : %d \n”,timep);
	p=localtime(&timep);
	timep = mktime(p);
	printf(“time()->localtime()->mktime():%d\n”,timep);
*/

	time_t timep;
	time(&timep);
	printf("%s",ctime(&timep));
	sleep(10);	
	int old=time(&timep);	
	printf("%d\n",old);

	int new=time((time_t*)NULL);	
	printf("%d\n",new);
	printf("new %d - old %d = %d\n",new,old,new-old);

	printf("\n");
	return 0;
}
