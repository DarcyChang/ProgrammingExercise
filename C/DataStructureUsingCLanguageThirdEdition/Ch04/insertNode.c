/* 程式範例: insertNode.c */
/* 函數: 插入節點 */
void insertNode(List ptr, int d) {   
   List newnode;
   /* 配置節點記憶體 */
   newnode = (List) malloc(sizeof(LNode));
   newnode->data = d;          /* 指定節點值 */ 
   if ( ptr == NULL ) {
      /* 情況1: 插入第一個節點 */
      newnode->next = first;   /* 新節點成為串列開始 */
      first = newnode;
   }
   else {
      if ( ptr->next == NULL ) { /* 串列最後一個節點 */
        /* 情況2: 插入最後一個節點 */
        ptr->next = newnode;     /* 最後指向新節點 */
        newnode->next = NULL;    /* 新節點指向NULL */ 
      }  
      else {
        /* 情況3: 插入成為中間節點 */
        newnode->next=ptr->next;/* 新節點指向下一節點 */
        ptr->next = newnode;    /* 節點ptr指向新節點 */
      }
   }
}
