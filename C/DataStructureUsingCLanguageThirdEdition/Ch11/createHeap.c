/* �{���d��: createHeap.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP  100
int heap[MAX_HEAP];     /* ��n���}�C */
int heap_len  = 0;      /* ��n�ثe�������� */
/* ���: �ˬd��n�O�_�O�Ū� */ 
int isHeapEmpty() {
   if ( heap_len > 0 ) return 0;
   else                return 1;
}
/* ���: �V�W�վ��n */ 
void shiftUp(int *heap, int pos) {
   int temp;
   /* �վ��n���D�j�� */
   while ( pos > 1 ) {            /* �O�_�ݭn�վ� */
      if ( heap[pos] <= heap[pos/2] )
         break;                   /* ���� */
      else { /* �洫���l�`�I����� */
         temp = heap[pos];
         heap[pos] = heap[pos/2];
         heap[pos/2] = temp;
      }
      pos /= 2;                   /* ���ܤ��`�I */
   }
}
/* ���: ���J��n���� */ 
void insertHeap(int data) {
   heap_len++;                    /* �����[�@ */
   heap[heap_len] = data;         /* �s�J��n */
   shiftUp(heap, heap_len);       /* ���ذ�n */
}
/* ���: �V�U�վ��n */ 
void shiftDown(int *heap, int pos, int len) {
   int j, temp;
   j = 2 * pos;                   /* ���l�`�I���� */
   temp = heap[pos];              /* ��n�վ㪺�`�I�� */
   while ( j <= len ) {           /* �D�j�� */
      if ( j < len &&             /* ��̤j�l�`�I */
             heap[j] < heap[j+1] )
            j++;                  /* �k�l�`�I */
         if ( temp >= heap[j] )   /* ����𪺮ڸ`�I */
            break;                /* ���� */
         else {
            heap[j/2] = heap[j];  /* �洫���l�`�I */
            j = 2 * j;            /* �~��վ��l�`�I */
         }
   }
   heap[j/2] = temp;              /* ���`�I���վ㪺�`�I�� */
}
/* ���: �R����n���� */ 
int removeHeap() {      
   int temp = -1;
   if ( !isHeapEmpty() ) {        /* ��n���O�Ū� */
      temp = heap[1];             /* ���o�̤j���ڸ`�I */
      heap[1] = heap[heap_len];   /* �M�̫�@���洫 */
      heap_len--;                 /* ���״�@ */
      shiftDown(heap, 1,heap_len);/* ���ذ�n */
   }
   return temp;                   /* �Ǧ^�R���`�I���e */
}
/* ���: ��ܰ�n���� */ 
void printHeap() {
   int i;   
   printf("��n�����e: ");
   for (i = 1; i <= heap_len; i++)/* ��ܤ��e */
         printf("[%d]", heap[i]);
   printf("\n");
}
