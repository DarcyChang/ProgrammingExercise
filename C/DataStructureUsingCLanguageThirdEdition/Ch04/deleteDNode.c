/* �{���d��: deleteDNode.c */
/* ���: �R���`�I */
void deleteDNode(DList ptr) {
   if ( ptr->previous == NULL ) { /* �O�_���e�@�Ӹ`�I */
      /* ���p1: �R���Ĥ@�Ӹ`�I */
      first = first->next;      /* ���V�U�@�Ӹ`�I */
      first->previous = NULL;   /* �]�w���V�e�`�I���� */
   }
   else {
      if ( ptr->next == NULL ) {  /* �O�_���U�@�Ӹ`�I */
         /* ���p2: �R���̫�@�Ӹ`�I */
         ptr->previous->next = NULL;/* �e�`�I���VNULL */
      }
      else {
         /* ���p3: �R���������`�I */
         /* �e�`�I���V�U�@�`�I */
         ptr->previous->next = ptr->next;
         /* �U�@�`�I���V�e�`�I */
         ptr->next->previous = ptr->previous;
      }
   }
   free(ptr);                /* ���^�R���`�I�O���� */
}
