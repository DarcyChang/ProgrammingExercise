/* �{���d��: Ch4-1.c */
#include <stdio.h>
#include <stdlib.h>
/* �D�{�� */
int main() {  
   struct test { /* �ŧi���c */
      int math;
   }; /* ���c�}�C�����ܼƫŧi */
   struct test *score, *ptr;
   float *ave;
   int i, num, sum, temp;
   printf("�п�J�ǥͤH�� ==> "); /* Ū���ǥͤH�� */
   scanf("%d", &num);
   /* �t�m���Z�}�C���O���� */
   score=(struct test *)malloc(num*sizeof(struct test));
   if ( score != NULL ) { /* �ˬd���� */
      sum = 0;   /* Ū�����Z */
      for ( i = 0; i < num; i++ ) {
         ptr = &score[i];  /* ���V���c������ */ 
         printf("�п�J��%d�쪺���Z. ==> ", i+1);
         scanf("%d", &temp);
         ptr->math = temp; /* ���w�ƾǦ��Z */ 
         sum += temp;
      } /* �t�m�B�I�ƪ��O���� */
      ave = (float *) malloc(sizeof(float));
      *ave = (float) sum / (float) num;  /* �p�⥭�� */
      printf("���Z�`��: %6d\n", sum);
      printf("�������Z: %6.2f\n", *ave);
      free(ave);  /* ���^�O����Ŷ� */
      free(score);
   } else printf("���Z���c�}�C���O����t�m����!\n");
   system("PAUSE");
   return 0; 
}
