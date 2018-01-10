/* 程式範例: Ch9-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      20           /* 最大陣列尺寸 */
/* 函數: 快速排序法的遞迴函數 */
void q_sort(int *data, int left, int right) {
   int partition;                /* 分割的整數 */
   int temp, i, j, k;
   if ( left < right ) {/* 遞迴中止條件, 是否繼續分割 */
      i = left;                   /* 分割的最左索引 */
      j = right + 1;              /* 分割的最右索引 */
      partition = data[left];     /* 取第一個元素 */
      do {  /* 主迴圈分別從兩個方向找尋交換元素 */ 
         do {                     /* 從左往右找 */
            i++;
         } while( data[i] < partition );
         do {                     /* 從右往左找 */
            j--;
         } while( data[j] > partition );
         if ( i < j ) {
            temp = data[i];       /* 交換資料 */
            data[i] = data[j];
            data[j] = temp;
         }
      } while( i < j );
      temp = data[left];          /* 交換資料 */
      data[left] = data[j];
      data[j] = temp;
      printf("輸出結果: ");  /* 顯示處理中的字串 */
      for ( k = left; k <= right; k++)
         printf("%d", data[k]);
      printf("\n");               /* 換行 */
      q_sort(data, left, j-1);    /* 快速排序遞迴呼叫 */
      q_sort(data, j+1, right);   /* 快速排序遞迴呼叫 */
   }
}
/* 函數: 快速排序法 */
void quickSort(int *data, int count) {
   q_sort(data, 0, count-1);
}
/* 主程式 */ 
int main() {
   int data[MAX_LEN];             /* 整數陣列 */
   int i, key = 1, len = 0;       /* 陣列尺寸 */
   while ( key != -1 ) {
      printf("輸入欲排序的整數 ==> ");
      scanf("%d", &key);          /* 讀取整數 */
      if ( key > 0 ) {            /* 只儲存正整數 */ 
         data[len++] = key;       /* 更新陣列索引 */
      }
   }
   quickSort(data, len);          /* 執行快速排序法 */
   /* 顯示排序後的整數陴列 */
   printf("\n輸出排序結果: ");
   for ( i = 0; i < len; i++ )
      printf("[%d]", data[i]);
   printf("\n");
   system("PAUSE");
   return 0; 
}
