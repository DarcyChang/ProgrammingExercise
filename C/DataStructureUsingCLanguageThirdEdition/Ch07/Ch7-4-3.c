/* �{���d��: Ch7-4-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-3-3.h"
#include "createBTree.c"
/* ���: �G���𪺫�Ǩ��X */
void postOrder(BTree ptr) {
   if ( ptr != NULL ) {     /* �פ���� */
      postOrder(ptr->left);   /* ���l�� */
      postOrder(ptr->right);  /* �k�l�� */
      /* ��ܸ`�I���e */
      printf("[%d]", ptr->data);
   }
}
/* ���: ��Ǩ��X��ܤG���� */
void printPostOrder() {
   postOrder(head);  /* �I�s��Ǩ��X��� */
   printf("\n");
} 
/* �D�{�� */
int main() {
   /* �G���𪺸`�I��� */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   createBTree(9, data);     /* �إߤG���� */
   printf("��Ǩ��X���`�I���e: \n");
   printPostOrder();   
   system("PAUSE");
   return 0; 
}
