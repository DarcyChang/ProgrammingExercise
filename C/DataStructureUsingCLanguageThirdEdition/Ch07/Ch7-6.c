/* 程式範例: Ch7-6.c */
#include <stdio.h>
#include <stdlib.h>
struct TNode {            /* 引線二元樹的節點宣告 */
   int data;              /* 儲存節點資料 */ 
   struct TNode *left;    /* 指向左子樹的指標 */
   struct TNode *right;   /* 指向右子樹的指標 */
   int isThread;          /* 右指標是否是引線 */
};
typedef struct TNode RTNode;/* 引線二元樹節點新型態 */
typedef RTNode *RTBTree;    /* 引線二元樹的新型態 */
RTBTree head = NULL;        /* 引線二元樹根節點的指標 */
/* 函數: 引線二元樹的節點插入的遞迴函數 */
void insertRTNode(RTBTree parent, int d) {
   RTBTree newnode;   
   if ( d < parent->data ) { /* 往左 */
      if ( parent->left == NULL ) {
         /* 建立左子節點, 配置新節點的記憶體 */
         parent->left = (RTBTree) malloc(sizeof(RTNode));
         parent->left->data = d;   /* 建立節點內容 */ 
         parent->left->left = NULL;
         parent->left->right = parent;
         parent->left->isThread = 1;  /* 是引線 */
      }     /* 遞迴往左下一層 */
      else  insertRTNode(parent->left, d);
   }
   else { /* 往右 */
      if ( parent->isThread == 1 ) { /* 是否是引線 */
         /* 建立右子節點, 配置新節點的記憶體 */
         newnode = (RTBTree) malloc(sizeof(RTNode));
         newnode->data = d;     /* 建立節點內容 */ 
         newnode->left = NULL;
         newnode->right = parent->right;
         newnode->isThread = 1; /* 是引線 */
         parent->right = newnode;
         parent->isThread = 0;  /* 不是引線 */
      }    /* 遞迴往右下一層 */
      else insertRTNode(parent->right, d);
   } 
}
/* 函數: 建立引線二元樹 */
void createRTBTree(int len, int *array) {
   int i; 
   /* 建立根節點 */ 
   head = (RTBTree) malloc(sizeof(RTNode));
   head->data = array[0];      
   head->left = NULL;
   head->right = NULL;
   head->isThread = 1;
   /* 使用迴圈建立樹狀結構 */
   for ( i = 1; i < len; i++ )
      insertRTNode(head, array[i]); /* 插入節點 */
}
/* 函數: 中序走訪引線二元樹 */
void printRTBTree() {
   RTBTree ptr = NULL;
   int haveNext = 1;
   while ( haveNext ) {  /* 中序走訪迴圈 */
      if ( ptr == NULL ) {
         ptr = head;    /* 指向根節點 */
         while ( ptr->left != NULL )  /* 往左子樹走 */
            ptr = ptr->left;
      }
      else {
         if ( ptr->isThread == 1 )  /* 是否是引線 */
            ptr = ptr->right;       /* 往右子樹走 */
         else {
            ptr = ptr->right;       /* 先到右子節點 */
            while ( ptr->left != NULL )  /* 往左子樹走 */
               ptr = ptr->left;         
         }
      }
      if ( ptr == NULL ) haveNext = 0;
      else printf("[%d]",ptr->data);  /* 顯示節點 */
   }
   printf("\n");
}
/* 主程式 */
int main() {
   /* 二元樹的節點資料 */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   createRTBTree(9, data);     /* 建立引線二元樹 */
   printf("右引線二元樹的中序走訪: \n");
   printRTBTree();   
   system("PAUSE");
   return 0; 
}
