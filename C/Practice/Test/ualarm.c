#define _XOPEN_SOURCE 500     /* Or: #define _BSD_SOURCE */
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    sigset_t block;

    sigemptyset(&block);
    sigaddset(&block, SIGALRM);
    sigprocmask(SIG_BLOCK, &block, NULL);

    ualarm(500000, 500000);
    while (1) {
        printf("%d\n", time(NULL));
        sigwaitinfo(&block, NULL);
    }

    return 0;
}
