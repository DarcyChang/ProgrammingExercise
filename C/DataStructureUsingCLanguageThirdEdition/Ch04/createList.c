/* 程式範例: createList.c */
/* 函數: 建立串列 */
void createList(int len, int *array) {
   int i;
   List newnode;
   for ( i = 0; i < len; i++ ) {
      /* 配置節點記憶體 */
      newnode = (List) malloc(sizeof(LNode));
      newnode->data = array[i]; /* 建立節點內容 */ 
      newnode->next = first;
      first = newnode;
   }
}
/* 函數: 檢查串列是否是空的 */
int isListEmpty() {
   if ( first == NULL ) return 1;
   else                 return 0;
}
/* 函數: 顯示串列資料 */
void printList() {
   List current = first;  /* 目前的串列指標 */
   while ( current != NULL ) { /* 顯示主迴圈 */
      printf("[%d]", current->data);
      current = current->next;  /* 下一個節點 */
   }
   printf("\n");
}
/* 函數: 搜尋節點資料 */
List searchNode(int d) {
   List current = first;   /* 目前的串列指標 */
   while ( current != NULL ) { /* 搜尋主迴圈 */
      if ( current->data == d ) /* 是否找到資料 */
         return current; /* 找到 */
      current = current->next;  /* 下一個節點 */
   }
   return NULL;          /* 沒有找到 */
}
