/* �{���d��: Ch2-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#define NUM_STUDENTS       3    /* �ǥͤH�� */ 
/* �D�{�� */ 
int main() {
   struct test {                /* �ŧi���c */
      int math;
      int english;
      int computer;
   };
   /* ���c�}�C�ܼƫŧi */
   struct test students[NUM_STUDENTS];
   int i, c;
   /* �U�즨�Z�`���ܼ� */
   int m_sum = 0, e_sum = 0, c_sum = 0;
   /* �U�쥭�����Z�ܼ� */   
   float m_ave, e_ave, c_ave;
   /* �ϥΰj��Ū���ǥͦ��Z */
   for ( i = 0; i < NUM_STUDENTS; i++ ) {
      printf("�ǥͽs��: %d\n",i + 1);
      printf("�п�J�ƾǦ��Z. ==> ");
      scanf("%d", &students[i].math); /* Ū���ƾǦ��Z */
      m_sum += students[i].math;      /* �p��ƾ��`�� */
      printf("�п�J�^�妨�Z. ==> ");
      scanf("%d",&students[i].english);/* Ū���^�妨�Z */
      e_sum += students[i].english;    /* �p��^���`�� */
      printf("�п�J�q�����Z. ==> ");
      scanf("%d",&students[i].computer);/* Ū���q�����Z */
      c_sum += students[i].computer;    /* �p��q���`�� */
   }
   /* �p�⥭�����Z */ 
   m_ave = (float) m_sum / (float) NUM_STUDENTS;
   e_ave = (float) e_sum / (float) NUM_STUDENTS;
   c_ave = (float) c_sum / (float) NUM_STUDENTS;
   printf("�ƾǥ������Z: %6.2f \n", m_ave);
   printf("�^�奭�����Z: %6.2f \n", e_ave);
   printf("�q���������Z: %6.2f \n", c_ave);
   system("PAUSE");
   return 0; 
}
