/* 程式範例: deleteAvlNode.c */
#include <stdio.h>
#include <stdlib.h>
/* 函數: 重建AVL樹 */
static AvlTree rebuildAVL(AvlTree ptr) {
   if ( ptr != NULL ) {   /* 終止條件 */
      ptr->left = rebuildAVL(ptr->left);  /* 左子樹 */ 
      ptr->right = rebuildAVL(ptr->right);/* 右子樹 */ 
      if ( bf(ptr) == 2 )   /* 不平衡 */ 
         if (  bf(ptr->left) == 1 )
            ptr = singleRotateLL(ptr); /* LL */
         else
            ptr = doubleRotateLR(ptr); /* LR */
      if ( bf(ptr) == -2 )    /* 不平衝 */
         if ( bf(ptr->right) == -1 )
            ptr = singleRotateRR(ptr); /* RR */
         else
            ptr = doubleRotateRL(ptr); /* RL */
      /* 指定最高的子樹高 */     
      ptr->height = maxH(h(ptr->left), h(ptr->right));
   }   
   return ptr;
}
/* 函數: 以BSTree方法來刪除節點 */
static int deleteBSTreeNode(int d) {
   AvlTree parent;      /* 父節點指標 */
   AvlTree ptr;         /* 刪除節點指標 */
   AvlTree child;       /* 子節點指標 */
   int isfound = 0;     /* 是否找到刪除節點 */ 
   /* 找尋刪除節點,其父節點指標 */
   parent = ptr = head;
   while ( ptr != NULL && !isfound ) { /* 主迴圈 */
      if ( ptr->data == d ) isfound = 1; /* 找到節點 */
      else {
         parent = ptr;        /* 保留父節點指標 */
         if ( ptr->data > d ) /* 比較資料 */
              ptr = ptr->left; /* 左子樹 */
         else ptr = ptr->right;/* 右子樹 */
      }       
   }
   if ( ptr == NULL ) return 0;  /* 沒有找到節點 */
   /* 刪除AVL樹的節點, 情況1: 葉節點 */
   if ( ptr->left == NULL && ptr->right == NULL ) {
      if ( parent->left == ptr )
         parent->left = NULL;  /* 左子節點 */
      else
         parent->right = NULL; /* 右子節點 */
      free(ptr);               /* 釋回節點記憶體 */
      return 1;                /* 已刪除 */ 
   }
   /* 情況2: 沒有左子樹 */
   if ( ptr->left == NULL ) {
      if ( parent->left == ptr )
         parent->left = ptr->right; /* 左子節點 */ 
      else parent->right = ptr->right; /* 右子節點 */
      free(ptr);               /* 釋回節點記憶體 */
      return 1;                /* 已刪除 */ 
   } /* 情況3: 沒有右子樹 */
   if ( ptr->right == NULL ) {
      if ( parent->right == ptr )
         parent->right = ptr->left; /* 右子節點 */ 
      else parent->left = ptr->left;/* 左子節點 */ 
      free(ptr);               /* 釋回節點記憶體 */
      return 1;                /* 已刪除 */ 
   } /* 情況4: 有左子樹和右子樹 */
   if ( ptr->left != NULL && ptr->right != NULL ) {
      parent = ptr;              /* 父節點指向刪除節點 */
      child = ptr->left;             /* 設定成左子節點 */
      while ( child->right!=NULL ) { /* 找到最右葉節點 */
         parent = child;             /* 保留父節點指標 */
         child = child->right;       /* 往右子樹走 */
      }
      ptr->data = child->data;     /* 設定成葉節點資料 */
      if ( parent->left == child ) /* 子節點沒有右子樹 */
         parent->left = NULL;       
      else parent->right=child->left;/* 連結左邊葉節點 */
      free(child);                   /* 釋回節點記憶體 */
      return 1;                      /* 已刪除 */
   } 
   return 1;                         /* 成功刪除 */ 
}

/* 函數: 刪除AVL樹的節點 */
int deleteAvlNode(int d) {
   if ( deleteBSTreeNode(d) == 0 ) return 0; /* 沒有找到 */
   else head = rebuildAVL(head);             /* 重建AVL樹 */
   return 1;                         /* 成功刪除 */ 
}
