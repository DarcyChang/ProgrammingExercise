/* �{���d��: Ch7-5.h */
struct Node {             /* �G���𪺸`�I�ŧi */
   int data;              /* �x�s�`�I��� */ 
   struct Node *left;     /* ���V���l�𪺫��� */
   struct Node *right;    /* ���V�k�l�𪺫��� */          
};
typedef struct Node TNode;/* �G����`�I���s���A */
typedef TNode *BSTree;    /* �G���j�M�𪺷s���A */
BSTree head = NULL;       /* �G���j�M��ڸ`�I������ */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void createBSTree(int len, int *array);
/* �G���j�M�𪺾ާ@ */
extern void insertBSTreeNode(int d); 
extern BSTree searchBSTreeNode(int d);
extern void deleteBSTreeNode(int d);
extern int isBSTreeEmpty();
extern void printBSTree(); 
extern void inOrder(BSTree ptr, char *f); /* �T�ب��X */ 
extern void preOrder(BSTree ptr, char *f);
extern void postOrder(BSTree ptr, char *f);
