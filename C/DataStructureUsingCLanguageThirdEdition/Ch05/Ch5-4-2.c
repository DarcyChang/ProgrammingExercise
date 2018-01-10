/* �{���d��: Ch5-4-2.c */
#include <stdio.h>
#include <stdlib.h>
int maze[7][10] = { /* �g�c�}�C,�Ʀr0�i��, 1���i�� */
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 1, 0, 1,
        1, 0, 1, 0, 1, 1, 1, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 1, 1, 1, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
/* ���g�c�����j��� */
int findPath(int x,int y) {
   if ( x == 1 && y == 1 ) {      /* �O�_�O�g�c�X�f */
      maze[x][y] = 2;             /* �O���̫ᨫ�L���� */
      return 1;
   }
   else if ( maze[x][y] == 0 ) {  /* �O���O�i�H������ */
          maze[x][y] = 2;         /* �O���v�g���L���� */
          if ( ( findPath(x - 1,y) +       /* ���W */
                 findPath(x + 1,y) +       /* ���U */
                 findPath(x,y - 1) +       /* ���� */
                 findPath(x,y + 1) ) > 0 ) /* ���k */
              return 1;
          else {
              maze[x][y] = 0;    /* �������q�����O�� */
              return 0;
          }
        }
        else return 0;
}
/* �D�{��: �ϥλ��j��Ʀb�}�C���g�c */
int main() {
   int i,j;
   findPath(5,8);                   /* �I�s���j��� */
   printf("�g�c���|��(�q�k�U���쥪�W��): \n");
   for ( i = 0; i <= 6; i++) {      /* ��ܰg�c�ϧ� */
      for ( j = 0; j <= 9; j++)
         printf("%d ", maze[i][j]); /* ��ܮy�Э� */
      printf("\n");
   }
   printf("\n�Ʀr 1: ���\n�Ʀr 2: ���L�����|\n");  
   system("PAUSE");
   return 0; 
}
