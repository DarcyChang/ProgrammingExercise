/* �{���d��: Ch6-2-2.c */
#include <stdio.h>
#include <stdlib.h> 
#include "Ch6-2-2.h"
/* ���: �ˬd��C�O�_�O�Ū� */
int isQueueEmpty() {
   if ( front == NULL ) return 1;
   else                 return 0;
}
/* ���: �N��Ʀs�J��C */
void enqueue(int d) {
   LQueue new_node;
   /* �t�m�`�I�O���� */
   new_node = (LQueue)malloc(sizeof(QNode));
   new_node->data = d;      /* �s�J��C�`�I */
   new_node->next = NULL;   /* �]�w��� */
   if ( rear == NULL )      /* �O�_�O�Ĥ@���s�J */
      front = new_node;     /* front���Vnew_node */
   else
      rear->next = new_node;/* ���Jrear���� */
   rear = new_node;         /* rear���Vnew_node */
}
/* ���: �q��C���X��� */
int dequeue() {
   LQueue ptr;
   int temp;
   if ( !isQueueEmpty() ) {   /* ��C�O�_�O�Ū� */
      if ( front == rear )    /* �p�G�O�̫�@�Ӹ`�I */
         rear = NULL;         
      ptr = front;            /* ptr���Vfront */
      front = front->next;    /* �R����1�Ӹ`�I */
      temp = ptr->data;       /* ���o��� */
      free(ptr);              /* ���^�O���� */
      return temp;            /* �Ǧ^���X����� */
   }
   else return -1;            /* ��C�O�Ū� */
}
/* �D�{�� */
int main() {   
   int input[100], output[100]; /* �x�s��J�M���X���� */
   int select = 1;              /* �ﶵ */
   int numOfInput  = 0;         /* �}�C�������� */
   int numOfOutput = 0;
   int i, temp;
   printf("�쵲��C����C�B�z......\n");                 
   while ( select != 3 ) {       /* �D�j�� */
      printf("[1]�s�J [2]���X [3]��ܥ������e ==> ");
      scanf("%d", &select);      /* ���o�ﶵ */
      switch ( select ) {
         case 1: /* �N��J�Ȧs�J��C */
            printf("�п�J�s�J��(%d) ==> ", numOfInput);
            scanf("%d", &temp);  /* ���o�s�J�� */
            enqueue(temp); 
            input[numOfInput++] = temp;
            break;
         case 2: /* ���X��C�����e */
            if ( !isQueueEmpty() ) {
               temp = dequeue();
               printf("���X��C����: %d\n", temp);
               output[numOfOutput++] = temp;
            }
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
