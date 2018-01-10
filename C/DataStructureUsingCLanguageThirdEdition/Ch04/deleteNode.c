/* �{���d��: deleteNode.c */
/* ���: �R���`�I */
int deleteNode(List ptr) {
   List current = first;   /* ���V�e�@�`�I */
   int value = ptr->data;  /* ���o�R�����`�I�� */
   if ( isListEmpty() )    /* �ˬd��C�O�_�O�Ū� */
      return -1;
   if (ptr==first || ptr==NULL) {/* ��C�}�l��NULL */
      /* ���p1: �R���Ĥ@�Ӹ`�I */
      first = first->next;       /* �R����1�Ӹ`�I */
   } else {     
      while (current->next!=ptr) /* ��`�Iptr���e�`�I */
         current = current->next;
      if ( ptr->next == NULL )    /* �O�_�O��C���� */
         /* ���p2: �R���̫�@�Ӹ`�I */
         current->next = NULL;    /* �R���̫�@�Ӹ`�I */
      else
         /* ���p3: �R�������`�I */
         current->next = ptr->next; /* �R�������`�I */
   }
   free(ptr);                     /* ����`�I�O���� */
   return value;                  /* �Ǧ^�R�����`�I�� */
}
