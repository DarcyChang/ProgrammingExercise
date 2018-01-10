/* �{���d��: createDList.c */
/* ���: �إ����V��C */
void createDList(int len, int *array) {
   int i;
   DList newnode, before;    /* �t�m��1�Ӹ`�I */
   first = (DList) malloc(sizeof(DNode));
   first->data = array[0];   /* �إ߸`�I���e */ 
   first->previous = NULL;   /* �e�`�I���Ь�NULL */ 
   before = first;           /* ���V�Ĥ@�Ӹ`�I */
   now = first;              /* ���]�ثe�`�I���� */
   for ( i = 1; i < len; i++ ) {
      /* �t�m�`�I�O���� */
      newnode = (DList) malloc(sizeof(DNode));
      newnode->data = array[i]; /* �إ߸`�I���e */ 
      newnode->next = NULL;     /* �U�`�I���Ь�NULL */ 
      newnode->previous=before; /* �N�s�`�I���V�e�`�I */
      before->next=newnode;     /* �N�e�`�I���V�s�`�I */
      before = newnode;         /* �s�`�I�����e�`�I */
   }
}
/* ���: ������V��C���`�I��� */
void printDList() {
   DList current = first;       /* �ثe���`�I���� */
   while ( current != NULL ) {  /* ��ܥD�j�� */
      if ( current == now )
         printf("#%d#", current->data);
      else 
         printf("[%d]", current->data);
      current = current->next;  /* �U�@�Ӹ`�I */
   }
   printf("\n");
}
/* ���: ���ʸ`�I���Ш�U�@�Ӹ`�I */
void nextNode() {
   if ( now->next != NULL )
      now = now->next;          /* �U�@�Ӹ`�I */
}
/* ���: ���ʸ`�I���Ш�W�@�Ӹ`�I */ 
void previousNode() {
   if ( now->previous != NULL )
      now = now->previous;      /* �e�@�Ӹ`�I */
}
/* ���: ���]�`�I���� */
void resetNode() {  now = first; }
/* ���: ���o�`�I���� */
DList readNode() { return now; }
