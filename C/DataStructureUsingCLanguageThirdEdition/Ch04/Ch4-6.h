/* �{���d��: Ch4-6.h */
struct Node {               /* Node�`�I���c */
   float coef;  int exp;    /* ���c�ܼƫŧi */
   struct Node *next;       /* ���V�U�@�Ӹ`�I */
};
typedef struct Node PNode;  /* �h������C�`�I���s���A */
typedef PNode *PList;       /* �h������C���s���A */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern PList createPoly(int len, float *array);
extern void printPoly(PList first);
