/* �{���d��: createAvlTree.c */
#include <stdio.h>
#include <stdlib.h>
/* ���: ���o�l�𪺳̤j�� */
static int h(AvlTree ptr) {
   if ( ptr == NULL ) return  0;  /* �Ťl�`�I */ 
   else  return ptr->height + 1;  /* �ثe�𰪥[�@ */ 
}
/* ���: �p�⥭�Ŧ]�lBalanced Factor */
static int bf(AvlTree ptr) {
   return h(ptr->left)-h(ptr->right); /* ����k�l�� */
}
/* ���: �p�⥪�k�l�𪺳̤j�� */
static int maxH(int lhights, int rhights) {
   return lhights > rhights ? lhights : rhights;
}
/* ���: LL�� */
static AvlTree singleRotateLL(AvlTree ptr) {
   AvlTree temp = ptr->left;      /* �l�ܤ��`�I */ 
   ptr->left = temp->right;       /* �s���k�l�� */ 
   temp->right = ptr;             /* ���ܤl�`�I */ 
   ptr->height = maxH(h(ptr->left),h(ptr->right));
   temp->height = maxH(h(temp->left),ptr->height);
   printf("LL[%d]\n", ptr->data);
   return temp;
}
/* ���: RR�� */
static AvlTree singleRotateRR(AvlTree ptr) {
   AvlTree temp = ptr->right;     /* �l�ܤ��`�I */
   ptr->right = temp->left;       /* �s�����l�� */
   temp->left = ptr;              /* ���ܤl�`�I */ 
   ptr->height = maxH(h(ptr->left),h(ptr->right));
   temp->height = maxH(ptr->height,h(temp->right));
   printf("RR[%d]\n", ptr->data); 
   return temp;
}
/* ���: LR�� */
static AvlTree doubleRotateLR(AvlTree ptr) {
   printf("LR[%d]\n", ptr->data);     
   ptr->left = singleRotateRR(ptr->left);  /* RR */ 
   return singleRotateLL(ptr);             /* LL */
}
/* ���: RL�� */
static AvlTree doubleRotateRL(AvlTree ptr) {
   printf("RL[%d]\n", ptr->data);     
   ptr->right = singleRotateLL(ptr->right); /* LL */
   return singleRotateRR(ptr);              /* RR */
}
/* ���: ���J�`�I��AVL�� */
AvlTree insertAvlNode(int data, AvlTree ptr) {
   if ( ptr == NULL ) { /* �إ߸`�I�O���� */ 
      ptr = (AvlTree) malloc( sizeof(AvlNode));
      ptr->data = data;
      ptr->height = 1;
      ptr->left = ptr->right = NULL;
   }
   else if ( data < ptr->data ) { /* �����l�� */ 
           ptr->left = insertAvlNode(data, ptr->left);
           if ( bf(ptr) == 2 )   /* ������ */ 
              if (  bf(ptr->left) == 1 )
                 ptr = singleRotateLL(ptr); /* LL */
              else
                 ptr = doubleRotateLR(ptr); /* LR */
   }
   else if ( data > ptr->data ) { /* ���k�l�� */ 
           ptr->right = insertAvlNode(data, ptr->right);
           if ( bf(ptr) == -2 )    /* ������ */
              if ( bf(ptr->right) == -1 )
                 ptr = singleRotateRR(ptr); /* RR */
              else
                 ptr = doubleRotateRL(ptr); /* RL */
   }
   ptr->height = maxH(h(ptr->left), h(ptr->right));
   return ptr;
}
/* ���: �إ�AVL�� */
void createAvlTree(int len, int *array) {
   int i; /* �ϥΰj��H���J�覡�إ߾𪬵��c */
   for ( i = 0; i < len; i++ ) 
      head = insertAvlNode(array[i], head);
}
/* ���: AVL�𪺤��Ǩ��X */
static void inOrder(AvlTree ptr, char *f) {
   if ( ptr != NULL ) {         /* �פ���� */
      inOrder(ptr->left, f);    /* ���l�� */
      /* ��ܸ`�I���e */
      printf(f, ptr->data, ptr->height, bf(ptr));
      inOrder(ptr->right, f);   /* �k�l�� */
   }
}
/* ���: ���AVL�� */
void printAvlTree() {
   inOrder(head, "%d(%d/%d) ");  /* �I�s���Ǩ��X��� */
   printf("\n");
}
