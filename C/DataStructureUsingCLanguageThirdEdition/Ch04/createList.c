/* �{���d��: createList.c */
/* ���: �إߦ�C */
void createList(int len, int *array) {
   int i;
   List newnode;
   for ( i = 0; i < len; i++ ) {
      /* �t�m�`�I�O���� */
      newnode = (List) malloc(sizeof(LNode));
      newnode->data = array[i]; /* �إ߸`�I���e */ 
      newnode->next = first;
      first = newnode;
   }
}
/* ���: �ˬd��C�O�_�O�Ū� */
int isListEmpty() {
   if ( first == NULL ) return 1;
   else                 return 0;
}
/* ���: ��ܦ�C��� */
void printList() {
   List current = first;  /* �ثe����C���� */
   while ( current != NULL ) { /* ��ܥD�j�� */
      printf("[%d]", current->data);
      current = current->next;  /* �U�@�Ӹ`�I */
   }
   printf("\n");
}
/* ���: �j�M�`�I��� */
List searchNode(int d) {
   List current = first;   /* �ثe����C���� */
   while ( current != NULL ) { /* �j�M�D�j�� */
      if ( current->data == d ) /* �O�_����� */
         return current; /* ��� */
      current = current->next;  /* �U�@�Ӹ`�I */
   }
   return NULL;          /* �S����� */
}
