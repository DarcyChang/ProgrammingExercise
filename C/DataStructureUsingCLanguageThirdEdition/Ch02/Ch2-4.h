/* �{���d��: Ch2-4.h */
#define MAX_TERMS    10  /* �}���x�}���̤j������ */
struct Term {            /* �}���x�}���������c */ 
   int row;              /* �������C�� */ 
   int col;              /* ��������� */ 
   int value;            /* �������� */ 
};
struct sMatrix {         /* �}���x�}�����c */
   int rows;             /* �x�}���C�� */ 
   int cols;             /* �x�}����� */ 
   int numOfTerms;       /* �x�}�������� */ 
   struct Term smArr[MAX_TERMS];  /* ���Y�}�C���ŧi */
};
typedef struct sMatrix Matrix; /* �إߵ}���x�}���s���A */ 
Matrix m;                      /* �إߵ}���x�} */ 
/* ��H��ƫ��A���ާ@��ƫŧi */
extern void createMatrix(int r,int c,int *arr);
extern void printMatrix();
