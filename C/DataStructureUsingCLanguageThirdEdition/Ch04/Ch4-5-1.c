/* 程式範例: Ch4-5-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch4-5.h"
#include "createDList.c"
/* 主程式 */
int main() {
   int temp = 1;  /* 宣告變數 */
   int data[6]={ 1, 2, 3, 4, 5, 6 };/* 建立串列的陣列 */
   /* 4-5-1: 建立與走訪雙向串列 */
   createDList(6, data);   /* 建立雙向串列 */
   while ( temp != 5 ) {
      printf("原來的串列: ");
      printDList();  /* 顯示雙向串列 */ 
      printf("[1]往下移動 [2]往前移動 ");
      printf("[3]重設 [4]節點值 [5]離開 ==> ");
      scanf("%d", &temp);        /* 讀入選項 */
      switch ( temp ) {
         case 1: nextNode();     /* 往下移動 */
            break;
         case 2: previousNode(); /* 往前移動 */ 
            break;
         case 3: resetNode();    /* 重設指標 */ 
            break;
         case 4: /* 讀取節點值 */
            printf("節點值: %d\n", readNode()->data); 
            break;
      }
   }      
   system("PAUSE");
   return 0; 
}
