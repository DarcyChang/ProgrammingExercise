/* �{���d��: Ch4-6.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch4-6.h"
#include "createPoly.c"
/* �D�{�� */
int main() {
   PList a = NULL;    /* �h������C1���}�Y���� */
   PList b = NULL;    /* �h������C2���}�Y���� */
   /* �إߦh��������һݪ��}�C */
   float list1[6] = { 4, 0, 3, 0, 7, 0 };
   float list2[6] = { 9, 7, 1, 0, 5, 6 };
   a = createPoly(6, list1);  /* �إߦh������C1 */
   b = createPoly(6, list2);  /* �إߦh������C2 */
   printPoly(a);     /* ��ܦh����1 */
   printPoly(b);     /* ��ܦh����2 */
   system("PAUSE");
   return 0; 
}
