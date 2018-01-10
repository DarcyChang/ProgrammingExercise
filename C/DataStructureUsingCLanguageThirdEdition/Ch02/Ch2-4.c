/* �{���d��: Ch2-4.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch2-4.h"
/* ���: �إߵ}���x�} */
void createMatrix(int r,int c,int *arr) {
   int i, j, count;
   m.rows = r;              /* ��l���c�������ܼ� */
   m.cols = c; 
   count = 0;
   for ( i = 0; i < r; i++ )    /* �G���}�C�����X */
      for ( j = 0; j < c; j++ )
         if ( arr[i*c+j] != 0 ) {        /* �������� */
            m.smArr[count].row = i;      /* �C�� */
            m.smArr[count].col = j;      /* ��� */
            /* ������ */
            m.smArr[count].value = arr[i*c+j];
            count++;
         }
   m.numOfTerms = count;
}
/* ���: ��ܵ}���x�} */
void printMatrix() {
   int i;
   /* ��ܵ}���x�}�ؤo�M���ؼ� */
   printf("�ؤo: %d X %d", m.rows, m.cols);
   printf(" ���ؼ�: %d\n", m.numOfTerms);
   printf("�Crow\t��col\t��value\n");
   /* ��ܵ}���x�}���U���خy�лP�� */
   for ( i = 0; i < m.numOfTerms; i++) {
     printf(" %d\t%d",m.smArr[i].row,m.smArr[i].col);
     printf("\t%d\n", m.smArr[i].value);
   }  
}
/* �D�{�� */ 
int main() {   
   /* �}���x�} */
   int sparse[5][10] = { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 9, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
                         0, 0, 0, 0, 3, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 6, 0, 0 };
   int *fp = &sparse[0][0];        /* ���o�}�C������ */ 
   /* �إߵ}���x�}���� */
   createMatrix(5, 10, fp); 
   printMatrix();                  /* ��ܵ}���x�} */
   system("PAUSE");
   return 0;  
}
