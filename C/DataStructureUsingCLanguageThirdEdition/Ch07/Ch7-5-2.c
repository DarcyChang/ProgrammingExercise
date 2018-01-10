/* 程式範例: Ch7-5-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch7-5.h"
#include "createBSTree.c"
/* 函數: 二元搜尋樹的節點刪除 */
void deleteBSTreeNode(int d) {
   BSTree parent;      /* 父節點指標 */
   BSTree ptr;         /* 刪除節點指標 */
   BSTree child;       /* 子節點指標 */
   int isfound = 0;    /* 是否找到刪除節點 */ 
   /* 找尋刪除節點和其父節點指標 */
   parent = ptr = head;
   while ( ptr != NULL && !isfound ) { /* 主迴圈 */
      if ( ptr->data == d )   
         isfound = 1;         /* 找到刪除節點 */
      else {
         parent = ptr;        /* 保留父節點指標 */
         if ( ptr->data > d ) /* 比較資料 */
             ptr = ptr->left; /* 左子樹 */
         else
             ptr = ptr->right;/* 右子樹 */
      }       
   }
   if ( ptr == NULL ) return;  /* 沒有找到刪除節點 */
   /* 刪除二元搜尋樹的節點, 情況1: 葉節點 */
   if ( ptr->left == NULL && ptr->right == NULL ) {
      if ( parent->left == ptr )
         parent->left = NULL; /* 左子節點 */
      else
         parent->right = NULL; /* 右子節點 */ 
      free(ptr);               /* 釋回節點記憶體     */
      return;
   }
   /* 情況2: 沒有左子樹 */
   if ( ptr->left == NULL ) {
      if ( parent != ptr )     /* 相等是根節點 */
         if ( parent->left == ptr )
            parent->left = ptr->right; /* 左子節點 */ 
         else parent->right = ptr->right; /* 右子節點 */ 
      else head = head->right;/* 根節點指向右子節點 */
      free(ptr);               /* 釋回節點記憶體     */
      return;
   } /* 情況3: 沒有右子樹 */
   if ( ptr->right == NULL ) {
      if ( parent != ptr )     /* 相等是根節點 */
         if ( parent->right == ptr )
             parent->right = ptr->left;/* 右子節點 */ 
         else parent->left = ptr->left;/* 左子節點 */ 
      else head = head->left;  /* 根節點指向左子節點 */
      free(ptr);               /* 釋回節點記憶體     */
      return;
   } /* 情況4: 有左子樹和右子樹 */
   parent = ptr;                /* 父節點指向刪除節點 */
   child = ptr->left;             /* 設定成左子節點 */
   while ( child->right!=NULL ) { /* 找到最右的葉節點 */
      parent = child;             /* 保留父節點指標 */
      child = child->right;       /* 往右子樹走 */
   }
   ptr->data = child->data;       /* 設定成葉節點資料 */
   if ( parent->left == child )   /* 子節點沒有右子樹 */
      parent->left = NULL;       
   else parent->right = child->left;/* 連結左邊葉節點 */
   free(child);                   /* 釋回節點記憶體 */
   return;
}
/* 主程式 */
int main() {
   int temp = 0;
   /* 二元搜尋樹的節點資料 */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   createBSTree(9, data);     /* 建立二元搜尋樹 */
   printf("刪除前的節點內容: ");
   printBSTree();             /* 顯示二元搜尋樹 */
   while ( temp != -1 ) {
      printf("請輸入刪除的節點資料1~9(-1結束) ==> ");
      scanf("%d", &temp);  /* 讀取節點值 */
      if ( temp != -1 ) {  /* 刪除節點資料 */
         deleteBSTreeNode(temp); /* 刪除節點 */
         printf("刪除後的節點內容: ");
         printBSTree();          /* 顯示二元搜尋樹 */
      }   
   }  
   system("PAUSE");
   return 0;    
}
