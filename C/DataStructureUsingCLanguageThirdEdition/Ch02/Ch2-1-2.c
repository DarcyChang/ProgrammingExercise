/* �{���d��: Ch2-1-2.c */
#include <stdio.h>
#include <stdlib.h>
/* �D�{�� */
int main() {
   /* �ǥͦ��Z�}�C */
   int scores[10] = {76,85,90,67,59,79,82,95,91,65};
   int num;          /* �Ǹ� */
   int grade;        /* ���Z */
   int i, choice;    /* �ﶵ */
   int doit = 1;
   /* ����ާ@���D�j�� */
   while ( doit ) {
      printf("----���----\n"); 
      printf("1: �d�ߦ��Z\n");
      printf("2: �ק令�Z\n");
      printf("3: ��ܦ��Z\n");
      printf("4: ���}�@�~\n");
      printf("�п�J�ﶵ( 1 �� 4 ). ==> ");
      scanf("%d", &choice); 
      if (choice < 3 ) {
         printf("�п�J�ǥ;Ǹ�( 0 �� 9). ==> ");
         scanf("%d", &num);  /* Ū�J�Ǹ� */
      }
      switch( choice ) {
         case 1:  /* �d�ߦ��Z */
            grade = scores[num];    /* ���o���Z */
            printf("�ǥͦ��Z: %d\n", grade);
            break;
         case 2:  /* �ק令�Z */
            grade = scores[num];
            printf("��Ӿǥͦ��Z: %d\n", grade);
            printf("��J�s���Z. ==> ");/* Ū���s���Z */
            scanf("%d", &grade);
            scores[num] = grade;    /* ��s���Z */
            break;
         case 3:  /* ��ܦ��Z */
            printf("�ǥͦ��Z: \n");
            for ( i = 0; i < 10; i++ )
               printf("%d:%d ", i, scores[i]);
            printf("\n");
            break;
         case 4:  /* �����@�~ */
            doit = 0;
            break;
      }
   }   
   system("PAUSE");
   return 0; 
}
