/* 程式範例: stack.c */
struct Node {                  /* 堆疊節點的宣告 */
   int data;                   /* 儲存堆疊資料 */
   struct Node *next;          /* 指向下一節點 */
};
typedef struct Node SNode;     /* 堆疊節點的新型態 */ 
typedef SNode *LStack;         /* 串列堆疊的新型態 */
LStack top = NULL;             /* 堆疊頂端的指標 */
/* 函數: 檢查堆疊是否是空的 */
int isStackEmpty() {
   if ( top == NULL ) return 1;
   else               return 0;
}
/* 函數: 將資料存入堆疊 */
void push(int d) {
   LStack new_node;            /* 新節點指標 */
   /* 配置節點記憶體 */
   new_node = (LStack)malloc(sizeof(SNode));
   new_node->data = d;         /* 建立節點內容 */
   new_node->next = top;       /* 新節點指向原開始 */
   top = new_node;             /* 新節點成為堆疊開始 */   
}
/* 函數: 從堆疊取出資料 */
int pop() {
   LStack ptr;                 /* 指向堆疊頂端 */
   int temp;
   if ( !isStackEmpty()  ) {   /* 堆疊是否是空的 */
      ptr = top;               /* 指向堆疊頂端 */
      top = top->next;         /* 堆疊指標指向下節點 */
      temp = ptr->data;        /* 取出資料 */
      free(ptr);               /* 釋回節點記憶體 */
      return temp;             /* 堆疊取出 */
   }
   else return -1;
}
