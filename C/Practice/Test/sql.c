#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void)
{
	time_t timep;
	time(&timep);
	printf("%s",ctime(&timep));

	return 0;
}
