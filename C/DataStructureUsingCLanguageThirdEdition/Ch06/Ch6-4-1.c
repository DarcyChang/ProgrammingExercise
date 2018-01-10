/* �{���d��: Ch6-4-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch6-4-1.h"
/* ���: �ˬd����C�O�_�O�Ū� */
int isDequeEmpty() {
   if ( front == rear ) return 1;
   else                 return 0;
}
/* ���: �ˬd����C�O�_�w�� */
int isDequeFull() {
   int pos;
   pos = ( rear+1 == MAXQUEUE ) ? 0 : rear+1;
   if ( front == pos  ) return 1;
   else                 return 0;
}
/* ���: �N��Ʀs�J��C */
int endeque(int d) {
   if ( isDequeFull() )          /* �ˬd�O�_�w�� */
      return 0;                  /* �w��, �L�k�s�J */
   else { /* �O�_�W�L,���s�w�� */
      rear = ( rear+1 == MAXQUEUE ) ? 0 : rear+1;
      deque[rear] = d;
   }   
   return 1;
}
/* ���: �q��C(����)���X��� */
int dedeque_rear() {
   int temp;
   if ( isDequeEmpty() )         /* �ˬd��C�O�_�O�� */
      return -1;                 /* �L�k���X */
   temp = deque[rear];
   rear--;                       /* ���ݫ��Щ��e�� */
   /* �O�_�W�L�}�C��� */
   if ( rear < 0 )
      rear = MAXQUEUE - 1;       /* �q�̤j�ȶ}�l */
   return temp;                  /* �Ǧ^��C���X���� */
}
/* ���: �q��C(�e��)���X��� */
int dedeque_front() {
   if ( isDequeEmpty() )         /* �ˬd��C�O�_�O�� */
      return -1;                 /* �L�k���X */
   /* �O�_�W�L,���s�w�� */   
   front = ( front+1 == MAXQUEUE ) ? 0 : front+1; 
   return deque[front];          /* �Ǧ^��C���X���� */
}
/* �D�{�� */
int main() {   
   int input[6] =  { 1, 2, 3, 4, 5, 6 }; /* ��J���� */
   int output[6];                        /* ���X���� */
   int select;                           /* ��ܶ� */
   int i, temp, pos = 0;
   for ( i = 0; i < 6; i++ )   /* �N�}�C�����s�J��C */
      endeque(input[i]);
   printf("��J���������C���B�z......\n");   
   while ( !isDequeEmpty() ) {   /* �D�j�� */
      printf("[1]�q����X [2]�q�e���X ==> ");
      scanf("%d", &select);       /* ���o�ﶵ */
      switch ( select ) {
         case 1:  /* �q���ݨ��X��C���e */
            temp = dedeque_rear();
            output[pos++] = temp;
            break;
         case 2:  /* �q�e�ݨ��X��C���e */
            temp = dedeque_front();
            output[pos++] = temp;
            break;
      }
   }
   printf("�s�J��C������: ");   /* ��ܿ�J�}�C���e */
   for ( i = 0; i < 6; i++ )
      printf("[%d]", input[i]);
   printf("\n��C���X������: "); /* ��ܨ��X�}�C���e */
   for ( i = 0; i < 6; i++ )
      printf("[%d]", output[i]);  
   printf("\n");
   system("PAUSE");
   return 0; 
}
