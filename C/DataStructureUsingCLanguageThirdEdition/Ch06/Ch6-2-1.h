/* �{���d��: Ch6-2-1.h */
#define MAXQUEUE 10          /* ��C���̤j�e�q */
int queue[MAXQUEUE];         /* ��C���}�C�ŧi */
int front = -1;              /* ��C���e�� */
int rear = -1;               /* ��C������ */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern int isQueueEmpty(); 
extern int enqueue(int d);
extern int dequeue();
