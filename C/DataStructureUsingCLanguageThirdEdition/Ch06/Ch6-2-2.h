/* �{���d��: Ch6-2-2.h */
struct Node {              /* ��C���c���ŧi */
   int data;               /* ��� */
   struct Node *next;      /* ���c���� */
};
typedef struct Node QNode; /* ��C�`�I���s���A */
typedef QNode *LQueue;     /* ��C��C���s���A */
LQueue front = NULL;       /* ��C���e�� */
LQueue rear = NULL;        /* ��C������ */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern int isQueueEmpty();
extern void enqueue(int d);
extern int dequeue();
