/* 程式範例: Ch7-5-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-5.h"
#include "createBSTree.c"
/* 函數: 二元搜尋樹的搜尋 */
BSTree searchBSTreeNode(int d) {
   BSTree ptr = head;
   while ( ptr != NULL ) {    /* 主迴圈 */
      if ( ptr->data == d )   /* 找到了 */
         return ptr;          /* 傳回節點指標 */
      else
         if ( ptr->data > d ) /* 比較資料 */
            ptr = ptr->left;  /* 左子樹 */
         else
            ptr = ptr->right; /* 右子樹 */
   }
   return NULL;               /* 沒有找到 */
}
/* 主程式 */
int main() {
   int temp = 0;
   /* 二元搜尋樹的節點資料 */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   createBSTree(9, data);     /* 建立二元搜尋樹 */
   printf("二元樹的節點內容: ");
   printBSTree();             /* 顯示二元搜尋樹 */
   while ( temp != -1 ) {
      printf("請輸入搜尋的節點資料1~9(-1結束) ==> ");
      scanf("%d", &temp);  /* 讀取節點值 */
      if ( temp != -1 )    /* 搜尋節點資料 */
         if ( searchBSTreeNode(temp) != NULL ) 
            printf("二元搜尋樹包含節點[%d]\n", temp);
         else
            printf("二元搜尋樹不含節點[%d]\n", temp);
   }  
   system("PAUSE");
   return 0;    
}
