/* 程式範例: Ch10-5-3.h */
#define MAX_LEN      10         /* 最大陣列尺寸 */
struct Node {                   /* 節點結構宣告 */
   int data;                    /* 鍵值 */
   struct Node *next;           /* 指下一個節點的指標 */
};
typedef struct Node *Table;     /* 雜湊表的節點新型態 */
struct Node hashTable[MAX_LEN]; /* 雜湊表的結構陣列 */
/* 抽象資料型態的操作函數宣告 */
extern void createHashTable(int len, int *array);
extern void printHashTable();
extern int chainHashSearch(int key);
extern int hashFunc(int key);
