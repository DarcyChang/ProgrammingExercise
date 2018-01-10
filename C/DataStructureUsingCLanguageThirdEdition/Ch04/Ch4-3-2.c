/* 程式範例: Ch4-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch4-3.h"
#include "createList.c"
#include "deleteNode.c"
/* 主程式 */
int main() {
   int temp;  /* 宣告變數 */
   int data[6]={ 1, 2, 3, 4, 5, 6 };/* 建立串列的陣列 */
   List ptr;
   createList(6, data);   /* 建立串列 */
   printf("原來的串列: ");
   printList();  /* 顯示串列 */ 
   /* 4-3-2: 節點刪除 */
   temp = 0; 
   while ( temp != -1 ) {
      printf("請輸入刪除的郵寄編號(-1結束) ==> ");
      scanf("%d", &temp);  /* 讀取郵寄編號 */
      if ( temp != -1 ) {  /* 搜尋節點資料 */
         ptr = searchNode(temp);  /* 找尋節點 */
         if ( ptr != NULL ) {
            temp = deleteNode(ptr); /* 刪除節點 */
            printf("刪除節點: %d\n", temp); 
            printf("刪除後串列: ");
            printList();        /* 顯示刪除後串列 */
         }         
      }
   }
   system("PAUSE");
   return 0; 
}
