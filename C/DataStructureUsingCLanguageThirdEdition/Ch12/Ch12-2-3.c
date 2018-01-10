/* �{���d��: Ch12-2-3.c */
#include <stdio.h>
#include <stdlib.h>
#define  MAX_LEN   8
#include "Ch12-2.h"
#include "createAvlTree.c"
#include "deleteAvlNode.c"
/* �D�{�� */ 
int main() {
   /* AVL�𪺸`�I��� */
   int data[MAX_LEN]={50,20,80,10,30,60, 90,70};
   int target = 0;
   createAvlTree(MAX_LEN, data);   /* �إ�AVL�� */ 
   printf("AVL��: ");
   printAvlTree();                 /* ���AVL�� */
   while ( target != -1 ) {
      printf("�п�J�R�����`�I���(-1����) ==> ");
      scanf("%d", &target);  /* Ū���`�I�� */
      if ( target != -1 ) {  /* ���R���`�I��� */
         if (deleteAvlNode(target)) { /* �R���`�I */
            printf("�R����: ");
            printAvlTree();        /* ���AVL�� */
         }   
         else printf("�S�����R���`�I...\n");
      }       
   }  
   system("PAUSE");
   return 0; 
}
