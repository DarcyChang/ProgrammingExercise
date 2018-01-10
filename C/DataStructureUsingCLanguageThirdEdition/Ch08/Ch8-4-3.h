/* �{���d��: Ch8-4-3.h */
#define MAX_VERTICES   6          /* �̤j���I�ƥ[�@ */
struct Edge {                     /* �ϧ���u���c�ŧi */
   int from;                      /* �}�l���I */
   int to;                        /* ���I���I */
   int weight;                    /* �v�� */
   struct Edge *next;             /* ���U�@����u */
};
typedef struct Edge *EdgeList;    /* ��u�����c�s���A */
EdgeList first = NULL;            /* ��u��C�}�l���� */
int vertex[MAX_VERTICES];         /* �ˬd�j�骺���I�}�C */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void createEdge(int len, int *edge);
extern void minSpanTree();
extern void addSet(int from, int to);
extern int isSameSet(int from, int to);
