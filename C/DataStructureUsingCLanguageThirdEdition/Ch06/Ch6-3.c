/* �{���d��: Ch6-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch6-3.h"
/* ���: �ˬd��C�O�_�O�Ū� */
int isQueueEmpty() {
   if ( front == rear ) return 1;
   else                 return 0;
}
/* ���: �ˬd��C�O�_�w�� */
int isQueueFull() {
   int pos;
   pos = (rear+1) % MAXQUEUE;
   if ( front == pos ) return 1;
   else                return 0;
}
/* ���: �N��Ʀs�J��C */
int enqueue(int d) {
   if ( isQueueFull() )          /* �ˬd�O�_�w�� */
      return 0;                  /* �w��, �L�k�s�J */
   else {
      rear = (rear+1) % MAXQUEUE;/* �O�_�W�L,���s�w�� */
      queue[rear] = d;
   }   
   return 1;
}
/* ���: �q��C���X��� */
int dequeue() {
   if ( isQueueEmpty() )         /* �ˬd��C�O�_�O�� */
      return -1;                 /* �L�k���X */
   front = (front+1) % MAXQUEUE; /* �O�_�W�L,���s�w�� */
   return queue[front];          /* �Ǧ^��C���X���� */
}
/* �D�{�� */
int main() {
   int input[100], output[100]; /* �x�s��J�M���X���� */
   int select = 1;              /* �ﶵ */
   int numOfInput  = 0;         /* �}�C�������� */
   int numOfOutput = 0;
   int i, temp;
   printf("������C�B�z......\n");                 
   while ( select != 3 ) {       /* �D�j�� */
      printf("[1]�s�J [2]���X [3]��ܥ������e ==> ");
      scanf("%d", &select);      /* ���o�ﶵ */
      switch ( select ) {
         case 1: /* �N��J�Ȧs�J��C */
            printf("�п�J�s�J��(%d) ==> ", numOfInput);
            scanf("%d", &temp);  /* ���o�s�J�� */
            if (enqueue(temp)) 
                input[numOfInput++] = temp;
            else
                printf("��C�w��!\n");
            break;
         case 2: /* ���X��C�����e */
            if ( !isQueueEmpty() ) {
               temp = dequeue();
               printf("���X��C����: %d\n", temp);
               output[numOfOutput++] = temp;
            }
            else
               printf("��C�w��!\n");
            break;
      }
   }
   printf("��J��C������: ");    /* ��J���� */
   for ( i = 0; i < numOfInput; i++ )
      printf("[%d]", input[i]);
   printf("\n���X��C������: ");  /* ��X���� */
   for ( i = 0; i < numOfOutput; i++ )
      printf("[%d]", output[i]);
   printf("\n�ѤU��C������: ");  /* ���X�ѤU��C���� */
   while ( !isQueueEmpty() )
      printf("[%d]", dequeue()); 
   printf("\n");
   system("PAUSE");
   return 0; 
}
