/* �{���d��: createGraph.c */
/* ���: �ϥ���u�}�C�إ߹ϧ� */ 
void createGraph(int len, int *edge) {
   Graph newnode, ptr;           /* ���I���� */
   int from, to;                 /* ��u���_�I�M���I */
   int i;
   for ( i = 1; i < MAX_VERTICES; i++ ) {
      head[i].data = i;          /* �]�w���I�� */
      head[i].next = NULL;       /* �M���ϧΫ��� */
   }
   for ( i = 0; i < len; i++ ) { /* Ū����u���j�� */
      from = edge[i*2];          /* ��u���_�I */
      to = edge[i*2+1];          /* ��u�����I */
      /* �t�m�s���I���O���� */
      newnode = (Graph)malloc(sizeof(struct Vertex));
      newnode->data = to;       /* �إ߳��I���e */
      newnode->next = NULL;     /* �]�w���Ъ�� */
      ptr = &(head[from]);      /* ���а}�C�����I���� */
      while ( ptr->next != NULL ) /* ���X�ܦ�C�� */
         ptr = ptr->next;         /* �U�@�ӳ��I */
      ptr->next = newnode;        /* ���J���� */
   }
}
/* ���: ��ܹϧ� */
void printGraph() {
   Graph ptr;
   int i;
   /* �ϥΰj����ܹϧ� */
   for ( i = 1; i < MAX_VERTICES; i++ ) {
      ptr = head[i].next;               /* ���I���� */
      if ( ptr != NULL ) {  /* ���ϥΪ��`�I */ 
         printf("���IV%d =>", head[i].data);/* ���I�� */
         while ( ptr != NULL ) {        /* ���X��� */
            printf("V%d ", ptr->data);  /* ���I���e */
            ptr = ptr->next;            /* �U�@�ӳ��I */
         }
         printf("\n");
      }   
   }
}
