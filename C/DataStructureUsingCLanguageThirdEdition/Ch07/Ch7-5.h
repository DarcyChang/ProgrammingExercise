/* 程式範例: Ch7-5.h */
struct Node {             /* 二元樹的節點宣告 */
   int data;              /* 儲存節點資料 */ 
   struct Node *left;     /* 指向左子樹的指標 */
   struct Node *right;    /* 指向右子樹的指標 */          
};
typedef struct Node TNode;/* 二元樹節點的新型態 */
typedef TNode *BSTree;    /* 二元搜尋樹的新型態 */
BSTree head = NULL;       /* 二元搜尋樹根節點的指標 */
/* 抽象資料型態的操作函數宣告 */
extern void createBSTree(int len, int *array);
/* 二元搜尋樹的操作 */
extern void insertBSTreeNode(int d); 
extern BSTree searchBSTreeNode(int d);
extern void deleteBSTreeNode(int d);
extern int isBSTreeEmpty();
extern void printBSTree(); 
extern void inOrder(BSTree ptr, char *f); /* 三種走訪 */ 
extern void preOrder(BSTree ptr, char *f);
extern void postOrder(BSTree ptr, char *f);
