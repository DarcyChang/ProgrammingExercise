/* �{���d��: Ch5-2-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch5-2-1.h"
/* ���: �ˬd���|�O�_�O�Ū� */
int isStackEmpty() {
   if ( top == -1 ) return 1;
   else             return 0;
}
/* ���: �N��Ʀs�J���| */
int push(int d) {
   if ( top >= MAXSTACK ) { /* �O�_�W�L���|�e�q */
      printf("���|���e����\n");
      return 0;
   }   
   else {
      stack[++top] = d;    /* �s�J���| */
      return 1;
   }
}
/* ���: �q���|���X��� */
int pop() {
   if ( isStackEmpty() )   /* ���|�O�_�O�Ū� */
      return -1;
   else 
      return stack[top--]; /* ���X��� */
}
/* �D�{�� */
int main() {   
   /* �ŧi�ܼ� */
   int data[6] = {1, 2, 3, 4, 5, 6};
   int i;
   printf("�s�J���|��ƪ�����: ");
   /* �ϥΰj��N��Ʀs�J���| */
   for ( i = 0; i < 6; i++) {
      push(data[i]);
      printf("[%d]", data[i]);
   }
   printf("\n���X���|��ƪ�����: ");
   while ( !isStackEmpty() )   /* ���X���|��� */
      printf("[%d]", pop()); 
   printf("\n");
   system("PAUSE");
   return 0; 
}
