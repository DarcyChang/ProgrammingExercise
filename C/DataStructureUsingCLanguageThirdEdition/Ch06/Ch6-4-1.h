/* �{���d��: Ch6-4-1.h */
#define MAXQUEUE   10  /* ��C���̤j�e�q */
int deque[MAXQUEUE];   /* ��C���}�C�ŧi */
int front = MAXQUEUE - 1;  /* ��C���e�� */
int rear = MAXQUEUE -1 ;   /* ��C������ */ 
/* ��H��ƫ��A���ާ@��ƫŧi */
extern int isDequeEmpty();
extern int isDequeFull();
extern int endeque(int d);
extern int dedeque_rear();
extern int dedeque_front();
