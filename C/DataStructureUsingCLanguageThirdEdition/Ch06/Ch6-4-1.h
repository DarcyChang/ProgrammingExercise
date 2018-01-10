/* 程式範例: Ch6-4-1.h */
#define MAXQUEUE   10  /* 佇列的最大容量 */
int deque[MAXQUEUE];   /* 佇列的陣列宣告 */
int front = MAXQUEUE - 1;  /* 佇列的前端 */
int rear = MAXQUEUE -1 ;   /* 佇列的尾端 */ 
/* 抽象資料型態的操作函數宣告 */
extern int isDequeEmpty();
extern int isDequeFull();
extern int endeque(int d);
extern int dedeque_rear();
extern int dedeque_front();
