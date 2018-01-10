/* 程式範例: Ch3-2-1.c */
#include <stdio.h>
#include <stdlib.h>
#define LEN       6
/* 主程式 */
int main() {
   /* 宣告變數 */
   int i;
   /* 建立int陣列且指定初值 */
   int array[LEN] = { 1, 23, 33, 17, -40, 100 };
   int *ptr = array;  /* 第一個元素 */ 
   /* 顯示陣列元素的值 */ 
   for ( i = 0; i < LEN; i++ )
      printf("array[%d]=%d ",i,array[i]);
   printf("\n");
   ptr = array;  /* 第一個元素 */ 
   for ( i = 0; i < LEN; i++ )
      printf("ptr+%d=%d ", i, *(ptr+i));
   printf("\n");
   ptr = &array[0];  /* 第一個元素 */ 
   for ( i = 0; i < LEN; i++ )
      printf("ptr+%d=%d ", i, *ptr++);
   printf("\n");
   ptr = &array[LEN-1];  /* 最後一個元素 */ 
   for ( i = 0; i < LEN; i++ )
      printf("ptr-%d=%d ", i, *ptr--);
   printf("\n");
   system("PAUSE");
   return 0; 
}
