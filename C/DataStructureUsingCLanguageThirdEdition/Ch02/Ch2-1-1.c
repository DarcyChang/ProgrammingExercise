/* �{���d��: Ch2-1-1.c */ 
#include <stdio.h>
#include <stdlib.h>
/* �D�{�� */
int main() {
   int sum = 0;  /* �`�� */
   /* �إ߾�ư}�C */
   int scores[5] = {56, 89, 75, 66, 98};
   printf("���int�O����j�p: %d\n", sizeof(int));
   printf("scores[0]����}: %p\n", &scores[0]);
   printf("scores[1]����}: %p\n", &scores[1]);
   printf("scores[2]����}: %p\n", &scores[2]);
   printf("scores[3]����}: %p\n", &scores[3]);
   printf("scores[4]����}: %p\n", &scores[4]); 
   /* �p���`�� */
   sum = scores[0] + scores[1] + \
         scores[2] + scores[3] + \
         scores[4];
   printf("���Z�`��: %d\n", sum);   
   system("PAUSE");
   return 0; 
}
