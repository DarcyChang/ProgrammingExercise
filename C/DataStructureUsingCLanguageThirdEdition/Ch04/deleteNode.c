/* 程式範例: deleteNode.c */
/* 函數: 刪除節點 */
int deleteNode(List ptr) {
   List current = first;   /* 指向前一節點 */
   int value = ptr->data;  /* 取得刪除的節點值 */
   if ( isListEmpty() )    /* 檢查串列是否是空的 */
      return -1;
   if (ptr==first || ptr==NULL) {/* 串列開始或NULL */
      /* 情況1: 刪除第一個節點 */
      first = first->next;       /* 刪除第1個節點 */
   } else {     
      while (current->next!=ptr) /* 找節點ptr的前節點 */
         current = current->next;
      if ( ptr->next == NULL )    /* 是否是串列結束 */
         /* 情況2: 刪除最後一個節點 */
         current->next = NULL;    /* 刪除最後一個節點 */
      else
         /* 情況3: 刪除中間節點 */
         current->next = ptr->next; /* 刪除中間節點 */
   }
   free(ptr);                     /* 釋放節點記憶體 */
   return value;                  /* 傳回刪除的節點值 */
}
