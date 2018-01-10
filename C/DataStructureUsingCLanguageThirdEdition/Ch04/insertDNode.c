/* 程式範例: insertDNode.c */
/* 函數: 插入節點 */
void insertDNode(DList ptr, int d) { 
   /* 配置節點記憶體 */
   DList newnode = (DList) malloc(sizeof(DNode));
   newnode->data = d;      /* 建立節點內容 */ 
   if ( first == NULL )         /* 如果串列是空的 */
      first = newnode;          /* 傳回新節點指標 */
   if ( ptr == NULL ) {
      /* 情況1: 插在第一個節點之前, 成為串列開始 */
      newnode->previous = NULL; /* 前指標為NULL */ 
      newnode->next = first;    /* 新節點指向串列開始 */
      first->previous = newnode;/* 原節點指向新節點 */
      first = newnode;          /* 新節點成為串列開始 */
   }
   else {
      if ( ptr->next == NULL ) {/* 是否是最後一個節點 */
         /* 情況2: 插在串列的最後 */
         ptr->next = newnode;   /* 最後節點指向新節點 */
         newnode->previous=ptr; /* 新節點指回最後節點 */
         newnode->next = NULL;  /* 後回指標為NULL */ 
      }
      else {
         /* 情況3: 插入節點至串列的中間節點 */
         ptr->next->previous = newnode; /* 指回新節點 */
         newnode->next = ptr->next;  /* 指向下一節點 */
         newnode->previous=ptr; /* 新節點指回插入節點 */
         ptr->next = newnode;   /* 插入節點指向新節點 */
      }
   }
}
