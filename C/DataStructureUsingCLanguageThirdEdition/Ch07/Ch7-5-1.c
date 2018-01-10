/* �{���d��: Ch7-5-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-5.h"
#include "createBSTree.c"
/* ���: �G���j�M�𪺷j�M */
BSTree searchBSTreeNode(int d) {
   BSTree ptr = head;
   while ( ptr != NULL ) {    /* �D�j�� */
      if ( ptr->data == d )   /* ���F */
         return ptr;          /* �Ǧ^�`�I���� */
      else
         if ( ptr->data > d ) /* ������ */
            ptr = ptr->left;  /* ���l�� */
         else
            ptr = ptr->right; /* �k�l�� */
   }
   return NULL;               /* �S����� */
}
/* �D�{�� */
int main() {
   int temp = 0;
   /* �G���j�M�𪺸`�I��� */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   createBSTree(9, data);     /* �إߤG���j�M�� */
   printf("�G���𪺸`�I���e: ");
   printBSTree();             /* ��ܤG���j�M�� */
   while ( temp != -1 ) {
      printf("�п�J�j�M���`�I���1~9(-1����) ==> ");
      scanf("%d", &temp);  /* Ū���`�I�� */
      if ( temp != -1 )    /* �j�M�`�I��� */
         if ( searchBSTreeNode(temp) != NULL ) 
            printf("�G���j�M��]�t�`�I[%d]\n", temp);
         else
            printf("�G���j�M�𤣧t�`�I[%d]\n", temp);
   }  
   system("PAUSE");
   return 0;    
}
