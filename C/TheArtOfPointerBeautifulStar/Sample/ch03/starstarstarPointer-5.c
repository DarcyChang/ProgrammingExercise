/* starstarstarPointer-5.c */
#include <stdio.h>
#include <stdlib.h>

int main()
{
   char *s[] = {"Stanford", "University", "California", "America"};
   char **sa[] = {s, s+1, s+2, s+3};
   char ***p3 = sa;
   printf("**p3++ = %s\n", **p3++);
   printf("**++p3 = %s\n", **++p3);
   printf("**++*p3 = %c\n", **++*p3);
   printf("*(*--*++p3+3) = %c\n", *(*--*++p3+3));
   system("PAUSE");
   return 0;
}
