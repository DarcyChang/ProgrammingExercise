/* strings.c -- string formatting */
#include <stdio.h>
#define BLURB "Authentic imitation!"
int main(void)
{

    printf("/%21s/\n", BLURB); // Authentic imitation! ¦³20­Ó¦r¤¸
   printf("/%2s/\n", BLURB);
   printf("/%24s/\n", BLURB);
   printf("/%24.5s/\n", BLURB);
   printf("/%-24.5s/\n", BLURB);

   return 0;
}
