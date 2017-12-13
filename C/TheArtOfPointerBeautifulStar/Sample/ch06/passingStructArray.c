/* passingStructArray.c */
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
	struct student stu[3];
 	int i;
	for(i=0; i<3; i++) {
 	  printf("請輸入第 #%d 位同學的姓名: ", i+1);
	  scanf("%s", stu[i].name);

	  printf("請輸入第 #%d 位同學C語言的分數: ", i+1);
	  scanf("%d", &stu[i].score);
	  printf("\n");
	}
	passOrdown(stu);
	output(stu);
	getch();
    return 0;
}
 
void passOrdown(struct student *p)
{
	int i;
	for(i=0; i<3; i++) {
		if (p->score >= 60)
			p->passdown = "PASS";
		else 
			p->passdown = "DOWN";
		p++;
	}
}

void output(struct student *q)
{
	int i;
	printf("\n\n%10s %10s %20s\n", "Name", "Score", "Pass or Down");
	for(i=1; i<=42; i++)
		printf("=");
    printf("\n");
	for(i=0; i<3; i++) {
		printf("%10s %10d %20s\n", q->name, q->score, q->passdown);
		q++;
	}
}

		
