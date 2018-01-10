/* �{���d��: insertDNode.c */
/* ���: ���J�`�I */
void insertDNode(DList ptr, int d) { 
   /* �t�m�`�I�O���� */
   DList newnode = (DList) malloc(sizeof(DNode));
   newnode->data = d;      /* �إ߸`�I���e */ 
   if ( first == NULL )         /* �p�G��C�O�Ū� */
      first = newnode;          /* �Ǧ^�s�`�I���� */
   if ( ptr == NULL ) {
      /* ���p1: ���b�Ĥ@�Ӹ`�I���e, ������C�}�l */
      newnode->previous = NULL; /* �e���Ь�NULL */ 
      newnode->next = first;    /* �s�`�I���V��C�}�l */
      first->previous = newnode;/* ��`�I���V�s�`�I */
      first = newnode;          /* �s�`�I������C�}�l */
   }
   else {
      if ( ptr->next == NULL ) {/* �O�_�O�̫�@�Ӹ`�I */
         /* ���p2: ���b��C���̫� */
         ptr->next = newnode;   /* �̫�`�I���V�s�`�I */
         newnode->previous=ptr; /* �s�`�I���^�̫�`�I */
         newnode->next = NULL;  /* ��^���Ь�NULL */ 
      }
      else {
         /* ���p3: ���J�`�I�ܦ�C�������`�I */
         ptr->next->previous = newnode; /* ���^�s�`�I */
         newnode->next = ptr->next;  /* ���V�U�@�`�I */
         newnode->previous=ptr; /* �s�`�I���^���J�`�I */
         ptr->next = newnode;   /* ���J�`�I���V�s�`�I */
      }
   }
}
