/* �{���d��: Ch12-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#define  MAX_LEN     6
#include "Ch12-2.h"
#include "createAvlTree.c"
/* �D�{�� */ 
int main() {
   /* AVL�𪺸`�I��� */
   int data[MAX_LEN]={50, 20, 60, 10, 40, 30};
   createAvlTree(MAX_LEN, data);   /* �إ�AVL�� */ 
   printf("AVL��`�I���e: ");
   printAvlTree();                 /* ���AVL�� */
   system("PAUSE");
   return 0; 
}
