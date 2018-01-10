/* 程式範例: Ch6-2-2.h */
struct Node {              /* 佇列結構的宣告 */
   int data;               /* 資料 */
   struct Node *next;      /* 結構指標 */
};
typedef struct Node QNode; /* 佇列節點的新型態 */
typedef QNode *LQueue;     /* 串列佇列的新型態 */
LQueue front = NULL;       /* 佇列的前端 */
LQueue rear = NULL;        /* 佇列的尾端 */
/* 抽象資料型態的操作函數宣告 */
extern int isQueueEmpty();
extern void enqueue(int d);
extern int dequeue();
