/* advancedStruct-1.c  */
#include <stdio.h>
#include <stdlib.h>

int main()
{
      struct student {
         char *name;
         int score;
      };
 
      struct student st= {"Brian", 97};
      struct student *ptr=&st;
 
      printf("ptr->name = %s\n", ptr->name);
      printf("*ptr->name = %c\n", *ptr->name);
      printf("*ptr->name++ = %c\n", *ptr->name++);
      printf("*ptr->name = %c\n", *ptr->name);
      printf("*ptr->score = %d\n", ptr->score);
      printf("*ptr->score++ = %d\n", (ptr->score)++);	
      printf("*ptr->score = %d\n", ptr->score);
      system("PAUSE");
      return 0;
}
