/* �{���d��: Ch4-3.h */
struct Node {         /* Node�`�I���c */
   int data;          /* ���c�ܼƫŧi */ 
   struct Node *next; /* ���V�U�@�Ӹ`�I */
};
typedef struct Node LNode;   /* ��C�`�I���s���A */
typedef LNode *List;         /* ��C���s���A */
List first = NULL;           /* ��C���}�Y���� */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void creatList(int len, int *array);
extern int isListEmpty();
extern void printList();
extern List searchNode(int d);
extern int deleteNode(List ptr);
extern void insertNode(List ptr, int d);
