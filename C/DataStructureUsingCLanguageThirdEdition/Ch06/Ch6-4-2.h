/* �{���d��: Ch6-4-2.h */
struct Node {              /* ��C���c���ŧi */
   int data;               /* ��� */
   struct Node *next;      /* ���c���� */
};
typedef struct Node QNode; /* ����C�`�I���s���A */
typedef QNode *LDeque;     /* ��C����C���s���A */
LDeque front = NULL;       /* ����C���e�� */
LDeque rear = NULL;        /* ����C������ */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern int isDequeEmpty();
extern void endeque_rear(int d);
extern void endeque_front(int d);
extern int dedeque();
