/* 程式範例: Ch10-5-1.h */
#define MAX_LEN      10     /* 最大陣列尺寸 */
int hashTable[MAX_LEN];     /* 雜湊表宣告 */
/* 抽象資料型態的操作函數宣告 */
extern void createHashTable(int len, int *array);
extern void printHashTable();
extern int lineHashSearch(int key);
extern int hashFunc(int key);
