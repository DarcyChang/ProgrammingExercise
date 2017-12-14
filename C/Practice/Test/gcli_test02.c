#include <stdio.h>
#include <string.h>

int main(){

	int a=1;
	char tmp[10];
	char target[10];
	
	memset(tmp, 0, sizeof(tmp));
	memset(target, 0, sizeof(target));
	
	for(a=1;a<10;a++)
	{
		sprintf(tmp, "%d", a);
    	printf("tmp = %s\n", tmp);
    	strcat(target, tmp);	
	//sprintf(target, "%d", tmp[0]);
	//	target[a]=a;
	}
	//strcat(target);
	printf("target = %s\n", target);

	return 0;

}
