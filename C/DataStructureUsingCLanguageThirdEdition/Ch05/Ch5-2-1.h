/* �{���d��: Ch5-2-1.h */
#define MAXSTACK 100        /* �̤j�����|�e�q */
int stack[MAXSTACK];        /* ���|���}�C�ŧi */
int top = -1;               /* ���|������ */
/* ��H��ƫ��A���ާ@��ƫŧi */ 
extern int isStackEmpty();
extern int push(int d);
extern int pop();
