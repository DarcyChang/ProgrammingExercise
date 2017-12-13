/* selfReference-4.c */
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
    struct student *ptr[]={st, st+1, st+2};
    printf("(*ptr)->name = %s\n", (*ptr)->name);
    printf("(**ptr).name = %s\n", (**ptr).name);
    printf("(*ptr)->score = %d\n", (*ptr)->score);
    printf("ptr[0]->score = %d\n", ptr[0]->score);
    printf("(*ptr)->next->name = %s\n", (*ptr)->next->name);	
    printf("(*ptr)->next->name = %s\n", (*ptr)->next->next->name);
    printf("(++(*ptr)->next)->name = %s\n", (++(*ptr)->next)->name);
    printf("(*ptr)->next->score = %d\n", (*ptr)->next->score);
    system("PAUSE");
    return 0;
}
