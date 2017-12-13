/* doublyListRandom.c */
/* 雙向鍵結串列的加入與刪除: 以分數的高低加以排序 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void init_f(void);     /* 初始化串列，建立一空節點為HEAD */
void insert_f(void);   /* 插入函數 */
void delete_f(void);   /* 刪除函數 */
void display_f(void);  /* 輸出函數 */
void modify_f(void);   /* 修改函數 */
 
struct student {
	char name[20];         /* 姓名 */
	int score;             /* 分數 */
	struct student *llink;  /* 節點左鏈結 */
	struct student *rlink;  /* 節點右鏈結 */
};

struct student *ptr, *head, *tail, *current_n, *prev;

int main()
{
	char option1;

	init_f();
	while(1){
		printf("\n ****************\n");
		printf("     1.insert\n");
		printf("     2.delete\n");
		printf("     3.display\n");
		printf("     4.modify\n");
		printf("     5.quit\n");
		printf(" *******************\n");
		printf("  Enter your choice (1-5): ");
		option1 = getche();
		switch(option1){
			case '1':
				insert_f();
				break;
			case '2':
				delete_f();
				break;
			case '3':
				display_f();
				break;
			case '4':
				modify_f();
				break;
			case '5':
 				printf("\n");
				return 0;
		}
	}
}

void init_f(void)  /* 設一HEAD，將左右鏈結皆指向本身 */
{
	ptr = (struct student *) malloc(sizeof(struct student));
	strcpy(ptr->name, "0");
	ptr->llink = ptr;
	ptr->rlink = ptr;
	head = ptr;
	tail = ptr;
}

/* 依分數的高低加入 */
void insert_f(void)
{
	char s_temp[4];

	ptr = (struct student *) malloc(sizeof(struct student));
	printf("\n Student name : ");
	gets(ptr->name);
	printf(" Student score: ");
	gets(s_temp);
	ptr->score = atoi(s_temp);
 
	prev = head;
	current_n = head->rlink;
	while((current_n != head) && (current_n->score >= ptr->score)) {
		prev = current_n;
		current_n = current_n->rlink;
	}
	ptr->rlink = current_n;
	ptr->llink = prev;
	prev->rlink = ptr;
	current_n->llink = ptr;
}

void delete_f(void)
{
	char del_name[20], ans;
	int count = 0;

	if(head->rlink == head) 
		printf("\n No student record\n");
	else {
		printf("\n Delete student name: ");
		gets(del_name);
		prev = head;
		current_n = head->rlink;
		while ((current_n != head) && (strcmp(current_n->name , del_name)!=0)) {
			prev = current_n;
			current_n = current_n->rlink;
		}
		if (current_n != head) {
           /* 確認是否要刪除 */       
           printf(" Are you sure? ");
           ans=getche();
           if (ans == 'Y' || ans == 'y') {
		  	  prev->rlink = current_n->rlink;
			  current_n->rlink->llink = prev;
			  free(current_n);
			  printf("\n Student %s has been deleted\n",del_name);
		   }
         } 
         else
		      printf("\n Student %s not found\n",del_name);
	}
}

void modify_f(void)
{
	int count = 0;
	char n_temp[20], s_temp[4];

	if(head->rlink == head) 
		printf("\n No student recond\n"); /* 無資料顯示錯誤 */
	else {
		printf("\n Modify student name: ");
		gets(n_temp);
		current_n=head->rlink;
		while ((current_n != head) && (strcmp(current_n->name , n_temp)!=0)){
			prev = current_n;
			current_n = current_n->rlink;
		}
		if (current_n != head)  {
			printf("\n **************************\n");
			printf("  Student name : %s\n",current_n->name);
			printf("  Student score: %d\n",current_n->score);
			printf(" **************************\n");
			printf(" Please enter new score: ");
			gets(s_temp);
			current_n->score = atoi(s_temp);
			printf("\n %s student record(s) modified\n", n_temp);
		}
		else     // 找不到資料則顯示錯誤
			printf("\n Student %s not found\n",n_temp);
	}
}

void display_f(void)
{
	int count = 0;

	if(head->rlink == head) 
		printf("\n No student record\n");
	else {
		printf("\n\n  NAME      SCORE\n");
		printf(" --------------------\n");
		current_n = head->rlink;
		while(current_n != head) {
			printf("  %-10s %3d\n", current_n->name, current_n->score);
			count++;
			current_n = current_n->rlink;
			if(count % 20 == 0) getch(); /* 每次印出20筆資料 */
		}
		printf(" ---------------------\n");
		printf(" Total %d record(s) found\n", count);
	}
}
 
