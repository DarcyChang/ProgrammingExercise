/* �{���d��: Ch6-3.h */
#define MAXQUEUE   4         /* ��C���̤j�e�q */
int queue[MAXQUEUE];         /* ��C���}�C�ŧi */
int front = MAXQUEUE - 1;    /* ��C���e�� */
int rear = MAXQUEUE - 1;     /* ��C������ */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern int isQueueEmpty();
extern int isQueueFull();
extern int enqueue(int d);
extern int dequeue();
