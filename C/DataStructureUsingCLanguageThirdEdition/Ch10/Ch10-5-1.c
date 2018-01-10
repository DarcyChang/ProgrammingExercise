/* �{���d��: Ch10-5-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch10-5-1.h"
/* ���: ������ */
int hashFunc(int key) { return key % 10; }  /* �l�� */
/* ���: �إ������ */
void createHashTable(int len, int *array) {
   int pos;                 /* ���ަ�m�ܼ� */
   int temp, i;
   for ( i = 0; i < MAX_LEN; i++ )
      hashTable[i] = -1;    /* �M������� */
   /* �ϥΰj��إ������ */
   for ( i = 0; i < len; i++ ) {
      /* �I�s�����ƭp����ަ�m */
      pos = hashFunc(array[i]);
      temp = pos;           /* �O�d�}�l�����ަ�m */
      while ( hashTable[temp] != -1 ) { /* ��M��m */
         temp = ( temp + 1 ) % MAX_LEN; /* �U�@�Ӧ�m */
         if ( pos == temp ) {       /* �����O�_�v�� */
            printf("�����v��!\n");
            return;
         }
      }
      hashTable[temp] = array[i];   /* �s�J����� */
   }   
}
/* ���: �u�ʱ����k������j�M */
int lineHashSearch(int key) {
   int pos;                 /* ��m�ܼ� */
   int temp;
   /* �I�s�����ƭp���m */
   pos = hashFunc(key);
   temp = pos;              /* �O�d�}�l�����ަ�m */
   while ( hashTable[temp] != key && /* �u�ʱ����j�� */
           hashTable[temp] != -1 ) {
      /* �ϥξl�ƱN�}�C�ܬ����� */
      temp = ( temp + 1 ) % MAX_LEN;/* �U�@�Ӧ�m */
      if ( pos == temp )            /* �d�ߵ��� */
         return -1;                 /* �w���S����� */
   }
   if ( hashTable[temp] == -1 )  /* �O�_�O�ť� */
      return -1;                 /* �S����� */
   else
      return temp;               /* ���F */
}
/* ���: �����������e */
void printHashTable() {
   int i;
   for ( i = 0; i < MAX_LEN; i++ )  /* �������� */
       printf("[%2d]", hashTable[i]);
   printf("\n");
}
/* �D�{�� */ 
int main() {
   /* �j�M����ȸ�� */
   int data[8]={37, 25, 11, 29, 34, 46, 44, 35};
   int target, index;
   createHashTable(8, data);  /* �إ������ */ 
   printf("������e: ");
   printHashTable();          /* �������� */
   target = 0;
   while ( target != -1 ) {
      printf("�п�J�j�M��(-1����) ==> ");
      scanf("%d", &target);
      /* �I�s�u�ʱ����k������j�M��� */
      index = lineHashSearch(target);
      if (index != -1)
          printf("�j�M�����: %d(%d)\n", target, index);
      else
          printf("�S���j�M�����: %d\n", target);
   }
   system("PAUSE");
   return 0; 
}
