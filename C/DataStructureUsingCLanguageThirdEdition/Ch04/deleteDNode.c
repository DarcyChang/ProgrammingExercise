/* 程式範例: deleteDNode.c */
/* 函數: 刪除節點 */
void deleteDNode(DList ptr) {
   if ( ptr->previous == NULL ) { /* 是否有前一個節點 */
      /* 情況1: 刪除第一個節點 */
      first = first->next;      /* 指向下一個節點 */
      first->previous = NULL;   /* 設定指向前節點指標 */
   }
   else {
      if ( ptr->next == NULL ) {  /* 是否有下一個節點 */
         /* 情況2: 刪除最後一個節點 */
         ptr->previous->next = NULL;/* 前節點指向NULL */
      }
      else {
         /* 情況3: 刪除中間的節點 */
         /* 前節點指向下一節點 */
         ptr->previous->next = ptr->next;
         /* 下一節點指向前節點 */
         ptr->next->previous = ptr->previous;
      }
   }
   free(ptr);                /* 釋回刪除節點記憶體 */
}
