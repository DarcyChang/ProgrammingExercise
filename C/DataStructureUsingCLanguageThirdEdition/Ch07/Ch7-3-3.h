/* �{���d��: Ch7-3-3.h */
struct Node {             /* �G���𪺸`�I�ŧi */
   int data;              /* �x�s�`�I��� */ 
   struct Node *left;     /* ���V���l�𪺫��� */
   struct Node *right;    /* ���V�k�l�𪺫��� */          
};
typedef struct Node TNode;  /* �G����`�I���s���A */
typedef TNode *BTree;       /* �G�����쵲���s���A */
BTree head = NULL;          /* �G����ڸ`�I������ */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void createBTree(int len, int *array);
extern void insertBTreeNode(int d);
extern int isBTreeEmpty();
extern void printBTree(); 
extern void inOrder(BTree ptr);
extern void printInOrder();
extern void preOrder(BTree ptr);
extern void printPreOrder();
extern void postOrder(BTree ptr);
extern void printPostOrder();
