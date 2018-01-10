/* �{���d��: Ch10-5-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch10-5-3.h"
/* ���: ������ */
int hashFunc(int key) { return key % 10; }  /* �l�� */
/* ���: �إ������ */
void createHashTable(int len, int *array) {
   Table ptr;               /* �}�l���� */
   Table newnode;           /* �s�`�I���� */
   int pos;                 /* ���ަ�m�ܼ� */
   int i;
   for ( i = 0; i < MAX_LEN; i++ )
      hashTable[i].next = NULL;    /* �M������� */
   /* �ϥΰj��إ������ */
   for ( i = 0; i < len; i++ ) {
      /* �إ߸`�I, �t�m�O���� */
      newnode = ( Table ) malloc(sizeof(struct Node));
      newnode->data = array[i];    /* �������� */
      newnode->next = NULL;        /* ���Ъ���� */
      /* �I�s�����ƭp����ަ�m */
      pos = hashFunc(array[i]);
      ptr = hashTable[pos].next;   /* ���o�}�l���� */
      if ( ptr != NULL ) {         /* �O�_�O��1�Ӹ`�I */
         while ( ptr->next!=NULL ) /* ��X�̫�1�Ӹ`�I */
            ptr= ptr->next;        /* �U�@�Ӹ`�I */
         ptr->next = newnode; /* �쵲�`�I */
      } else
         hashTable[pos].next = newnode; /* ��1�Ӹ`�I */      
   }   
}
/* ���: �쵲�k������j�M */
int chainHashSearch(int key) {
   Table ptr;               /* �}�l���� */
   int pos;                 /* ��m�ܼ� */
   /* �I�s�����ƭp���m */
   pos = hashFunc(key);
   ptr = hashTable[pos].next;   /* ���o�}�l���� */
   while ( ptr != NULL )        /* �쵲�k���j�M�j�� */
      if ( ptr->data == key )   /* �O�_���F */
         return 1;
      else
         ptr = ptr->next;       /* �U�@�Ӹ`�I */
   return 0;
}
/* ���: �����������e */
void printHashTable() {
   Table ptr;               /* �}�l���� */
   int i;
   printf("������e: ");
   for ( i = 0; i < MAX_LEN; i++ ) { 
      printf("\n%2d ==> ",i);
      ptr = hashTable[i].next;  /* ���o�}�l���� */
      while ( ptr != NULL ) {   /* ��ܦ�C���j�� */
         printf("[%2d]", ptr->data);  /* ������ */
         ptr = ptr->next;       /* �U�@�Ӹ`�I */
      }
   }
   printf("\n"); 
}
/* �D�{�� */ 
int main() {
   /* �j�M����ȸ�� */
   int data[8]={37, 25, 11, 29, 34, 46, 44, 35};
   int target;
   createHashTable(8, data);  /* �إ������ */ 
   printHashTable();          /* �������� */
   target = 0;
   while ( target != -1 ) {
      printf("�п�J�j�M��(-1����) ==> ");
      scanf("%d", &target);
      /* �I�s�쵲�k������j�M��� */
      if ( chainHashSearch(target) )
          printf("�j�M�����: %d\n", target);
      else
          printf("�S���j�M�����: %d\n", target);
   }
   system("PAUSE");
   return 0; 
}
