/* �{���d��: ChA-1.c */
#include <stdio.h>
#include <stdlib.h>
int total;                    /* �����ܼƪ��ŧi */ 
/* ���: �Ǧ^1�[��n */
int one2N(int n) {
   int i, total = 0;          /* �ϰ��ܼƪ��ŧi */
   for ( i = 1; i <= n; i++ ) total+=i; /* �j��ԭz */
   return total;
}
/* �D�{�� */
int main() {
   total = one2N(10);         /* �I�s��ƭp��1�[��10 */
   printf("�q1��10���`�M: %d\n", total);
   system("PAUSE");
   return 0; 
}
