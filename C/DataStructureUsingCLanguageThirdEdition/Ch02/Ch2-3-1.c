/* �{���d��: Ch2-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {       /* �ǥ͸�� */
    int id;
    char name[20];
    int math;
    int english;
    int computer;
};
/* �D�{�� */ 
int main() {
   struct student std1;         /* �ŧi���c�ܼ� */
   struct student std2 = {2, "���p��", 45, 78, 66};
   struct student std3;
   int total;  
   std1.id = 1;                 /* ���w���c�ܼƪ��� */
   strcpy(std1.name, "���|�w");
   std1.math = 78;
   std1.english = 65;
   std1.computer = 90;
   std3 = std2;                 /* ���w�ԭz */
   /* ��ܾǥ͸�� */
   printf("�Ǹ�: %d\n", std1.id);
   printf("�m�W: %s\n", std1.name);
   total = std1.math + std1.english + std1.computer;
   printf("���Z�`��: %d\n", total);
   printf("--------------------\n"); 
   printf("�Ǹ�: %d\n", std2.id);
   printf("�m�W: %s\n", std2.name);
   total = std2.math + std2.english + std2.computer;
   printf("���Z�`��: %d\n", total);
   printf("--------------------\n"); 
   printf("�Ǹ�: %d\n", std3.id);
   printf("�m�W: %s\n", std3.name);
   total = std3.math + std3.english + std3.computer;
   printf("���Z�`��: %d\n", total);
   system("PAUSE");
   return 0; 
}
