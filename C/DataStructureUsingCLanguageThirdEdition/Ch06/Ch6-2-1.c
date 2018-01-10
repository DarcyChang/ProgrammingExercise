/* �{���d��: Ch6-2-1.c */
#include <stdio.h>
#include <stdlib.h> 
#include "Ch6-2-1.h"
/* ���: �ˬd��C�O�_�O�Ū� */
int isQueueEmpty() {
   if ( front == rear ) return 1;
   else                 return 0;
}
/* ���: �N��Ʀs�J��C */
int enqueue(int d) {
   if ( rear >= MAXQUEUE )  /* �O�_�W�L��C�e�q */
     return 0;
   else {
      queue[++rear] = d;    /* �s�J��C */
      return 1;
   }
}
/* ���: �q��C���X��� */
int dequeue() {
   if ( isQueueEmpty() )   /* ��C�O�_�O�Ū� */
      return -1;
   else
      return queue[++front];/* ���X��� */
}
/* �D�{�� */
int main() {   
   /* �ŧi�ܼ� */
   int data[6] = {1, 2, 3, 4, 5, 6};
   int i;
   printf("�s�J��C��ƪ�����: ");
   /* �ϥΰj��N��Ʀs�J��C */
   for ( i = 0; i < 6; i++) {
      enqueue(data[i]);
      printf("[%d]", data[i]);
   }
   printf("\n���X��C��ƪ�����: ");
   while ( !isQueueEmpty() )   /* ���X��C��� */
      printf("[%d]", dequeue()); 
   printf("\n");
   system("PAUSE");
   return 0; 
}
