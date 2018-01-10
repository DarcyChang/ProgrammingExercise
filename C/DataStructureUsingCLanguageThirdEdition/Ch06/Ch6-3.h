/* 程式範例: Ch6-3.h */
#define MAXQUEUE   4         /* 佇列的最大容量 */
int queue[MAXQUEUE];         /* 佇列的陣列宣告 */
int front = MAXQUEUE - 1;    /* 佇列的前端 */
int rear = MAXQUEUE - 1;     /* 佇列的尾端 */
/* 抽象資料型態的操作函數宣告 */
extern int isQueueEmpty();
extern int isQueueFull();
extern int enqueue(int d);
extern int dequeue();
