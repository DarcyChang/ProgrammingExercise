/* 程式範例: Ch12-2.h */
struct Node {             /* AVL樹的節點宣告 */
   int data;              /* 儲存節點資料 */ 
   struct Node *left;     /* 指向左子樹的指標 */
   struct Node *right;    /* 指向右子樹的指標 */ 
   int height;            /* 子樹的最大樹高值 */
};
typedef struct Node AvlNode; /* AVL樹節點的新型態 */
typedef AvlNode *AvlTree;    /* AVL樹鏈結的新型態 */
AvlTree head = NULL;         /* AVL樹根節點的指標 */
/* 抽象資料型態的操作函數宣告 */
extern void createAvlTree(int len, int *array);
extern AvlTree insertAvlNode(int data, AvlTree ptr);
extern int deleteAvlNode(int data);
extern void printAvlTree();
