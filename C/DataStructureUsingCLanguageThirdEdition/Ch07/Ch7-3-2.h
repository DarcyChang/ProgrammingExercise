/* �{���d��: Ch7-3-2.h */
#define MAX_LENGTH   16     /* �̤j�}�C�ؤo */
struct Node {               /* �G���𪺵��c�ŧi */
   int data;                /* �`�I��� */
   int left;                /* ���V���l�𪺦�m */
   int right;               /* ���V�k�l�𪺦�m */
};
typedef struct Node TreeNode;  /* �𪺸`�I�s���A */
TreeNode btree[MAX_LENGTH];    /* �G���𵲺c�}�C�ŧi */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void createBTree(int len, int *array);
extern void printBTree();
