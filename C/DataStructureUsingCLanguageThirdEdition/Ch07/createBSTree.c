/* 程式範例: createBSTree.c */
/* 函數: 建立二元搜尋樹 */
void createBSTree(int len, int *array) {
   int i; 
   /* 使用迴圈以插入方式建立樹狀結構 */
   for ( i = 0; i < len; i++ ) 
      insertBSTreeNode(array[i]);
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
/* 函數: 檢查二元搜尋樹是否是空的 */
int isBSTreeEmpty() {
   if ( head == NULL ) return 1;
   else                return 0; 
}
/* 函數: 以中序走訪顯示二元搜尋樹 */
void printBSTree() {
   inOrder(head, "[%d]");  /* 呼叫中序走訪函數 */
   printf("\n");
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
/* 函數: 二元搜尋樹的前序走訪 */
void preOrder(BSTree ptr, char *f) {
   if ( ptr != NULL ) {         /* 終止條件 */
      /* 顯示節點內容 */
      printf(f, ptr->data);
      preOrder(ptr->left, f);   /* 左子樹 */
      preOrder(ptr->right, f);  /* 右子樹 */
   }
}
/* 函數: 二元搜尋樹的後序走訪 */
void postOrder(BSTree ptr, char *f) {
   if ( ptr != NULL ) {          /* 終止條件 */
      postOrder(ptr->left, f);   /* 左子樹 */
      postOrder(ptr->right, f);  /* 右子樹 */
      /* 顯示節點內容 */
      printf(f, ptr->data);
   }
}
