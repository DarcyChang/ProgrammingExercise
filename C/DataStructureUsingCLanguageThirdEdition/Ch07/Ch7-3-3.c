/* �{���d��: Ch7-3-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-3-3.h"
#include "createBTree.c"
/* �D�{�� */
int main() {
   /* �G���𪺸`�I��� */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   createBTree(9, data);     /* �إߤG���� */
   printf("�G����O�Ū�: %d\n", isBTreeEmpty());
   printf("�G���𪺸`�I���e: \n");
   printBTree();
   system("PAUSE");
   return 0; 
}
