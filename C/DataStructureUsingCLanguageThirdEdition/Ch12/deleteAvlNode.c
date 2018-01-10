/* �{���d��: deleteAvlNode.c */
#include <stdio.h>
#include <stdlib.h>
/* ���: ����AVL�� */
static AvlTree rebuildAVL(AvlTree ptr) {
   if ( ptr != NULL ) {   /* �פ���� */
      ptr->left = rebuildAVL(ptr->left);  /* ���l�� */ 
      ptr->right = rebuildAVL(ptr->right);/* �k�l�� */ 
      if ( bf(ptr) == 2 )   /* ������ */ 
         if (  bf(ptr->left) == 1 )
            ptr = singleRotateLL(ptr); /* LL */
         else
            ptr = doubleRotateLR(ptr); /* LR */
      if ( bf(ptr) == -2 )    /* ������ */
         if ( bf(ptr->right) == -1 )
            ptr = singleRotateRR(ptr); /* RR */
         else
            ptr = doubleRotateRL(ptr); /* RL */
      /* ���w�̰����l�� */     
      ptr->height = maxH(h(ptr->left), h(ptr->right));
   }   
   return ptr;
}
/* ���: �HBSTree��k�ӧR���`�I */
static int deleteBSTreeNode(int d) {
   AvlTree parent;      /* ���`�I���� */
   AvlTree ptr;         /* �R���`�I���� */
   AvlTree child;       /* �l�`�I���� */
   int isfound = 0;     /* �O�_���R���`�I */ 
   /* ��M�R���`�I,����`�I���� */
   parent = ptr = head;
   while ( ptr != NULL && !isfound ) { /* �D�j�� */
      if ( ptr->data == d ) isfound = 1; /* ���`�I */
      else {
         parent = ptr;        /* �O�d���`�I���� */
         if ( ptr->data > d ) /* ������ */
              ptr = ptr->left; /* ���l�� */
         else ptr = ptr->right;/* �k�l�� */
      }       
   }
   if ( ptr == NULL ) return 0;  /* �S�����`�I */
   /* �R��AVL�𪺸`�I, ���p1: ���`�I */
   if ( ptr->left == NULL && ptr->right == NULL ) {
      if ( parent->left == ptr )
         parent->left = NULL;  /* ���l�`�I */
      else
         parent->right = NULL; /* �k�l�`�I */
      free(ptr);               /* ���^�`�I�O���� */
      return 1;                /* �w�R�� */ 
   }
   /* ���p2: �S�����l�� */
   if ( ptr->left == NULL ) {
      if ( parent->left == ptr )
         parent->left = ptr->right; /* ���l�`�I */ 
      else parent->right = ptr->right; /* �k�l�`�I */
      free(ptr);               /* ���^�`�I�O���� */
      return 1;                /* �w�R�� */ 
   } /* ���p3: �S���k�l�� */
   if ( ptr->right == NULL ) {
      if ( parent->right == ptr )
         parent->right = ptr->left; /* �k�l�`�I */ 
      else parent->left = ptr->left;/* ���l�`�I */ 
      free(ptr);               /* ���^�`�I�O���� */
      return 1;                /* �w�R�� */ 
   } /* ���p4: �����l��M�k�l�� */
   if ( ptr->left != NULL && ptr->right != NULL ) {
      parent = ptr;              /* ���`�I���V�R���`�I */
      child = ptr->left;             /* �]�w�����l�`�I */
      while ( child->right!=NULL ) { /* ���̥k���`�I */
         parent = child;             /* �O�d���`�I���� */
         child = child->right;       /* ���k�l�� */
      }
      ptr->data = child->data;     /* �]�w�����`�I��� */
      if ( parent->left == child ) /* �l�`�I�S���k�l�� */
         parent->left = NULL;       
      else parent->right=child->left;/* �s�����中�`�I */
      free(child);                   /* ���^�`�I�O���� */
      return 1;                      /* �w�R�� */
   } 
   return 1;                         /* ���\�R�� */ 
}

/* ���: �R��AVL�𪺸`�I */
int deleteAvlNode(int d) {
   if ( deleteBSTreeNode(d) == 0 ) return 0; /* �S����� */
   else head = rebuildAVL(head);             /* ����AVL�� */
   return 1;                         /* ���\�R�� */ 
}
