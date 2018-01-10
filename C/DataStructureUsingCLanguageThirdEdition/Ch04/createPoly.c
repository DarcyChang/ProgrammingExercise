/* �{���d��: createPoly.c */
/* ���: �إߦh��������C */
PList createPoly(int len, float *array) {
   int i;
   PList first, ptr, newnode;   /* �إ߶}�Y�`�I */
   first = (PList) malloc(sizeof(PNode));
   first->coef = 0.0;    /* �إ߶}�Y�`�I�����e */
   first->exp = -1;  
   ptr = first;          /* �e�@�Ӹ`�I���� */
   for ( i = len-1; i >= 0; i-- ) {
      if ( array[i] != 0.0 ) {    /* �t�m�`�I�O���� */
         newnode = (PList) malloc(sizeof(PNode));
         newnode->coef = array[i]; /* �إ߸`�I�����e */
         newnode->exp = i;         
         ptr->next = newnode;     /* �s���s�`�I */ 
         ptr = newnode;           /* �����e�@�Ӹ`�I */ 
      }   
   }
   ptr->next = first;  /* �s����1�Ӹ`�I, �إ�������C */
   return first;
}
/* ���: ��ܦh���� */
void printPoly(PList first) {
   PList ptr = first->next;  /* ��C�u�����}�Y */
   float c;
   int e;
   while ( ptr != first ) {  /* ��ܥD�j�� */
      c = ptr->coef;
      e = ptr->exp;
      printf("%3.1fX^%d", c, e);
      ptr = ptr->next;       /* �U�@�Ӹ`�I */
      if ( ptr != first ) printf("+");
   }
   printf("\n");   
}
