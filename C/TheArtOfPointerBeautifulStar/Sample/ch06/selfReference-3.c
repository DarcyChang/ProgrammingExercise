/* selfReference-3.c */
#include <stdio.h>
#include <stdlib.h>

int main()
{
      struct student {
          char *name;
          int score;
          struct student *next;
      };
      struct student st[]= {	{"John", 90, st+1}, 
                        {"Mary", 85, st+2},
					{"Peter", 92, st} };
      struct student *ptr=st;
      printf("st[0].name = %s\n", st[0].name);
      printf("(*st).name = %s\n", (*st).name);
      printf("ptr->name = %s\n", ptr->name);
      printf("st[1].next->name = %s\n", st[1].next->name);	
      printf("st[1].next->score = %d\n", st[1].next->score);
      printf("++(ptr->name) = %s\n", ++(ptr->name));
      printf("++ptr->name = %s\n", ++ptr->name);
      printf("ptr->next->name = %s\n", ptr->next->name);
      printf("ptr->next->score = %d\n", ptr->next->score);
      system("PAUSE");
      return 0;
}
