/* �{���d��: Ch10-5-3.h */
#define MAX_LEN      10         /* �̤j�}�C�ؤo */
struct Node {                   /* �`�I���c�ŧi */
   int data;                    /* ��� */
   struct Node *next;           /* ���U�@�Ӹ`�I������ */
};
typedef struct Node *Table;     /* ������`�I�s���A */
struct Node hashTable[MAX_LEN]; /* ��������c�}�C */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void createHashTable(int len, int *array);
extern void printHashTable();
extern int chainHashSearch(int key);
extern int hashFunc(int key);
