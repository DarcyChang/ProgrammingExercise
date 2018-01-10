/* 程式範例: Ch2-4.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch2-4.h"
/* 函數: 建立稀疏矩陣 */
void createMatrix(int r,int c,int *arr) {
   int i, j, count;
   m.rows = r;              /* 初始結構的成員變數 */
   m.cols = c; 
   count = 0;
   for ( i = 0; i < r; i++ )    /* 二維陣列的走訪 */
      for ( j = 0; j < c; j++ )
         if ( arr[i*c+j] != 0 ) {        /* 元素有值 */
            m.smArr[count].row = i;      /* 列數 */
            m.smArr[count].col = j;      /* 欄數 */
            /* 元素值 */
            m.smArr[count].value = arr[i*c+j];
            count++;
         }
   m.numOfTerms = count;
}
/* 函數: 顯示稀疏矩陣 */
void printMatrix() {
   int i;
   /* 顯示稀疏矩陣尺寸和項目數 */
   printf("尺寸: %d X %d", m.rows, m.cols);
   printf(" 項目數: %d\n", m.numOfTerms);
   printf("列row\t欄col\t值value\n");
   /* 顯示稀疏矩陣的各項目座標與值 */
   for ( i = 0; i < m.numOfTerms; i++) {
     printf(" %d\t%d",m.smArr[i].row,m.smArr[i].col);
     printf("\t%d\n", m.smArr[i].value);
   }  
}
/* 主程式 */ 
int main() {   
   /* 稀疏矩陣 */
   int sparse[5][10] = { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 9, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
                         0, 0, 0, 0, 3, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 6, 0, 0 };
   int *fp = &sparse[0][0];        /* 取得陣列的指標 */ 
   /* 建立稀疏矩陣物件 */
   createMatrix(5, 10, fp); 
   printMatrix();                  /* 顯示稀疏矩陣 */
   system("PAUSE");
   return 0;  
}
