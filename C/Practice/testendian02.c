/* What endian on your system.*/

#include <stdio.h>

int main(int argc, char* argv[]) {
	/* 
		0123 is big endian
		3210 is little endian
	*/
	int n = 256*256+2*256+3;
	unsigned char *c;
    
	printf("\nn = %d\n", n);
	c = (unsigned char*) (void*) &n;
	printf("n is allocated at\n%11u\t%11u\t%11u\t%11u\n", c, c+1, c+2, c+3);
	printf("%11u\t", *c++);
	printf("%11u\t", *c++);
	printf("%11u\t", *c++);
	printf("%11u\n", *c++);


	return 0; 
}

