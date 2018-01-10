/* �{���d��: Ch6-4-2.c */
#include <stdio.h>
#include <stdlib.h> 
#include "Ch6-4-2.h" 
/* ���: �ˬd��C�O�_�O�Ū� */
int isDequeEmpty() {
   if ( front == NULL ) return 1;
   else                 return 0;
}
/* ���: �N��Ʀs�J��C (�q����) */
void endeque_rear(int d) {
   LDeque new_node;
   /* �t�m�`�I�O���� */
   new_node = (LDeque)malloc(sizeof(QNode));
   new_node->data = d;      /* �s�J��C�`�I */
   new_node->next = NULL;   /* �]�w��� */
   if ( rear == NULL )      /* �O�_�O�Ĥ@���s�J */
      front = new_node;     /* front���Vnew_node */
   else
      rear->next = new_node;/* ���Jrear���� */
   rear = new_node;         /* rear���Vnew_node */
}
/* ���: �N��Ʀs�J��C (�q�e��) */
void endeque_front(int d) {
   LDeque new_node;
   /* �t�m�`�I�O���� */
   new_node = (LDeque)malloc(sizeof(QNode));
   new_node->data = d;       /* �s�J��C�`�I */
   if ( front == NULL ) {    /* �O�_�O�Ĥ@���s�J */
      new_node->next = NULL; /* �]�w��� */
      rear = new_node;       /* rear���Vnew_node */
   } else
      new_node->next = front;/* ���Jfront���e */
   front = new_node;         /* front���Vnew_node */
}
/* ���: �q��C���X��� */
int dedeque() {
   LDeque ptr;
   int temp;
   if ( !isDequeEmpty() ) {   /* ��C�O�_�O�Ū� */
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
   int input[6] =  { 1, 2, 3, 4, 5, 6 }; /* ��J���� */
   int i, select;                        /* ��ܶ� */
   for ( i = 0; i < 6; i++ ) {    /* �s�J��C */
      printf("[1]�q��s�J [2]�q�e�s�J ==> ");
      scanf("%d", &select);       /* Ū�J�ﶵ */
      switch ( select ) {
         case 1: /* �q���ݦs�J��C���e */
            endeque_rear(input[i]);
            break;
         case 2: /* �q�e�ݦs�J��C���e */
            endeque_front(input[i]);
            break;
      }
   }
   printf("�s�J����������: ");  /* ��ܿ�J�}�C���e */
   for ( i = 0; i < 6; i++ )
      printf("[%d]", input[i]);
   printf("\n��C���X������: ");
   while ( !isDequeEmpty() )    /* ���X�ѤU����C���� */
      printf("[%d]", dedeque());
   printf("\n");
   system("PAUSE");
   return 0; 
}
