#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_V 100  /*最大節點數*/
#define TRUE 1
#define FALSE 0

typedef struct {
	int vertex1;
	int vertex2;
	int weight;
	int edge_deleted;
} Edge;

typedef struct {
	int vertex[MAX_V];
	int edges;
} Graph;

Edge E[MAX_V];
Graph T;

int total_vertex;
int total_edge;
int adjmatrix[MAX_V][MAX_V];  /*store matrix weight*/

void kruskal();
void addEdge(Edge );
void build_adjmatrix();
Edge mincostEdge();
int cyclicT(Edge e);
void showEdge();

void main()
{
	Edge e;
	int i , j ,weight;

	build_adjmatrix();

	for (i = 1; i <= total_vertex; i++)
		for ( j = i+1; j <= total_vertex; j++ )
		{
			weight = adjmatrix[i][j];
			if ( weight != 0 )
			{
				e.vertex1 = i;
				e.vertex2 = j;
				e.weight = weight;
				e.edge_deleted = FALSE;
				addEdge(e);
			}
		}

	showEdge();
	/*init T*/
	for ( i = 1; i <= total_vertex; i++ )
		T.vertex[i] = 0;
	T.edges = 0;

	puts("\nMinimum cost spanning tree using Kruskal");
	puts("-------------------------------------------");
	kruskal();
}

void build_adjmatrix()
{
	FILE *fptr;
	int vi,vj;

	fptr = fopen("kruskal.dat","r");
	if ( fptr == NULL )
	{
		perror("kruskal.dat");
		exit(0);
	}

	/*讀取節點總數*/
	fscanf(fptr,"%d",&total_vertex);

	for (vi = 1; vi <= total_vertex; vi++)
		for ( vj = 1; vj <= total_vertex; vj++ )
			fscanf(fptr,"%d",&adjmatrix[vi][vj]);

	fclose(fptr);
}

void addEdge( Edge e)
{
	E[++total_edge] = e;
}

void showEdge()
{
	int  i = 1;

	printf("total vertex = %d  ",total_vertex);
	printf("total_edge = %d\n",total_edge);
	while ( i <= total_edge )
	{
		printf("V%d  <----->  V%d   weight= %d\n",E[i].vertex1,
				E[i].vertex2,E[i].weight);
		i++;
	}
}

Edge mincostEdge()
{
	int i , min;
	long minweight = 10000000;

	for ( i = 1; i <= total_edge; i++ )
	{
		if (!E[i].edge_deleted && E[i].weight < minweight)
		{
			minweight = E[i].weight;
			min = i;
		}
	}
	E[min].edge_deleted = TRUE;
	return E[min];
}


void kruskal()
{
	Edge e;
	int loop = 1;

	while ( T.edges != total_vertex - 1  )
	{
		e = mincostEdge();

		if ( !cyclicT(e) )
		{
			printf("%dth min edge : ",loop++);
			printf("V%d  <----->  V%d  weight= %d\n",
					e.vertex1, e.vertex2,e.weight);
		}
	}
}

int cyclicT(Edge e)
{
	int v1 = e.vertex1;
	int v2 = e.vertex2;

	T.vertex[v1]++;
	T.vertex[v2]++;
	T.edges++;

	if ( T.vertex[v1] >= 2 && T.vertex[v2] >= 2 )
	{
		if(v2 == 2)
			return FALSE;
		T.vertex[v1]--;
		T.vertex[v2]--;
		T.edges--;
		return TRUE;
	}
	else
		return FALSE;
}