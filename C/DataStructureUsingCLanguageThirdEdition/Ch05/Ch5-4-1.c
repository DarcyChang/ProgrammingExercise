/* �{���d��: Ch5-4-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
/* �D�{��: �ϥΦ^����k�b�}�C���g�c */
int main() {
   int maze[7][10] = { /* �g�c�}�C,�Ʀr0�i��, 1���i�� */
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 1, 0, 1,
            1, 0, 1, 0, 1, 1, 1, 0, 0, 1,
            1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
            1, 0, 0, 0, 1, 1, 1, 0, 0, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
   int i,j;
   int x = 5;                     /* �g�c�J�f�y�� */
   int y = 8;
   while ( x != 1 || y != 1 ) {   /* �D�j�� */
      maze[x][y] = 2;             /* �Хܬ��w���L���� */
      if ( maze[x-1][y] <= 0 ) {  /* ���W�訫 */
         x = x - 1;               /* �y��x��1 */
         push(x);                 /* �s�J���| */
         push(y);
      }
      else if ( maze[x+1][y] <= 0 ) { /* ���U�訫 */
           x = x + 1;            /* �y��x�[1 */
           push(x);              /* �s�J���| */
           push(y);
         }
         else if ( maze[x][y-1] <= 0 ) { /* �����訫 */
              y = y - 1;            /* �y��y��1 */
              push(x);              /* �s�J���| */
              push(y);
           }
           else if ( maze[x][y+1] <= 0 ) {/* ���k�訫 */
                y = y + 1;             /* �y��y�[1 */
                push(x);               /* �s�J���| */
                push(y);
             }
             else {  /* �S�����i��:�j�� */
                  maze[x][y] = 3;   /* ��ܬO�j������ */
                  y = pop();        /* �h�^�@�B */
                  x = pop();
               }
   }
   maze[x][y] = 2;                /* �Х̫ܳ��m */
   printf("�g�c���|��(�q�k�U���쥪�W��): \n");
   for ( i = 0; i <= 6; i++) {    /* ��ܰg�c�ϧ� */
      for ( j = 0; j <= 9; j++)
         printf("%d ", maze[i][j]); /* ��ܮy�Э� */
      printf("\n");
   }
   printf("\n�Ʀr 1: ���\n�Ʀr 2: ���L�����|\n");
   printf("�Ʀr 3: �^�����|\n");
   system("PAUSE");
   return 0; 
}
