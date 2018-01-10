/* 程式範例: Ch12-2-3.c */
#include <stdio.h>
#include <stdlib.h>
#define  MAX_LEN   8
#include "Ch12-2.h"
#include "createAvlTree.c"
#include "deleteAvlNode.c"
/* 主程式 */ 
int main() {
   /* AVL樹的節點資料 */
   int data[MAX_LEN]={50,20,80,10,30,60, 90,70};
   int target = 0;
   createAvlTree(MAX_LEN, data);   /* 建立AVL樹 */ 
   printf("AVL樹: ");
   printAvlTree();                 /* 顯示AVL樹 */
   while ( target != -1 ) {
      printf("請輸入刪除的節點資料(-1結束) ==> ");
      scanf("%d", &target);  /* 讀取節點值 */
      if ( target != -1 ) {  /* 有刪除節點資料 */
         if (deleteAvlNode(target)) { /* 刪除節點 */
            printf("刪除後: ");
            printAvlTree();        /* 顯示AVL樹 */
         }   
         else printf("沒有找到刪除節點...\n");
      }       
   }  
   system("PAUSE");
   return 0; 
}
