#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

void sigroutine(int signo){
    switch (signo){
        case SIGALRM:
                printf("Catch a signal -- SIGALRM \n");
				printf("TEST signo = %d\n");
//                signal(SIGALRM, sigroutine);
                break;
        case SIGVTALRM:
                printf("Catch a signal -- SIGVTALRM \n");
				printf("TEST signo = %d\n");
//                signal(SIGVTALRM, sigroutine);
                break;
	}
	return;
}
void test(int signo)
{
	printf("TEST %d\n",signo);
	return ;
}

int main()
{
   struct itimerval value, ovalue, value2; //(1)
   printf("process id is %d\n", getpid());
   signal(SIGALRM, sigroutine);
   signal(SIGVTALRM, sigroutine);
   value.it_value.tv_sec = 1;
   value.it_value.tv_usec = 0;
   value.it_interval.tv_sec = 1;
   value.it_interval.tv_usec = 0;
//   setitimer(ITIMER_REAL, &value, &ovalue); //(2)
   value2.it_value.tv_sec = 6;
   value2.it_value.tv_usec = 0;
   value2.it_interval.tv_sec = 6;
   value2.it_interval.tv_usec = 0;
	test(1);
//	setitimer(ITIMER_VIRTUAL, &value2, &ovalue);
//	for(;;)
//	;
	while(1)
	;
//		pause(); // this code only do one timer
}


