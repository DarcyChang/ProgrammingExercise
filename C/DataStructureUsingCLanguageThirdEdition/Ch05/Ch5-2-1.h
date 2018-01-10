/* 程式範例: Ch5-2-1.h */
#define MAXSTACK 100        /* 最大的堆疊容量 */
int stack[MAXSTACK];        /* 堆疊的陣列宣告 */
int top = -1;               /* 堆疊的頂端 */
/* 抽象資料型態的操作函數宣告 */ 
extern int isStackEmpty();
extern int push(int d);
extern int pop();
