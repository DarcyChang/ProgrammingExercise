/* 程式範例: Ch6-2-1.h */
#define MAXQUEUE 10          /* 佇列的最大容量 */
int queue[MAXQUEUE];         /* 佇列的陣列宣告 */
int front = -1;              /* 佇列的前端 */
int rear = -1;               /* 佇列的尾端 */
/* 抽象資料型態的操作函數宣告 */
extern int isQueueEmpty(); 
extern int enqueue(int d);
extern int dequeue();
