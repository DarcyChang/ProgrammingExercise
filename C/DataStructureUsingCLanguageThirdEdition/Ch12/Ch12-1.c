/* 程式範例: Ch12-1.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      9     /* 最大陣列尺寸 */
struct Node {              /* 二元樹的節點宣告 */
   int data;              /* 儲存節點資料 */ 
   struct Node *left;      /* 指向左子樹的指標 */
   struct Node *right;     /* 指向右子樹的指標 */          
};
typedef struct Node TNode;/* 二元樹節點的新型態 */
typedef TNode *BSTree;    /* 二元搜尋樹的新型態 */
BSTree head = NULL;       /* 二元搜尋樹根節點的指標 */
/* 函數: 檢查二元搜尋樹是否是空的 */
int isBSTreeEmpty() {
   if ( head == NULL ) return 1;
   else                return 0; 
}
/* 函數: 二元搜尋樹的節點插入) */
void insertBSTreeNode(int d) {
   BSTree newnode, current; /* 目前二元樹節點指標 */
   int inserted = 0; /* 是否插入新節點 */
   /* 配置新節點的記憶體 */
   newnode = (BSTree) malloc(sizeof(TNode));
   newnode->data = d;      /* 建立節點內容 */ 
   newnode->left = NULL;
   newnode->right = NULL;
   if ( isBSTreeEmpty() )  /* 是否空二元樹 */
      head = newnode;      /* 建立根節點 */
   else {  /* 保留目前二元樹指標 */
      current = head; 
      while( !inserted )    /* 比較節點值 */
         if ( current->data > newnode->data ) {
            /* 是否是最左的子節點 */
            if ( current->left == NULL ) {   
                current->left = newnode; /* 建立鏈結 */
                inserted = 1;
            } else current = current->left;/* 左子樹 */
         }
         else {  /* 是否是最右的子節點 */
            if ( current->right == NULL ) {
                current->right = newnode; /* 建立鏈結 */
                inserted = 1;
            } else current = current->right;/* 右子樹 */
         }
   }
}
/* 函數: 建立二元搜尋樹 */
void createBSTree(int len, int *array) {
   int i; 
   /* 使用迴圈以插入方式建立樹狀結構 */
   for ( i = 0; i < len; i++ ) 
      insertBSTreeNode(array[i]);
}
/* 函數: 二元搜尋樹的中序走訪 */
void inOrder(BSTree ptr, char *f) {
   if ( ptr != NULL ) {         /* 終止條件 */
      inOrder(ptr->left, f);    /* 左子樹 */
      /* 顯示節點內容 */
      printf(f, ptr->data); 
      inOrder(ptr->right, f);   /* 右子樹 */
   }
}
/* 函數: 二元搜尋樹排序法 */
void BSTreeSort() {
   inOrder(head, "[%d]");  /* 呼叫中序走訪函數 */
   printf("\n");
}
/* 函數: 二元搜尋樹搜尋法 */
int BSTreeSearch(BSTree ptr, int d) {
   if ( ptr != NULL ) {           /* 終止條件 */
      if ( ptr->data == d )       /* 找到了 */
         return 1;
      else if ( ptr->data > d )   /* 往左子樹找 */
            return BSTreeSearch(ptr->left, d);
         else                     /* 往右子樹找 */
            return BSTreeSearch(ptr->right, d);
   } else return 0;               /* 沒有找到 */
}
/* 主程式 */ 
int main() {
   /* 二元樹節點資料 */
   int data[MAX_LEN]={55,61,41,87,24,35,79,11,99};
   int target;
   createBSTree(MAX_LEN, data);   /* 建立二元搜尋樹 */ 
   printf("輸出排序結果: ");
   BSTreeSort();              /* 執行二元搜尋樹排序法 */
   target = 0;
   while ( target != -1 ) {
      printf("請輸入搜尋值(-1結束) ==> ");
      scanf("%d", &target);
      /* 呼叫二元搜尋樹搜尋法的搜尋函數 */ 
      if ( BSTreeSearch(head, target))
          printf("搜尋到鍵值: %d\n", target);
      else
          printf("沒有搜尋到鍵值: %d\n", target);
   }
   system("PAUSE");
   return 0; 
}
