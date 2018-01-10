/* �{���d��: Ch7-4-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-3-3.h"
#include "createBTree.c"
/* ���: �G���𪺤��Ǩ��X */
void inOrder(BTree ptr) {
   if ( ptr != NULL ) {     /* �פ���� */
      inOrder(ptr->left);   /* ���l�� */
      /* ��ܸ`�I���e */
      printf("[%d]", ptr->data); 
      inOrder(ptr->right);  /* �k�l�� */
   }
}
/* ���: ���Ǩ��X��ܤG���� */
void printInOrder() {
   inOrder(head);  /* �I�s���Ǩ��X��� */
   printf("\n");
} 
/* �D�{�� */
int main() {
   /* �G���𪺸`�I��� */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   createBTree(9, data);     /* �إߤG���� */
   printf("���Ǩ��X���`�I���e: \n");
   printInOrder();   
   system("PAUSE");
   return 0; 
}
