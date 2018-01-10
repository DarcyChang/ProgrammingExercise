/* 程式範例: Ch1-6-2a.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      11          /* 最大的陣列尺寸 */
/* 函數: 陣列元素和 */ 
int sumArray(int *data, int n) {
   int i, total = 0;
   for ( i = 0; i < n; i++ )
      total += data[i];
   return total;
}
/* 主程式 */
int main() {
   /* 變數宣告 */
   int data[MAX_LEN] =        /* 陣列內容 */
          {9, 25, 33, 74, 90, 15, 1, 8, 42, 66, 81};
   int i;
   printf("原始陣列: "); 
   for ( i = 0; i < MAX_LEN; i++ )
      printf("[%d]", data[i]); /* 顯示陣列元素 */
   printf("\n");
   printf("陣列和: %d\n", sumArray(data, MAX_LEN)); 
   system("PAUSE");
   return 0; 
}
