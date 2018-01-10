/* file name: poly_add_list.c */
/* �h�����ۥ[--�ϥέ����ƦC��J��Ӯ榡��ax^b���h�����ۥ[ */
#include <stdio.h>
#include <stdlib.h>
void input(struct poly **);  /* ��J��� */
void poly_add(void);         /* �h�����ۥ[��� */
void show_ans(void);         /* ��ܦh�����ۥ[���G��� */

struct poly {
	int coef;   /* �h�����Y�� */
	int exp;    /* �h�������� */
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
	while(this_n1 != NULL || this_n2 != NULL) /* ���Ӧh�����Ҭۥ[�����h���� */
	{
		ptr = (struct poly *) malloc(sizeof(struct poly));
		ptr->next = NULL;
		/* �Ĥ@�Ӧh�������Ƥj��ĤG�Ӧh���� */
		if(this_n1 != NULL && (this_n2 == NULL || this_n1->exp > this_n2->exp))
		{
			ptr->coef = this_n1->coef;
			ptr->exp = this_n1->exp;
			this_n1 = this_n1->next;
		}
		else
			/* �Ĥ@�Ӧh�������Ƥp��ĤG�Ӧh���� */
			if(this_n1 == NULL || this_n1->exp < this_n2->exp)
			{
				ptr->coef = this_n2->coef;
				ptr->exp = this_n2->exp;
				this_n2 = this_n2->next;
			}
			else  /* ��Ӧh�������Ƭ۵��A�i��ۥ[ */
			{
				ptr->coef = this_n1->coef + this_n2->coef;
				ptr->exp = this_n1->exp;
				if(this_n1 != NULL) this_n1 = this_n1->next;
				if(this_n2 != NULL) this_n2 = this_n2->next;
			}
		if(ptr->coef != 0)  /* ��ۥ[���G������0�A�h��J���צh������ */
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
