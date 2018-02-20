#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_V  100    /*�̤j�`�I��*/
#define MAX(x,y) (x < y ) ? y : x
#define MIN(x,y) (x > y ) ? y : x
#define empty -1

/*�۾F�`�I��Ƶ��c*/
typedef struct node_tag {
	int vertex;
	int duration;
	struct node_tag *link;
}  Node;

/*�۾F��C�Y��Ƶ��c*/
typedef struct headnode_tag {
	int count;
	Node *link;
}  HeadNode;

struct Stackstruct {
	int top;
	int item[MAX_V+1];
};

HeadNode *adjlist1[MAX_V+1];    /*�۾F��C*/
HeadNode *adjlist2[MAX_V+1];    /*�Ϭ۾F��C*/
struct Stackstruct Stack1 = { empty }; 
struct Stackstruct Stack2 = { empty };
int N;   /*���I�`��*/
/*�_�l���I,���I���I,�̦��γ̱߮ɶ�*/
int source,sink,ES[MAX_V+1],LC[MAX_V+1];
int CriticalNode[MAX_V+1] ,node_count,path_count;

void initial_ES();
void initial_LC();
void build_adjlist();
void show_adjlist(HeadNode *[]);
void Toplogical_sort( HeadNode *[],int []);
void print_steps(int [],int);
void print_critical_node();
void print_critical_path();
void print_ES_LC();
void print_path_node(Node *,int);
void Push(struct Stackstruct *,int );
int  Pop(struct Stackstruct * );

void main()
{
	build_adjlist();
	show_adjlist(adjlist1);          /*��ܬ۾F��C*/
	initial_ES();                    /*�_�lES(�̦��ɶ�)*/
	Toplogical_sort(adjlist1,ES);    /*�H�ݾ�ƧǪk�D�XES*/
	initial_LC();                    /*�_�lLC(�̱߮ɶ�)*/
	show_adjlist(adjlist2);          /*��ܤϬ۾F��C*/
	Toplogical_sort(adjlist2,LC);    /*�H�ݾ�ƧǪk�D�XLC*/
	print_ES_LC();	 	     /*�C�X�̦��γ̱߮ɶ�*/
	print_critical_node();           /*�C�X�{���I*/
	print_critical_path();           /*�C�X�{���|*/
}

void build_adjlist()
{
	FILE *fptr;
	int vi,vj,w;
	Node *node;

	fptr = fopen("critical.dat","r");
	if ( fptr == NULL )
	{
		perror("critical.dat");
		exit(1);
	}

	fscanf(fptr,"%d",&N);
	/*�_�l�۾F��C,count���e��̪��ƥ� */
	for ( vi = 1; vi <= N; vi++)
	{
		adjlist1[vi] = (HeadNode *)malloc(sizeof(HeadNode));
		adjlist2[vi] = (HeadNode *)malloc(sizeof(HeadNode));
		adjlist1[vi]->count = 0;
		adjlist2[vi]->count = 0;
		adjlist1[vi]->link = NULL;
		adjlist2[vi]->link = NULL;
	}

	/* Ū��vi��vj���vw(duration)�æ�ܬ۾F��C�ΤϬ۾F��C */
	while( fscanf(fptr,"%d %d %d",&vi,&vj,&w) !=EOF)
	{
		node = (Node *)malloc(sizeof(Node));
		node->vertex = vj;
		node->duration = w;
		node->link = adjlist1[vi]->link;
		adjlist1[vi]->link = node;
		adjlist1[vj]->count++;      /*�e��̼ƥ[1*/
		node = (Node *)malloc(sizeof(Node));
		node->vertex = vi;
		node->duration = w;
		node->link = adjlist2[vj]->link;
		adjlist2[vj]->link = node;
		adjlist2[vi]->count++;      /*�e��̼ƥ[1*/
	}
	fclose(fptr);

	/*��X�}�l���I*/
	for (vi =1; vi <= N; vi++ )
		if ( adjlist1[vi]->count == 0 )
		{
			source = vi;
			break;
		}
	/*��X�������I*/
	for ( vi = 1;vi <= N; vi++ )
		if ( adjlist1[vi]->link == NULL )
		{
			sink = vi;
			break;
		}
}

/*��ܬ۾F��C���*/
void show_adjlist(HeadNode *adjlist[])
{
	int v;
	Node *ptr;

	/*�P�_���۾F��Cadjlist1�ΤϬ۾F��Cadjlist2*/
	if ( adjlist == adjlist1)
		puts("\nThe adjacency lists [adjlist1] of the Graph");
	else
		puts("\n\nThe inverse adjaccny list [adjlist2] of the Graph");
	puts("Headnodes    adjacency nodes");
	puts("  /count        /duration   ");
	puts("------------------------------");
	for (v = 1; v <= N; v++)
	{
		printf("V%d: %d",v,adjlist[v]->count);
		ptr = adjlist[v]->link;
		while ( ptr != NULL )
		{
			printf(" --> V%d(%d)",ptr->vertex,ptr->duration);
			ptr = ptr->link;
		}
		printf("\n");
	}
}

/*�H�ݾ�ƧǪk�p��̦��ɶ�(ES)�γ̱߮ɶ�(LC)*/
void Toplogical_sort(HeadNode *adjlist[],int ES_LC[])
{
	int vi,vj ,k,dur;
	Node *ptr;

	/*�N�S���e��̪����I���J���|*/
	for ( vi = 1; vi <= N; vi++ )
		if ( adjlist[vi]->count == 0 )
			Push(&Stack1,vi);
	print_steps(ES_LC,0);   /*�C�X���|��ES_LC���p*/
	for ( k=1; k<= N; k++ )
	{
		if (  Stack1.top == empty )
		{
			printf("\nCyclic Path found....\n");
			exit(1);
		}
		/*�q���|�u�X���I*/
		vi = Pop(&Stack1);
		ptr = adjlist[vi]->link;  /*ptr���Vvi���۾F���C*/
		while ( ptr != NULL )
		{
			vj = ptr->vertex;     /*vj��vi���ߧY����*/
			dur = ptr->duration;  
			adjlist[vj]->count--;  /*vj �e��̼ƴ�1*/
			if ( adjlist[vj]->count == 0 )
				Push(&Stack1,vj);
			if ( adjlist == adjlist1 ) /*�P�_�p��ES��LC*/
				ES_LC[vj] = MAX(ES_LC[vj],ES_LC[vi]+dur);
			else
				ES_LC[vj] = MIN(ES_LC[vj],ES_LC[vi]-dur);
			ptr = ptr->link;
		}
		print_steps(ES_LC,vi);
	}
}

/*��ܥثe���|���p��ES��LC��*/
void print_steps(int ES_LC[],int v)
{
	int i;

	if ( v == 0 )
	{
		printf("\nComputation of ES_LC :\n");
		printf("----------------------\n");
		printf("ES_LC[N]  : ");
		for (i = 1;i <= N; i++ ) printf(" [%d]",i);
		printf("     Current Stack");
		printf("\ninitial   :");
	}
	else
		printf("\nPopout V%d :",v);
	for ( i = 1; i <= N; i++ )
		printf(" %3d",ES_LC[i]);
	printf("     ");
	for ( i =0; i <= Stack1.top; i++ )
		printf(" %d,",Stack1.item[i]);
}

/*��ܦU���I���̦��ɶ�(ES)�Φ��߮ɶ�(LC)��*/
void print_ES_LC()
{
	int i;

	printf("\n");
	for ( i = 1; i<= N; i++ )
		printf("\nES(%d) = %3d   LC(%d) = %3d ES  - LC = %3d",
					i,ES[i],i,LC[i],ES[i] - LC[i]);
}

/*�C�X�{���I*/
void print_critical_node()
{
	int v;

	for ( v =1; v<= N;v++ )
		if ( LC[v] == ES[v] )    /*��LC == ES �ɳ��I���{���I*/
			CriticalNode[++node_count] = v;
	printf("\n\nThe Critical Nodes of the Graph :\n");
	for ( v = 1; v<= node_count; v++ )
		printf("%d,",CriticalNode[v]);
}

/*�C�X�ɸ��|*/
void print_critical_path()
{
	printf("\n\nThe Critical Paths of the Graph :");
	/*�q�_�l���I�}�l��M�{�ɸ��|*/
	print_path_node(adjlist1[source]->link,source);
}

void print_path_node(Node *ptr,int v)
{
	int  i;

	/* �P�_�۾F���I�O�_���{���I�A�N�{���I���J���|
	   �ñq���{���I�~�򻼰j�I�sprint_path_node() */
	while ( ptr != NULL )
	{
		for ( i = 1;i<= node_count;i++)
			if ( CriticalNode[i] == ptr->vertex && LC[ptr->vertex]-LC[v] == ptr->duration )
			{
				Push(&Stack1,(int)ptr);
				Push(&Stack2,v);
				v = ptr->vertex;
				ptr = adjlist1[v]->link;
				print_path_node(ptr,v);
			}
		ptr = ptr->link;
	}

	if ( v == source )
	{
		printf("\n\nThere are %d Critical paths from %d to %d\n",
				path_count,source,sink);
		exit(0);
	}
	/* ����F���I�`�I�ɧY���@�{�ɸ��| */
	/* �C�X���|Stack1�Ҧs���{���I
	   ��Stack2�Ҧs���{�ɬ���        */
	if ( v == sink )
	{
		printf("\n");
		for ( i = 0;i <= Stack2.top; i++)
		{
			v = Stack2.item[i];
			ptr =(Node *) Stack1.item[i];
			printf("V%d--%d-->",v,ptr->duration);
		}
		printf("V%d",sink);
		path_count++;
	}

	/* �u�X���|�����e�@�h�{�ɳ��I���{�ɬ��� */
	/* �~��j�M��۾F���I�O�_���{�ɸ��| */
	ptr = (Node *)Pop(&Stack1);
	ptr = ptr->link;
	v = Pop(&Stack2);
	print_path_node(ptr,v);
}

/*�_�lES���*/
void initial_ES()
{
	int i;
	for ( i = 1;i <= N; i++ ) ES[i] = 0;
}

/*�_�lLC���,LC��Ȭ�ES�̤j��*/
void initial_LC()
{
	int i ,max = 0;
	for ( i = 1; i <= N; i++ ) max= MAX(max,ES[i]);
	for ( i = 1; i <= N; i++ ) LC[i] = max;
}

void Push( struct Stackstruct *stack,int value )
{
	if ( stack->top >= MAX_V)
	{
		printf("Stack is Overflow!!\n");
		exit(1);
	}
	else
		stack->item[++stack->top] = value;
}

int Pop(struct Stackstruct *stack)
{
	if ( stack->top == empty )
	{
		printf("Stack is empty!!");
		exit(1);
	}
	else
		return (stack->item[stack->top--]);
}