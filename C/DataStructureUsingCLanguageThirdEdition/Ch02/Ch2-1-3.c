/* �{���d��: Ch2-1-3.c */
#include <stdio.h>
#include <stdlib.h>
/* �D�{�� */
int main() {
   /* �ǥͥ\�Ҫ�, �ϥνҵ{�N�X */
   int courses[6][5]={0, 2, 0, 2, 0,
                      1, 4, 1, 4, 1,
                      5, 0, 5, 0, 5,
                      0, 0, 0, 0, 0,
                      3, 0, 3, 0, 3,
                      0, 0, 0, 0, 0 };
   int week_no;    /* �P���X */
   int num;        /* �ĴX�`�� */
   int code;       /* �ҵ{�N�X */
   printf("�п�J�P��(1 �� 5). ==> ");
   scanf("%d", &week_no);   /* Ū���P���X */
   printf("�п�J�ĴX�`��(1 �� 6). ==> ");
   scanf("%d", &num);       /* Ū���ĴX�`�� */
   /* ���o�ҵ{�N�X */
   code = courses[num-1][week_no-1];
   printf("�ҵ{�N�X: %d\n", code); 
   /* ��ܽҵ{�W�� */
   switch ( code ) {
      case 0: printf("�S�ҡI\n");
              break;
      case 1: printf("�p�������\n");
              break;
      case 2: printf("�����ƾ�\n");
              break;
      case 3: printf("��Ƶ��c\n");
              break;
      case 4: printf("��Ʈw�z��\n");
              break;
      case 5: printf("�W�����\n");
              break;
   }
   system("PAUSE");
   return 0; 
}
