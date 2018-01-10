/* 程式範例: Ch5-2-2.h */
struct Node {                  /* 堆疊節點的宣告 */
   int data;                   /* 儲存堆疊資料 */
   struct Node *next;          /* 指向下一節點 */
};
typedef struct Node SNode;     /* 堆疊節點的新型態 */ 
typedef SNode *LStack;         /* 串列堆疊的新型態 */
LStack top = NULL;             /* 堆疊頂端的指標 */
/* 抽象資料型態的操作函數宣告 */ 
extern int isStackEmpty();
extern void push(int d);
extern int pop();
