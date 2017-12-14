#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEIGHT 4	
#define WIDTH 3
struct ABC {
	char a[12];
	char b[12];
	char c[12];
};

int instead(struct ABC *result)
{
	strcpy(result->a, result->b);
	return 0;
}

void pic(int buffer[][WIDTH], int h, int w)
{
	int i,j; 
	for(i=0; i<h; i++)
	    for(j=0; j<w; j++)
		buffer[i][j] = i+j;

}

int main()
{
	int buffer[HEIGHT][WIDTH] = {0};	
	int i, j;

	pic(buffer, HEIGHT, WIDTH);
	
	for(i=0; i<HEIGHT; i++)
	{
	    for(j=0; j<WIDTH; j++)
		printf("%d\t", buffer[i][j]);
	    printf("\n");
	}

	return 0;
}
