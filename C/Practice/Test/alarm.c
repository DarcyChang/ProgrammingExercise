
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
int main(int argc, char *argv[])
{
    sigset_t block;

    sigemptyset(&block);
    sigaddset(&block, SIGALRM);
    sigprocmask(SIG_BLOCK, &block, NULL);
	
	int tmp=0, request = 3600;

    while (1) {
        alarm(1);
		printf("%d\n",tmp=tmp-1);
		printf("result = %d\n", tmp % request);
		if(tmp % request == 0)
        	printf("%d\n", time(NULL));
        sigwaitinfo(&block, NULL);
    }

    return 0;
}


#if 0
int main ()
{
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Current local time and date: %s", asctime (timeinfo) );

  return 0;
}

#endif
