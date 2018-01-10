/* �{���d��: Ch12-2.h */
struct Node {             /* AVL�𪺸`�I�ŧi */
   int data;              /* �x�s�`�I��� */ 
   struct Node *left;     /* ���V���l�𪺫��� */
   struct Node *right;    /* ���V�k�l�𪺫��� */ 
   int height;            /* �l�𪺳̤j�𰪭� */
};
typedef struct Node AvlNode; /* AVL��`�I���s���A */
typedef AvlNode *AvlTree;    /* AVL���쵲���s���A */
AvlTree head = NULL;         /* AVL��ڸ`�I������ */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void createAvlTree(int len, int *array);
extern AvlTree insertAvlNode(int data, AvlTree ptr);
extern int deleteAvlNode(int data);
extern void printAvlTree();
