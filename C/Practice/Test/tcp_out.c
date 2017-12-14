/************************************************************/
/*                                                          */
/************************************************************/
//#define DEBUG

#include <termios.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifdef DEBUG
#define DBG(x, args...)	printf(x,##args)
#else
#define DBG(x, args...)
#endif

#define MAXSOCKFD		10
#define TCPServerIP		"192.168.240.1"
#define TCPServerPort	9955
#define	MODEMDEVICE		"/dev/ttyS1"
#define BAUDRATE		B57600
#define _POSIX_SOURCE	1
#define FALSE			0
#define TRUE			1

volatile int STOP=FALSE;

void signal_handler_IO(int status);
int wait_flag=TRUE;

int comfd,sockfd;
struct sockaddr_in  addr;
char	buf[256]={""};
char	sockbuf[2500]={""};
int		is_connected[MAXSOCKFD];
unsigned int count =0;
int main(int argc, char *argv[])
{
	int	res,i;
	int	fwrite=0,fread=0;

//	comfd = init_uart();
//	printf("com %d\n",comfd);
	sockfd = init_socketclient();
	printf("com %d sock %d\n",comfd,sockfd);

	while(STOP==FALSE){
		usleep(10000);

		//chk_socket(sockfd);
		sock_sendData(1000);

//		if(wait_flag == FALSE)
//		{
//			bzero(buf,sizeof(buf));
//			res = read(comfd,buf,sizeof(buf));
//			printf("got com data len %d\n",res);
//			for(i=0;i<res;i++)
//				printf("0x%.2x ",buf[i]);
//			printf("\n");
//			wait_flag = TRUE;	
//		}

	}

	return 0;
}

int	chk_socket(int _sockfd){
	int fd=0,len=0;
	int newsockfd=0;
	fd_set readfds;
	struct timeval      Timeout;
	int addr_len = sizeof(struct sockaddr_in);

	printf("_sockfd %d\n",_sockfd);

	FD_ZERO(&readfds);
	FD_SET(_sockfd,&readfds);
	for(fd=0;fd<MAXSOCKFD;fd++)
	{
		if(is_connected[fd])
			FD_SET(fd,&readfds);
	}

	Timeout.tv_usec = 60000;    //0.06s
	Timeout.tv_sec  = 2 ;

	if(select(MAXSOCKFD,&readfds,NULL,NULL,&Timeout)==0)    //  timeout, no net data in
	{

	}

	for(fd=0;fd<MAXSOCKFD;fd++)
	{
		if(FD_ISSET(fd,&readfds))
		{
			if(_sockfd == fd)        //  have new connect
			{
				if((newsockfd = accept (_sockfd,(struct sockaddr *)&addr,(socklen_t*)&addr_len))<0)
					perror("accept");
				if(newsockfd >= MAXSOCKFD)
				{
					close(newsockfd);
					printf("connect newsock %d bigger than max, close\n",newsockfd);
				}
				else
				{
					is_connected[newsockfd] = 1;
					printf("connect from %s newsock %d\n",inet_ntoa(addr.sin_addr),newsockfd);
				}
			}
			else                    //  have data from Net
			{
				printf("got data\n");
				bzero(sockbuf,sizeof(sockbuf));
				len = read(fd,sockbuf,sizeof(sockbuf));
				if(len <= 0)
				{
					printf("connect closed.\n");
					is_connected[fd]=0;
					close(fd);
				}
				else
				{
					sock_getData(len);
				}
			}
		}
	}
}

int sock_sendData(int _len)
{
	int i;
	for(i=0;i<_len;i++)
		sockbuf[i] = i;
	write(sockfd,sockbuf,_len);
	printf("socket send data len %d %d\n",_len, count);
	count++;
	return 1;
}

int sock_getData(int _len)
{
	int i;
	printf("socket got data len %d\n",_len);
	for(i=0;i<_len;i++)
		printf("0x%.2x ",sockbuf[i]);
	printf("\n");
	write(comfd,sockbuf,_len);
	return 1;
}

int init_socketclient(){
	int	tmpsock=0;
	struct sockaddr_in  serveraddr;
	int i=0;

	if ((tmpsock = socket(AF_INET,SOCK_STREAM,0))<0){
		perror("socket:");
        exit(-1);
	}
//    bzero(&addr,sizeof(addr));
//    addr.sin_family =AF_INET;
//    addr.sin_port = htons(0);//TCPServerPort);
//    addr.sin_addr.s_addr = htonl(INADDR_ANY);

//    if(bind(tmpsock,(struct sockaddr *)&addr,sizeof(addr))<0){
//		perror("bind:");
//        exit(-1);
//	}                                                                                

    bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(TCPServerPort);
	serveraddr.sin_addr.s_addr = inet_addr(TCPServerIP);
	
	if(connect(tmpsock,(struct sockaddr *)&serveraddr, sizeof(serveraddr))<0){
		perror("connect:");
        exit(-1);
	}                                                                                

	return tmpsock;

}

int init_socket(){
	int	tmpsock=0;
	int i=0;

	if ((tmpsock = socket(AF_INET,SOCK_STREAM,0))<0){
		perror("socket:");
        exit(-1);
	}
    bzero(&addr,sizeof(addr));
    addr.sin_family =AF_INET;
    addr.sin_port = htons(TCPServerPort);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
                                                                                                                                                  
    if(bind(tmpsock,(struct sockaddr *)&addr,sizeof(addr))<0){
		perror("bind:");
        exit(-1);
	}                                                                                
    if(listen(tmpsock,10)<0)
        exit(1);
    for(i=0;i<MAXSOCKFD;i++)
        is_connected[i]=0;


	return tmpsock;

}

int	init_uart(){
	int		openfd=0;
	struct termios oldtio,newtio;
	struct sigaction saio;
	sigset_t sigset;

	openfd = open(MODEMDEVICE, O_RDWR|O_NOCTTY|O_NONBLOCK);
	if(openfd < 0){
		perror(MODEMDEVICE);
		exit(-1);
	}

//	saio.sa_handler = signal_handler_IO;
//	sigemptyset(&sigset);

//	saio.sa_mask = sigset;
//	saio.sa_flags = 0;
//	saio.sa_restorer = NULL;
//	sigaction(SIGIO,&saio,NULL);

//	fcntl(openfd, F_SETOWN, getpid());
//	fcntl(openfd, F_SETFL, FASYNC);

	tcgetattr(openfd, &oldtio);
	bzero(&newtio, sizeof(newtio));

	newtio.c_cflag = BAUDRATE|CS8|CLOCAL|CREAD;
	newtio.c_iflag = IGNPAR;
	newtio.c_oflag = 0;
	//newtio.c_lflag = ICANON;

	newtio.c_cc[VMIN] = 1;
	newtio.c_cc[VTIME]= 0;

	tcflush(openfd, TCIFLUSH);
	tcsetattr(openfd, TCSANOW, &newtio);

	return openfd;
}

void signal_handler_IO(int status)
{
	printf("received SIGIO signal.\n");
	wait_flag = FALSE;
}

