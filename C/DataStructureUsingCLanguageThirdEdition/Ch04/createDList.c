/* 程式範例: createDList.c */
/* 函數: 建立雙向串列 */
void createDList(int len, int *array) {
   int i;
   DList newnode, before;    /* 配置第1個節點 */
   first = (DList) malloc(sizeof(DNode));
   first->data = array[0];   /* 建立節點內容 */ 
   first->previous = NULL;   /* 前節點指標為NULL */ 
   before = first;           /* 指向第一個節點 */
   now = first;              /* 重設目前節點指標 */
   for ( i = 1; i < len; i++ ) {
      /* 配置節點記憶體 */
      newnode = (DList) malloc(sizeof(DNode));
      newnode->data = array[i]; /* 建立節點內容 */ 
      newnode->next = NULL;     /* 下節點指標為NULL */ 
      newnode->previous=before; /* 將新節點指向前節點 */
      before->next=newnode;     /* 將前節點指向新節點 */
      before = newnode;         /* 新節點成為前節點 */
   }
}
/* 函數: 顯示雙向串列的節點資料 */
void printDList() {
   DList current = first;       /* 目前的節點指標 */
   while ( current != NULL ) {  /* 顯示主迴圈 */
      if ( current == now )
         printf("#%d#", current->data);
      else 
         printf("[%d]", current->data);
      current = current->next;  /* 下一個節點 */
   }
   printf("\n");
}
/* 函數: 移動節點指標到下一個節點 */
void nextNode() {
   if ( now->next != NULL )
      now = now->next;          /* 下一個節點 */
}
/* 函數: 移動節點指標到上一個節點 */ 
void previousNode() {
   if ( now->previous != NULL )
      now = now->previous;      /* 前一個節點 */
}
/* 函數: 重設節點指標 */
void resetNode() {  now = first; }
/* 函數: 取得節點指標 */
DList readNode() { return now; }
