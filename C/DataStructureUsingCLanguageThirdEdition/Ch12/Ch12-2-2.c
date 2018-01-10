/* 程式範例: Ch12-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#define  MAX_LEN     6
#include "Ch12-2.h"
#include "createAvlTree.c"
/* 主程式 */ 
int main() {
   /* AVL樹的節點資料 */
   int data[MAX_LEN]={50, 20, 60, 10, 40, 30};
   createAvlTree(MAX_LEN, data);   /* 建立AVL樹 */ 
   printf("AVL樹節點內容: ");
   printAvlTree();                 /* 顯示AVL樹 */
   system("PAUSE");
   return 0; 
}
