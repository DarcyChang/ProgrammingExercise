/* �{���d��: Ch5-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch5-2-2.h"
/* ���: �ˬd���|�O�_�O�Ū� */
int isStackEmpty() {
   if ( top == NULL ) return 1;
   else               return 0;
}
/* ���: �N��Ʀs�J���| */
void push(int d) {
   LStack new_node;            /* �s�`�I���� */
   /* �t�m�`�I�O���� */
   new_node = (LStack)malloc(sizeof(SNode));
   new_node->data = d;         /* �إ߸`�I���e */
   new_node->next = top;       /* �s�`�I���V��}�l */
   top = new_node;             /* �s�`�I�������|�}�l */   
}
/* ���: �q���|���X��� */
int pop() {
   LStack ptr;                 /* ���V���|���� */
   int temp;
   if ( !isStackEmpty()  ) {   /* ���|�O�_�O�Ū� */
      ptr = top;               /* ���V���|���� */
      top = top->next;         /* ���|���Ы��V�U�`�I */
      temp = ptr->data;        /* ���X��� */
      free(ptr);               /* ���^�`�I�O���� */
      return temp;             /* ���|���X */
   }
   else return -1;
}
/* �D�{�� */
int main() {   
   int input[100], output[100]; /* �x�s��J�M���X���� */
   int select = 1;              /* �ﶵ */
   int numOfInput  = 0;         /* �}�C�������� */
   int numOfOutput = 0;
   int i , temp;
   printf("�쵲��C�����|�B�z......\n");                
   while ( select != 3 ) {      /* �D�j�� */
      printf("[1]�s�J [2]���X [3]��ܥ������e ==> ");
      scanf("%d", &select);     /* ���o�ﶵ */
      switch ( select ) {
         case 1: /* �N��J�Ȧs�J���| */
            printf("�п�J�s�J��(%d) ==> ", numOfInput);
            scanf("%d", &temp); /* ���o�s�J�� */
            push(temp);
            input[numOfInput++] = temp;
            break;
         case 2: /* ���X���|�����e */
            if ( !isStackEmpty() ) {
               temp = pop();
               printf("���X���|����: %d\n", temp);
               output[numOfOutput++] = temp;
            }   
            break;
      }
   }
   printf("��J���|������: ");    /* ��J���� */
   for ( i = 0; i < numOfInput; i++ )
      printf("[%d]", input[i]);
   printf("\n���X���|������: ");  /* ��X���� */
   for ( i = 0; i < numOfOutput; i++ )
      printf("[%d]", output[i]);
   printf("\n�ѤU���|������: ");  /* ���X�ѤU���|���� */
   while ( !isStackEmpty() ) 
      printf("[%d]", pop()); 
   printf("\n");
   system("PAUSE");
   return 0; 
}
