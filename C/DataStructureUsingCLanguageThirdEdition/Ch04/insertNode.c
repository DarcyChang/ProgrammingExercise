/* �{���d��: insertNode.c */
/* ���: ���J�`�I */
void insertNode(List ptr, int d) {   
   List newnode;
   /* �t�m�`�I�O���� */
   newnode = (List) malloc(sizeof(LNode));
   newnode->data = d;          /* ���w�`�I�� */ 
   if ( ptr == NULL ) {
      /* ���p1: ���J�Ĥ@�Ӹ`�I */
      newnode->next = first;   /* �s�`�I������C�}�l */
      first = newnode;
   }
   else {
      if ( ptr->next == NULL ) { /* ��C�̫�@�Ӹ`�I */
        /* ���p2: ���J�̫�@�Ӹ`�I */
        ptr->next = newnode;     /* �̫���V�s�`�I */
        newnode->next = NULL;    /* �s�`�I���VNULL */ 
      }  
      else {
        /* ���p3: ���J���������`�I */
        newnode->next=ptr->next;/* �s�`�I���V�U�@�`�I */
        ptr->next = newnode;    /* �`�Iptr���V�s�`�I */
      }
   }
}
