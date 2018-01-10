/* file name: poly_add_list.c */
/* 多項式相加--使用降冪排列輸入兩個格式為ax^b的多項式相加 */
#include <stdio.h>
#include <stdlib.h>
void input(struct poly **);  /* 輸入函數 */
void poly_add(void);         /* 多項式相加函數 */
void show_ans(void);         /* 顯示多項式相加結果函數 */

struct poly {
	int coef;   /* 多項式係數 */
	int exp;    /* 多項式指數 */
	struct poly *next;
};

struct poly *ptr, *eq_h1, *eq_h2, *ans_h;
void main(void)
{
	printf("****************************************\n");
	printf(" -- Polynomial add using format ax^b --\n");
	printf("****************************************\n");
	printf("Please enter the first equation: ");
	input(&eq_h1);
	printf("Please enter the second equation: ");
	input(&eq_h2);
	poly_add();
	show_ans();
}

void input(struct poly **eq_h)
{
	struct poly *prev = NULL;
	char symbol = '+';
	do
	{
		ptr = (struct poly *) malloc(sizeof(struct poly));
		ptr->next = NULL;
		scanf("%dx^%d", &ptr->coef, &ptr->exp);
		if(*eq_h == NULL)
			*eq_h = ptr;
		else
		{
			if(symbol == '-') ptr->coef = -(ptr->coef);
			prev->next = ptr;
		}
		prev = ptr;
		scanf("%c", &symbol);
	}  while(symbol != '\n');
}

void poly_add(void)
{
	struct poly *this_n1, *this_n2, *prev;
	this_n1 = eq_h1;
	this_n2 = eq_h2;
	prev = NULL;
	while(this_n1 != NULL || this_n2 != NULL) /* 當兩個多項式皆相加完畢則結束 */
	{
		ptr = (struct poly *) malloc(sizeof(struct poly));
		ptr->next = NULL;
		/* 第一個多項式指數大於第二個多項式 */
		if(this_n1 != NULL && (this_n2 == NULL || this_n1->exp > this_n2->exp))
		{
			ptr->coef = this_n1->coef;
			ptr->exp = this_n1->exp;
			this_n1 = this_n1->next;
		}
		else
			/* 第一個多項式指數小於第二個多項式 */
			if(this_n1 == NULL || this_n1->exp < this_n2->exp)
			{
				ptr->coef = this_n2->coef;
				ptr->exp = this_n2->exp;
				this_n2 = this_n2->next;
			}
			else  /* 兩個多項式指數相等，進行相加 */
			{
				ptr->coef = this_n1->coef + this_n2->coef;
				ptr->exp = this_n1->exp;
				if(this_n1 != NULL) this_n1 = this_n1->next;
				if(this_n2 != NULL) this_n2 = this_n2->next;
			}
		if(ptr->coef != 0)  /* 當相加結果不等於0，則放入答案多項式中 */
		{
			if(ans_h == NULL) ans_h = ptr;
			else prev->next = ptr;
			prev = ptr;
		}
		else free(ptr);
	}
}

void show_ans(void)
{
	struct poly *this_n;
	this_n = ans_h;
	printf("The answer equation: ");
	while(this_n != NULL)
	{
		printf("%dx^%d", this_n->coef, this_n->exp);
		if(this_n->next != NULL && this_n->next->coef >= 0)
			printf("+");
		this_n = this_n->next;
	}
	printf("\n");
}
