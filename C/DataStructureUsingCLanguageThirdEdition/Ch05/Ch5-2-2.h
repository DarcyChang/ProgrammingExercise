/* �{���d��: Ch5-2-2.h */
struct Node {                  /* ���|�`�I���ŧi */
   int data;                   /* �x�s���|��� */
   struct Node *next;          /* ���V�U�@�`�I */
};
typedef struct Node SNode;     /* ���|�`�I���s���A */ 
typedef SNode *LStack;         /* ��C���|���s���A */
LStack top = NULL;             /* ���|���ݪ����� */
/* ��H��ƫ��A���ާ@��ƫŧi */ 
extern int isStackEmpty();
extern void push(int d);
extern int pop();
