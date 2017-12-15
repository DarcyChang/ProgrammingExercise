/* What endian on your system.*/

#include <stdio.h>

typedef union 
{ 
	long l; 
	unsigned char c[4]; 
} EndianTest; 

int main(int argc, char* argv[]) {
	EndianTest a;
	a.l=0x12345678;
	int i=0;
	
	if(a.c[0]==0x78 && a.c[1]==0x56 && a.c[2]==0x34 && a.c[3]==0x12) 
	{
		printf("This system is 'Little Endian'.\n"); 
	}
	else if(a.c[0]==0x12 && a.c[1]==0x34 && a.c[2]==0x56 && a.c[3]==0x78) 
	{
		printf("This system is 'Big Endian'.\n"); 
	} 
	else
	{
		printf("This system is 'Unknown Endian'.\n"); 
	} 
	
	printf("for a long variable value is 0x%lX\n",a.l);
	printf("and its storage order in memory :\n");
	
	for(i=0;i<4;i++) 
		printf("%p : 0x%02X\n",&a.c[i],a.c[i]);  

	// getchar(); // wait for a key ..。  
	return 0; 
}

