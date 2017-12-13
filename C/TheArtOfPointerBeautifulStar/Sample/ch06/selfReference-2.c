/* selfReference-2.c */
#include <stdio.h>
#include <conio.h>

int main()
{
    struct student {
		char *name;
		int score;
		struct student *next;
	};

	struct student *p, *q, *r, *current;
    p=(struct student *) malloc(sizeof (struct student));
	p->name = "Bright";
	p->score = 98;

    q=(struct student *) malloc(sizeof (struct student));
	q->name = "Linda";
	q->score = 95;

    r=(struct student *) malloc(sizeof (struct student));
	r->name = "Jennifer";
	r->score = 95;

	p->next = q;
	q->next = r;
	
	r->next=NULL;
     
	printf("There are three students in my class\n");
    current = p;
	while(current != NULL) {
		printf("%10s %10d\n", current->name, current->score);
		current = current->next;
	}
    getch();
    return 0;
}
 
		
