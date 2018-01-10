/* 程式範例: Ch9-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      20           /* 最大陣列尺寸 */
/* 函數: 合併陣列 */ 
void merge(int *data,int start,int mid,int end) {
    int left = start;              /* 左半部的索引 */ 
    int right = mid + 1;           /* 右半部的索引 */ 
    int i, k, *finalData; 
    /* 配置合併區段所需的記憶體空間 */ 
    finalData = (int*) malloc(sizeof(int)*(end-start+1)); 
    /* 合併左右兩半部分區段的迴圈 */
    for (i = 0; i < (end-start+1); i++) {
        if ( left > mid ) { 
            finalData[i] = data[right];
            right++; 
        } else if ( right > end ) { 
            finalData[i] = data[left];
            left++; 
        } else if (data[left] < data[right]) {
            finalData[i] = data[left];
            left++; 
        } else { 
            finalData[i] = data[right];
            right++; 
        } 
    }
    /* 複製到原始陣列的區段 */ 
    for (i = 0; i < (end-start+1); i++) { 
        data[start + i] = finalData[i]; 
    } /* 顯示合併後的陣列內容 */
    printf("%d-%d-%d: ",start,mid,end);
    for ( k = 0; k < (end-start+1); k++ )
         printf("[%d]", finalData[k]);
    printf("\n");       
}
/* 函數: 合併排序法 */ 
void mergeSort(int *data, int start, int end) { 
    int mid; 
    if ( end <= start ) return;    /* 終止條件 */ 
    mid = (start + end) / 2;       /* 中間索引 */ 
    mergeSort(data, start, mid);   /* 遞迴排序左半邊 */
    mergeSort(data, mid+1, end);   /* 遞迴排序右半邊 */
    merge(data, start, mid, end);  /* 合併陣列 */    
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
   mergeSort(data, 0, len-1);     /* 執行合併排序法 */
   /* 顯示排序後的整數陴列 */
   printf("\n輸出排序結果: ");
   for ( i = 0; i < len; i++ )
      printf("[%d]", data[i]);
   printf("\n");
   system("PAUSE");
   return 0; 
}
