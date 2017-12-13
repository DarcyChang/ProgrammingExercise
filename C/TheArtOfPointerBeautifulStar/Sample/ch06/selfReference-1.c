/* selfReference-1.c */
#include <stdio.h>
#include <conio.h>

int main()
{
     struct node {
        char *name;
        int score;
        struct node *next;
     };
     struct node *p, *q;
     p = (struct node *) malloc(sizeof(struct node));
     p->name = "Mary";
     p->score = 80;
     p->next = NULL;
     q = (struct node *) malloc(sizeof(struct node));
     q->name = "John";
     q->score = 90;
     q->next = p;
     printf("%s %d\n", q->name, q->score);
     printf("%s %d\n", q->next->name, q->next->score);
     getch();
     return 0;
}

