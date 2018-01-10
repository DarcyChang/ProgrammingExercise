/* �{���d��: createBSTree.c */
/* ���: �إߤG���j�M�� */
void createBSTree(int len, int *array) {
   int i; 
   /* �ϥΰj��H���J�覡�إ߾𪬵��c */
   for ( i = 0; i < len; i++ ) 
      insertBSTreeNode(array[i]);
}
/* ���: �G���j�M�𪺸`�I���J) */
void insertBSTreeNode(int d) {
   BSTree newnode, current; /* �ثe�G����`�I���� */
   int inserted = 0; /* �O�_���J�s�`�I */
   /* �t�m�s�`�I���O���� */
   newnode = (BSTree) malloc(sizeof(TNode));
   newnode->data = d;      /* �إ߸`�I���e */ 
   newnode->left = NULL;
   newnode->right = NULL;
   if ( isBSTreeEmpty() )  /* �O�_�ŤG���� */
      head = newnode;      /* �إ߮ڸ`�I */
   else {  /* �O�d�ثe�G������� */
      current = head; 
      while( !inserted )    /* ����`�I�� */
         if ( current->data > newnode->data ) {
            /* �O�_�O�̥����l�`�I */
            if ( current->left == NULL ) {   
                current->left = newnode; /* �إ��쵲 */
                inserted = 1;
            } else current = current->left;/* ���l�� */
         }
         else {  /* �O�_�O�̥k���l�`�I */
            if ( current->right == NULL ) {
                current->right = newnode; /* �إ��쵲 */
                inserted = 1;
            } else current = current->right;/* �k�l�� */
         }
   }
}
/* ���: �ˬd�G���j�M��O�_�O�Ū� */
int isBSTreeEmpty() {
   if ( head == NULL ) return 1;
   else                return 0; 
}
/* ���: �H���Ǩ��X��ܤG���j�M�� */
void printBSTree() {
   inOrder(head, "[%d]");  /* �I�s���Ǩ��X��� */
   printf("\n");
}
/* ���: �G���j�M�𪺤��Ǩ��X */
void inOrder(BSTree ptr, char *f) {
   if ( ptr != NULL ) {         /* �פ���� */
      inOrder(ptr->left, f);    /* ���l�� */
      /* ��ܸ`�I���e */
      printf(f, ptr->data); 
      inOrder(ptr->right, f);   /* �k�l�� */
   }
}
/* ���: �G���j�M�𪺫e�Ǩ��X */
void preOrder(BSTree ptr, char *f) {
   if ( ptr != NULL ) {         /* �פ���� */
      /* ��ܸ`�I���e */
      printf(f, ptr->data);
      preOrder(ptr->left, f);   /* ���l�� */
      preOrder(ptr->right, f);  /* �k�l�� */
   }
}
/* ���: �G���j�M�𪺫�Ǩ��X */
void postOrder(BSTree ptr, char *f) {
   if ( ptr != NULL ) {          /* �פ���� */
      postOrder(ptr->left, f);   /* ���l�� */
      postOrder(ptr->right, f);  /* �k�l�� */
      /* ��ܸ`�I���e */
      printf(f, ptr->data);
   }
}
