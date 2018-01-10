/* �{���d��: Ch8-2-2.h */
#define MAX_VERTICES   10       /* �ϧΪ��̤j���I�� */
struct Vertex {                 /* �ϧγ��I���c�ŧi */
   int data;                    /* ���I��� */
   struct Vertex *next;         /* ���U�@�ӳ��I������ */
};
typedef struct Vertex *Graph;   /* �ϧΪ��s���A */
struct Vertex head[MAX_VERTICES];/* �ϧγ��I���c�}�C */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void createGraph(int len, int *edge);
extern void printGraph();
extern void dfs(int vertex);
extern void bfs(int vertex);
