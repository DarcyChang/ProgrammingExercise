/* 程式範例: Ch4-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch4-3.h"
#include "createList.c"
/* 主程式 */
int main() {
   int temp;  /* 宣告變數 */
   int data[6]={ 1, 2, 3, 4, 5, 6 };/* 建立串列的陣列 */
   List ptr;
   /* 4-3-1: 建立, 走訪與搜尋串列 */ 
   createList(6, data);   /* 建立串列 */
   printf("原來的串列: ");
   printList();  /* 顯示串列 */
   printf("串列是否空的: %d\n", isListEmpty());
   temp = 0; 
   while ( temp != -1 ) {
      printf("請輸入搜尋的郵寄編號(-1結束) ==> ");
      scanf("%d", &temp);  /* 讀取節點值 */
      if ( temp != -1 )    /* 搜尋節點資料 */
         if ( searchNode(temp) != NULL ) 
            printf("串列包含節點[%d]\n", temp);
         else
            printf("串列不含節點[%d]\n", temp);
   }  
   system("PAUSE");
   return 0; 
}
