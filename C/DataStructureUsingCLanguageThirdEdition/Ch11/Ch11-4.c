/* �{���d��: Ch11-4.c */
#include <stdio.h>
#include <stdlib.h> 
#include "createHeap.c"
/* ���: �ˬd�u����C�O�_�O�Ū� */
int isPriorityQueueEmpty() {
   if ( isHeapEmpty() ) return 1;
   else                 return 0;
}
/* ���: �N��Ʀs�J�u����C */
void enqueue(int d) {
   insertHeap(d);        /* �s�J�u����C */
}
/* ���: �q�u����C���X��� */
int dequeue() {
   return removeHeap();  /* ���X��� */
}
/* �D�{�� */
int main() {   
   /* �ŧi�ܼ� */
   int data[6] = {6, 2, 3, 5, 4, 1};
   int i;
   printf("�s�J�u����C��ƪ�����: ");
   /* �ϥΰj��N��Ʀs�J��C */
   for ( i = 0; i < 6; i++ ) {
      enqueue(data[i]);
      printf("[%d]", data[i]);
   }
   printf("\n���X�u����C��ƪ�����: ");
   while (!isPriorityQueueEmpty()) /* ���X��C��� */
      printf("[%d]", dequeue()); 
   printf("\n");
   system("PAUSE");
   return 0; 
}
