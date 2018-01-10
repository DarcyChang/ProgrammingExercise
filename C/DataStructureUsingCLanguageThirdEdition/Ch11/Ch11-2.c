/* 程式範例: Ch11-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "createHeap.c"
/* 主程式 */ 
int main() {
   /* 二元樹的節點資料 */
   int data[10] = { 0, 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   int i;
   printf("二元樹內容: ");
   for ( i = 1; i < 10; i++ ) {    /* 顯示二元樹內容 */
      printf("[%d]", data[i]);
      insertHeap(data[i]);
   }
   printf("\n");
   printHeap();
   printf("刪除節點 = %d\n", removeHeap());
   printHeap();
   printf("刪除節點 = %d\n", removeHeap());
   printHeap();
   system("PAUSE");
   return 0; 
}
