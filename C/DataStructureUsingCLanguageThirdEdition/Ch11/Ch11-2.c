/* �{���d��: Ch11-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "createHeap.c"
/* �D�{�� */ 
int main() {
   /* �G���𪺸`�I��� */
   int data[10] = { 0, 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   int i;
   printf("�G���𤺮e: ");
   for ( i = 1; i < 10; i++ ) {    /* ��ܤG���𤺮e */
      printf("[%d]", data[i]);
      insertHeap(data[i]);
   }
   printf("\n");
   printHeap();
   printf("�R���`�I = %d\n", removeHeap());
   printHeap();
   printf("�R���`�I = %d\n", removeHeap());
   printHeap();
   system("PAUSE");
   return 0; 
}
