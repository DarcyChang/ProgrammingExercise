/* 程式範例: createAvlTree.c */
#include <stdio.h>
#include <stdlib.h>
/* 函數: 取得子樹的最大樹高 */
static int h(AvlTree ptr) {
   if ( ptr == NULL ) return  0;  /* 空子節點 */ 
   else  return ptr->height + 1;  /* 目前樹高加一 */ 
}
/* 函數: 計算平衡因子Balanced Factor */
static int bf(AvlTree ptr) {
   return h(ptr->left)-h(ptr->right); /* 左減右子樹高 */
}
/* 函數: 計算左右子樹的最大樹高 */
static int maxH(int lhights, int rhights) {
   return lhights > rhights ? lhights : rhights;
}
/* 函數: LL型 */
static AvlTree singleRotateLL(AvlTree ptr) {
   AvlTree temp = ptr->left;      /* 子變父節點 */ 
   ptr->left = temp->right;       /* 連結右子樹 */ 
   temp->right = ptr;             /* 父變子節點 */ 
   ptr->height = maxH(h(ptr->left),h(ptr->right));
   temp->height = maxH(h(temp->left),ptr->height);
   printf("LL[%d]\n", ptr->data);
   return temp;
}
/* 函數: RR型 */
static AvlTree singleRotateRR(AvlTree ptr) {
   AvlTree temp = ptr->right;     /* 子變父節點 */
   ptr->right = temp->left;       /* 連結左子樹 */
   temp->left = ptr;              /* 父變子節點 */ 
   ptr->height = maxH(h(ptr->left),h(ptr->right));
   temp->height = maxH(ptr->height,h(temp->right));
   printf("RR[%d]\n", ptr->data); 
   return temp;
}
/* 函數: LR型 */
static AvlTree doubleRotateLR(AvlTree ptr) {
   printf("LR[%d]\n", ptr->data);     
   ptr->left = singleRotateRR(ptr->left);  /* RR */ 
   return singleRotateLL(ptr);             /* LL */
}
/* 函數: RL型 */
static AvlTree doubleRotateRL(AvlTree ptr) {
   printf("RL[%d]\n", ptr->data);     
   ptr->right = singleRotateLL(ptr->right); /* LL */
   return singleRotateRR(ptr);              /* RR */
}
/* 函數: 插入節點至AVL樹 */
AvlTree insertAvlNode(int data, AvlTree ptr) {
   if ( ptr == NULL ) { /* 建立節點記憶體 */ 
      ptr = (AvlTree) malloc( sizeof(AvlNode));
      ptr->data = data;
      ptr->height = 1;
      ptr->left = ptr->right = NULL;
   }
   else if ( data < ptr->data ) { /* 往左子樹 */ 
           ptr->left = insertAvlNode(data, ptr->left);
           if ( bf(ptr) == 2 )   /* 不平衡 */ 
              if (  bf(ptr->left) == 1 )
                 ptr = singleRotateLL(ptr); /* LL */
              else
                 ptr = doubleRotateLR(ptr); /* LR */
   }
   else if ( data > ptr->data ) { /* 往右子樹 */ 
           ptr->right = insertAvlNode(data, ptr->right);
           if ( bf(ptr) == -2 )    /* 不平衝 */
              if ( bf(ptr->right) == -1 )
                 ptr = singleRotateRR(ptr); /* RR */
              else
                 ptr = doubleRotateRL(ptr); /* RL */
   }
   ptr->height = maxH(h(ptr->left), h(ptr->right));
   return ptr;
}
/* 函數: 建立AVL樹 */
void createAvlTree(int len, int *array) {
   int i; /* 使用迴圈以插入方式建立樹狀結構 */
   for ( i = 0; i < len; i++ ) 
      head = insertAvlNode(array[i], head);
}
/* 函數: AVL樹的中序走訪 */
static void inOrder(AvlTree ptr, char *f) {
   if ( ptr != NULL ) {         /* 終止條件 */
      inOrder(ptr->left, f);    /* 左子樹 */
      /* 顯示節點內容 */
      printf(f, ptr->data, ptr->height, bf(ptr));
      inOrder(ptr->right, f);   /* 右子樹 */
   }
}
/* 函數: 顯示AVL樹 */
void printAvlTree() {
   inOrder(head, "%d(%d/%d) ");  /* 呼叫中序走訪函數 */
   printf("\n");
}
