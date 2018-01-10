/* file name: allpair.c */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_V 10   /*最大節點數*/
#define Infinite 1073741823

long int A[MAX_V+1][MAX_V+1];
long int D[MAX_V+1][MAX_V+1];
long int Origin[MAX_V+1][MAX_V+1];
int N;
int first = 1;

void init();
void Output();
void Changed(int num);
void AllPairLength(int N);

void main()
{
	init();
	AllPairLength(N);
}

void init()
{
	FILE *fptr;
	int i,j;
	long int weight;

	fptr = fopen("allpair.dat","r");
	if ( fptr == NULL )
	{
		perror("allpair.dat");
		exit(1);
	}

	fscanf(fptr,"%d",&N);       /*讀取圖形節點數*/
	for ( i=1; i<=N; i++ )
		for ( j=1; j<=N; j++ )
			A[i][j] = Infinite;  /*起始A[1..N][1..N]相鄰矩陣*/
 
	while ( fscanf(fptr,"%d %d %ld",&i,&j,&weight) != EOF )
	A[i][j] = weight;      /*讀取i節點到j節點的權weight */
	fclose(fptr);

	for ( i = 1; i <= N; i++){
		for ( j = 1; j <= N; j++ ){
			D[i][j] = A[i][j]; /*記錄起始頂點至各頂點最短距離*/
		}
	D[i][i] = 0;
	}
	printf("If the distance is changed,\nit will have '*' symbol !!\n");
	printf("    A#%i",0);
	Output();

}

void AllPairLength(int N)
{
	int i, j, k;
	first = 0;
		
	for(k=1; k<=N; k++){
		for(i=1; i<=N; i++){
			for(j=1; j<=N; j++){
				if ((D[i][k] + D[k][j]) < D[i][j]){
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	printf("\n    A#%i",k);
	Changed(k);
	Output();
	}
}

void Output()
{
	int i=0,j=0;

	printf("\n");
	for ( i=1 ; i<=N ; i++)
		printf("=======");
	printf("\n");

	printf("    j");
	for ( i=1; i<=N; i++ )
		printf("%4ld",i);
	printf("\n");
	for ( i=1 ; i<=N ; i++)
		printf("-------");
	printf("\n");

	for ( i =1; i<=N ; i++){
		if (i == (1+N)/2)
			printf("i");
		else
			printf(" ");
		printf("%4ld",i);

		for ( j=1; j<=N; j++ )
			if ( D[i][j] == Infinite )
				printf("  ∞");
			else{
				if (Origin[i][j] != D[i][j] && first != 1)
					printf("  *%d",D[i][j]);
				else
					printf("%4ld",D[i][j]);
			}
		printf("\n");
	}
	for ( i=1 ; i<=N ; i++)
		printf("=======");
	printf("\n");
	getch();
}

void Changed(int num)
{
	int i,j,k;
	switch(num){
	case 1:
		for ( i = 1; i <= N; i++){
			for ( j = 1; j <= N; j++ ){
				Origin[i][j] = A[i][j]; /*記錄起始頂點至各頂點最短距離*/
			}
		Origin[i][i] = 0;
		}
		break;
	default:
		for(k=num-1; k<=num-1 ; k++){
			for(i=1; i<=N; i++){
				for(j=1; j<=N; j++){
					if ((Origin[i][k] + Origin[k][j]) < Origin[i][j])
						Origin[i][j] = Origin[i][k] + Origin[k][j];
				}
			}
		}
		break;
	}
}