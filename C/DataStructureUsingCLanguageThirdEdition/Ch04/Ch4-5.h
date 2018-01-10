/* 程式範例: Ch4-5.h */
struct Node {             /* Node節點結構 */
   int data;              /* 結構變數宣告 */ 
   struct Node *next;     /* 指向下一個節點 */
   struct Node *previous; /* 指向前一個節點 */ 
};
typedef struct Node DNode;   /* 雙向串列節點的新型態 */
typedef DNode *DList;        /* 雙向串列的新型態 */
DList first = NULL;          /* 雙向串列的開頭指標 */
DList now = NULL;            /* 雙向串列目前節點指標 */ 
/* 抽象資料型態的操作函數宣告 */
extern void creatDList(int len, int *array);
extern void printDList();
extern void nextNode();
extern void previousNode();
extern void resetNode();
extern DList readNode();
extern void insertDNode(DList ptr, int d);
extern void deleteDNode(DList ptr);
