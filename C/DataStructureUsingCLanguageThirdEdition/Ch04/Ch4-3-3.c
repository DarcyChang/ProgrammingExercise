/* 程式範例: Ch4-3-3.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch4-3.h"
#include "createList.c"
#include "insertNode.c"
/* 主程式 */
int main() {
   int temp;  /* 宣告變數 */
   int data[6]={ 1, 2, 3, 4, 5, 6 };/* 建立串列的陣列 */
   List ptr;
   createList(6, data);   /* 建立串列 */
   printf("原來的串列: ");
   printList();  /* 顯示串列 */ 
   /* 4-3-3: 節點插入 */
   temp = 0;
   insertNode(NULL, 50); /* 插入第一個節點 */
   printf("插入後串列: ");
   printList();          /* 顯示插入後串列 */
   while ( temp != -1 ) {
      printf("請輸入插入其後的郵寄編號(-1結束) ==> ");
      scanf("%d", &temp);   /* 讀取郵寄編號 */
      if ( temp != -1 ) {
         ptr = searchNode(temp); /* 找尋節點 */
         if ( ptr != NULL ) 
            printf("請輸入新的郵寄編號(0~100) ==> ");
            scanf("%d", &temp);  /* 讀取新的郵寄編號 */
            insertNode(ptr, temp);
            printf("插入後串列: ");
            printList();          /* 顯示插入後串列 */
      } 
   }
   system("PAUSE");
   return 0; 
}
