/* 程式範例: Ch4-3.h */
struct Node {         /* Node節點結構 */
   int data;          /* 結構變數宣告 */ 
   struct Node *next; /* 指向下一個節點 */
};
typedef struct Node LNode;   /* 串列節點的新型態 */
typedef LNode *List;         /* 串列的新型態 */
List first = NULL;           /* 串列的開頭指標 */
/* 抽象資料型態的操作函數宣告 */
extern void creatList(int len, int *array);
extern int isListEmpty();
extern void printList();
extern List searchNode(int d);
extern int deleteNode(List ptr);
extern void insertNode(List ptr, int d);
