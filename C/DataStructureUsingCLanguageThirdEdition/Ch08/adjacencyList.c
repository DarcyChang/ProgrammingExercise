/* �{���d��: adjacencyList.c */
#define MAX_VERTICES   10       /* �ϧΪ��̤j���I�� */
struct Vertex {                 /* �ϧγ��I���c�ŧi */
   int data;                    /* ���I��� */
   int weight;                  /* �v�� */ 
   struct Vertex *next;         /* ���U�@�ӳ��I������ */
};
typedef struct Vertex *Graph;   /* �ϧΪ��s���A */
/* ���: �ϥ���u�}�C�إߧt������ת��ϧ� */ 
void createGraph(Graph head, int len, int *edge) {
   Graph newnode, ptr;           /* ���I���� */
   int from, to;                 /* ��u���_�I�M���I */
   int i;
   for ( i = 1; i < MAX_VERTICES; i++ ) {
      head[i].data = 0;          /* �M�����I�� */
      head[i].next = NULL;       /* �M���ϧΫ��� */
   }
   for ( i = 0; i < len; i++ ) { /* Ū����u���j�� */
      from = edge[i*3];          /* ��u���_�I */
      to = edge[i*3+1];          /* ��u�����I */
      head[to].data += 1;        /* ������ץ[�@ */
      /* �t�m�s���I���O���� */
      newnode = (Graph)malloc(sizeof(struct Vertex));
      newnode->data = to;       /* �إ߳��I���e */
      newnode->weight = edge[3*i+2];
      newnode->next = NULL;     /* �]�w���Ъ�� */
      ptr = &(head[from]);      /* ���а}�C�����I���� */
      while ( ptr->next != NULL ) /* ���X�ܦ�C�� */
         ptr = ptr->next;         /* �U�@�ӳ��I */
      ptr->next = newnode;        /* ���J���� */
   }
}
/* ���: ��ܹϧ� */
void printGraph(Graph head) {
   Graph ptr;
   int i;
   /* �ϥΰj����ܹϧ� */
   for ( i = 1; i < MAX_VERTICES; i++ ) {
      ptr = head[i].next;               /* ���I���� */
      if ( ptr != NULL ) {  /* ���ϥΪ��`�I */
         printf("V%d(%d) =>",i,head[i].data);/* ���I */
         while ( ptr != NULL ) {        /* ���X��� */
            printf("V%d[%d] ", ptr->data,
                   ptr->weight);        /* ���I���e */
            ptr = ptr->next;            /* �U�@�ӳ��I */
         }
         printf("\n");
      }   
   }
}
