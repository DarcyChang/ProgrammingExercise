#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>
#include <signal.h>

int daemon_init(void)
{ 
	pid_t pid;
	if((pid = fork()) < 0) 
		return(-1);
	else if(pid != 0) 
		exit(0);

	setsid();
	chdir("/");
	umask(0);
	close(0);
	close(1);
	close(2);
	return(0); 
}

void sig_term(int signo)
{ 
	if(signo == SIGTERM)
	{ 
		syslog(LOG_INFO, "program terminated.");
		closelog(); 
		exit(0); 
	}
}

int main(void)
{ 
	if(daemon_init() == -1){
		printf("can't fork self\n"); 
		exit(0);
	} 
	openlog("daemontest", LOG_PID, LOG_USER);
	syslog(LOG_INFO, "program started.");
	signal(SIGTERM, sig_term);
	while(1) 
		sleep(1); 
	return(0); 
}
