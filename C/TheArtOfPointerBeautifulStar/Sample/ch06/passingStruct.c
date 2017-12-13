/* passingStruct.c */
#include <stdio.h>
#include <conio.h>
void passOrdown(struct student *);
void output(struct student *);

struct student {
		char name[20];
		int score;
		char *passdown;
};

int main()
{
	struct student stu;
    printf("�п�J�m�W: ");
    scanf("%s", stu.name);
    printf("�п�JC�y��������: ");
    scanf("%d", &stu.score);
 
	passOrdown(&stu);
	output(&stu);
	getch();
    return 0;
}
 
void passOrdown(struct student *p)
{
    if (p->score >= 60)
		p->passdown = "PASS";
	else 
		p->passdown = "DOWN";
}

void output(struct student *q)
{
	int i;
	printf("\n\n%10s %10s %20s\n", "Name", "Score", "Pass or Down");
	for(i=1; i<=42; i++)
		printf("=");
    printf("\n");
 	printf("%10s %10d %20s\n", q->name, q->score, q->passdown); 
}

		
