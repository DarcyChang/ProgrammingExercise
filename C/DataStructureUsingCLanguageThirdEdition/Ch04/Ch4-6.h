/* 程式範例: Ch4-6.h */
struct Node {               /* Node節點結構 */
   float coef;  int exp;    /* 結構變數宣告 */
   struct Node *next;       /* 指向下一個節點 */
};
typedef struct Node PNode;  /* 多項式串列節點的新型態 */
typedef PNode *PList;       /* 多項式串列的新型態 */
/* 抽象資料型態的操作函數宣告 */
extern PList createPoly(int len, float *array);
extern void printPoly(PList first);
