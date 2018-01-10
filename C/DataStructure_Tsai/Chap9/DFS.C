/* 圖形的追蹤: 相鄰串列與蹤向優先搜尋法(DFS)*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_V 100  /*最大節點數*/
#define TRUE 1
#define FALSE 0

/*定義資料結構*/
typedef struct node_tag {
	int vertex;
	struct node_tag *link;
} Node;

Node *adjlist[MAX_V+1];  /*宣告相鄰串列*/
int visited[MAX_V+1];  /*記錄頂點是否已拜訪*/
int total_vertex;


void build_adjlist();
void show_adjlist();
void dfs(int);
Node *searchlast(Node *);

void main()
{
	build_adjlist(); /*以相鄰串列表示圖形*/
	show_adjlist();  /*顯示串列之資料*/
	puts("\n------Depth Fisrt Search------");
	dfs(1);     /*圖形之蹤向優先搜尋，以頂點1為啟始頂點*/
}

void build_adjlist()
{
	FILE *fptr;
	Node *node,*lastnode;
	int vi,vj ,weight;

	fptr = fopen("dfs.dat","r");
	if ( fptr == NULL )
	{
		perror("dfs.dat");
		exit(0);
	}

	/*讀取節點總數*/
	fscanf(fptr,"%d",&total_vertex);
	for ( vi = 1; vi <= total_vertex; vi++)
	{
		/*設定陣列及各串列啟始值*/
		visited[vi] = FALSE;
		adjlist[vi] = (Node *)malloc(sizeof(Node));
		adjlist[vi]->vertex = vi;
		adjlist[vi]->link = NULL;
	}

	/*讀取節點資料*/
	for ( vi = 1; vi <= total_vertex; vi++ )
		for ( vj = 1; vj <= total_vertex; vj++ )
		{
			fscanf(fptr,"%d",&weight);
			/* 資料檔以相鄰矩陣格式儲存,以1代表相鄰
			   0 代表不相鄰，將相鄰頂點鏈結在各串列後 */
			if ( weight != 0 )
			{
				node = (Node *)malloc(sizeof(Node));
				node->vertex = vj;
				node->link = NULL;
				lastnode = searchlast(adjlist[vi]);
				lastnode->link = node;
			}
		}
	fclose(fptr);
}

/*顯示各相鄰串列之資料*/
void show_adjlist()
{
	int index;
	Node *ptr;

	puts("Head    adjacency nodes");
	puts("------------------------------");
	for (index = 1; index <= total_vertex; index++)
	{
		printf("V%-2d ",adjlist[index]->vertex);
		ptr = adjlist[index]->link;
		while ( ptr != NULL )
		{
			printf("--> V%d ",ptr->vertex);
			ptr = ptr->link;
		}
		printf("\n");
	}
}

/*圖形之蹤向優先搜尋*/
void dfs(int v)
{
	Node *ptr;
	int w;

	printf("V%d ",adjlist[v]->vertex);
	visited[v] = TRUE;          /*設定v頂點為已拜訪過*/
	ptr = adjlist[v]->link;     /*拜訪相鄰頂點*/

	do
	{
		/* 若頂點尚未走訪，則以此頂點為新啟始點繼續
		   做蹤向優先搜尋法走訪，否則找與其相鄰的頂點
		   直到所有相連接的節點都已走訪          */
		w = ptr->vertex;
		if ( !visited[w] )
			dfs(w);
		else
			ptr = ptr->link;
	} while ( ptr != NULL);
}

/*搜尋串列最後節點函數*/
Node *searchlast( Node *linklist )
{
	Node *ptr;

	ptr = linklist;
	while ( ptr->link != NULL ) ptr = ptr->link;
	return ptr;
}

