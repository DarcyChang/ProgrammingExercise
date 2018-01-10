/* 程式範例: Ch6-4-2.h */
struct Node {              /* 佇列結構的宣告 */
   int data;               /* 資料 */
   struct Node *next;      /* 結構指標 */
};
typedef struct Node QNode; /* 雙佇列節點的新型態 */
typedef QNode *LDeque;     /* 串列雙佇列的新型態 */
LDeque front = NULL;       /* 雙佇列的前端 */
LDeque rear = NULL;        /* 雙佇列的尾端 */
/* 抽象資料型態的操作函數宣告 */
extern int isDequeEmpty();
extern void endeque_rear(int d);
extern void endeque_front(int d);
extern int dedeque();
