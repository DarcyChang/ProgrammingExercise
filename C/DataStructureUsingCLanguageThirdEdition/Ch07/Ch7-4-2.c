/* �{���d��: Ch7-4-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-3-3.h"
#include "createBTree.c"
/* ���: �G���𪺫e�Ǩ��X */
void preOrder(BTree ptr) {
   if ( ptr != NULL ) {     /* �פ���� */
      /* ��ܸ`�I���e */
      printf("[%d]", ptr->data);
      preOrder(ptr->left);   /* ���l�� */
      preOrder(ptr->right);  /* �k�l�� */
   }
}
/* ���: �e�Ǩ��X��ܤG���� */
void printPreOrder() {
   preOrder(head);  /* �I�s�e�Ǩ��X��� */
   printf("\n");
} 
/* �D�{�� */
int main() {
   /* �G���𪺸`�I��� */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   createBTree(9, data);     /* �إߤG���� */
   printf("�e�Ǩ��X���`�I���e: \n");
   printPreOrder();   
   system("PAUSE");
   return 0; 
}
