/* �{���d��: Ch4-5.h */
struct Node {             /* Node�`�I���c */
   int data;              /* ���c�ܼƫŧi */ 
   struct Node *next;     /* ���V�U�@�Ӹ`�I */
   struct Node *previous; /* ���V�e�@�Ӹ`�I */ 
};
typedef struct Node DNode;   /* ���V��C�`�I���s���A */
typedef DNode *DList;        /* ���V��C���s���A */
DList first = NULL;          /* ���V��C���}�Y���� */
DList now = NULL;            /* ���V��C�ثe�`�I���� */ 
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void creatDList(int len, int *array);
extern void printDList();
extern void nextNode();
extern void previousNode();
extern void resetNode();
extern DList readNode();
extern void insertDNode(DList ptr, int d);
extern void deleteDNode(DList ptr);
