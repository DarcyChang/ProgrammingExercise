/* �{���d��: Ch10-5-1.h */
#define MAX_LEN      10     /* �̤j�}�C�ؤo */
int hashTable[MAX_LEN];     /* �����ŧi */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void createHashTable(int len, int *array);
extern void printHashTable();
extern int lineHashSearch(int key);
extern int hashFunc(int key);
