/* 利用AVL-TREE 處理學生資料--取檔、存檔、插入、刪除、修改、輸出 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void load_f(void);    /* 取檔函數 */
void save_f(void);    /* 存檔函數 */
void insert_f(void);  /* 插入函數 */
void delete_f(void);  /* 刪除函數 */
void modify_f(void);  /* 修改函數 */
void list_f(void);    /* 輸出函數 */
void sort_f(char[], char[]);      /* 插入檔案後排序 */
void inorder(struct student *);   /* 輸出使用中序追蹤 */
void preorder(FILE *, struct student *);  /* 存檔使用前序追蹤 */
void bf_count(struct student *);  /* 計算節點BF值 */
int height_count(struct student *);   /* 計算節點高度 */
void pivot_find(void);   /* 找出pivot所在節點 */
void ptr_find(struct student *);  /* 於刪除時找出PTR所在位置 */
int type_find(void);     /* 找出改善方法 */
void type_ll(void);      /* 使用LL型態 */
void type_rr(void);      /* 使用RR型態 */
void type_lr(void);      /* 使用LR型態 */
void type_rl(void);      /* 使用RL型態 */
void anykey_f(void);
struct student {
	char name[20];  /* 姓名 */
	int score;  /* 分數 */
	int bf;  /* 節點BF值 */
	struct student *llink, *rlink;  /* 節點子鏈結 */
};
struct student *ptr, *root, *this_n, *prev, *pivot, *pivot_prev;

void main()
{
	char option;
	load_f();
	while(1)
	{
		system("cls");
		printf(" *****************************\n");
		printf("         <1> insert\n");
		printf("         <2> delete\n");
		printf("         <3> modify\n");
		printf("         <4> list\n");
		printf("         <5> exit\n");
		printf(" *****************************\n");
		printf("  Please input your choice: ");
		option = getche();
		switch(option)
		{
			case '1':
				insert_f();
				break;
			case '2':
				delete_f();
				break;
			case '3':
				modify_f();
				break;
			case '4':
				list_f();
				break;
			case '5':
				save_f();
				exit(0);
		}
	}
}

void load_f()
{
	FILE *fptro;
	char name_t[20], score_t[4];
	/* 開檔時，若找不到檔案，則要求輸入第一筆資料 */
	if((fptro = fopen("dfile.dat","r")) == NULL)
	{
		printf(" File student.dat not found\n");
		printf(" The data can not be loaded\n");
		printf(" Press any key to insert the first data...");
		getch();
		insert_f();
	}
	else
	{
		while(fscanf(fptro, "%s %s", name_t, score_t) != EOF)
			sort_f(name_t, score_t);
		fclose(fptro);
	}
}

void save_f()
{
	FILE *fptri;
	fptri = fopen("dfile.dat","w");
	preorder(fptri, root);   /* 資料寫入檔案是使用前序法寫入 */
	fclose(fptri);
}

void insert_f(void)
{
	char name_t[20], score_t[4];
	system("cls");
	printf(" Please enter student name: ");
	gets(name_t);
	printf(" Please enter student score: ");
	gets(score_t);
	sort_f(name_t, score_t);   /* 呼叫SORT_F函數作排序及平衡 */
}

void sort_f(char name_t[], char score_t[])
{
	int op;
	this_n = root;
	while((this_n != NULL) && (strcmp(name_t, this_n->name) != 0))
	{
		if(strcmp(name_t, this_n->name) < 0)  /* 插入資料小於目前位置，則往左移 */
		{
			prev = this_n;
			this_n = this_n->llink;
		}
		else   /* 若大於目前位置，則往右移 */
		{
			prev = this_n;
			this_n = this_n->rlink;
		}
	}
	if(this_n == NULL || strcmp(name_t, this_n->name) != 0)  /* 找到插入位置，無重覆資料存在 */
	{
		ptr = (struct student *) malloc(sizeof(struct student));
		strcpy(ptr->name, name_t);
		ptr->score = atoi(score_t);
		ptr->llink = NULL;
		ptr->rlink = NULL;
		if(root == NULL) root = ptr;   /* ROOT不存在，則將ROOT指向插入資料 */
			if(prev != NULL)
				if(strcmp(ptr->name, prev->name) < 0) prev->llink = ptr;
				else prev->rlink = ptr;
		bf_count(root);
		pivot_find();
		if(pivot != NULL)   /* PIVOT存在，則須改善為AVL-TREE */
		{
			op = type_find();
			switch(op)
			{
				case 11:
					type_ll();
					break;
				case 22:
					type_rr();
					break;
				case 12:
					type_lr();
					break;
				case 21:
					type_rl();
					break;
			}
		}
		bf_count(root);  /* 重新計算每個節點的BF值 */
	}
	else
	{ /* 欲插入資料KEY已存在，則顯示錯誤 */
		printf(" Student %s has existed\n", name_t);
		anykey_f();
	}
}

void delete_f(void)
{
	struct student *clear;
	char name_t[20];
	int op;
	system("cls");
	/* 若根不存在，則顯示錯誤 */
	if(root == NULL)
		printf(" No student record\n");
	else
	{
		printf(" Please enter student name to delete: ");
		gets(name_t);
		this_n = root;
		while(this_n != NULL && strcmp(name_t, this_n->name) != 0)
		{
			/* 若刪除資料鍵值小於目前所在資料，則往左子樹 */
			if(strcmp(name_t, this_n->name) < 0)
			{
				prev = this_n;
				this_n = this_n->llink;
			}
			/* 否則則往右子樹 */
			else
			{
				prev = this_n;
				this_n = this_n->rlink;
			}
		}
		/* 找到欲刪除資料的狀況 */
		if(strcmp(name_t, this_n->name) == 0)
		{
			/* 當欲刪除資料底下無左右子樹存在的狀況 */
			if(this_n->llink == NULL && this_n->rlink == NULL)
			{
				clear = this_n;
				if(strcmp(name_t, root->name) == 0)  /* 欲刪除資料為根 */
					root = NULL;
				else
				{
					/* 若不為根，則判斷其為左子樹或右子樹 */
					if(strcmp(name_t, prev->name) < 0)
						prev->llink = NULL;
					else
						prev->rlink = NULL;
					ptr_find(prev);    /* 從PREV的位置開始往下找PTR */
				}
				free(clear);
			}
			else
			{
				/* 以左子樹最大點代替刪除資料 */
				if(this_n->llink != NULL)
				{
					clear = this_n->llink;
					while(clear->rlink != NULL)
					{
						prev = clear;
						clear = clear->rlink;
					}
					strcpy(this_n->name, clear->name);
					this_n->score = clear->score;
					if(this_n->llink == clear)
						this_n->llink = clear->llink;
					else
						prev->rlink = clear->llink;
				}
				/* 以右子樹最小點代替刪除資料 */
				else
				{
					clear = this_n->rlink;
					while(clear->llink != NULL)
					{
						prev = clear;
						clear = clear->llink;
					}
					strcpy(this_n->name, clear->name);
					this_n->score = clear->score;
					if(this_n->rlink == clear)
						this_n->rlink = clear->rlink;
					else
						prev->llink = clear->rlink;
				}
				ptr_find(this_n);    /* 從this_n的位置開始往下找PTR */
				free(clear);
			}
			bf_count(root);
			if(root != NULL)     /* 若根不存在，則無需作平衡改善 */
			{
				pivot_find();      /* 尋找PIVOT所在節點 */
				if(pivot != NULL)
				{
					op = type_find();
					switch(op)
					{
						case 11:
							type_ll();
							break;
						case 22:
							type_rr();
							break;
						case 12:
							type_lr();
							break;
						case 21:
							type_rl();
							break;
					}
				}
				bf_count(root);
			}
			printf(" Student data deleted\n");
		}
		/* 找不到刪除資料，則顯示錯誤 */
		else
			printf(" student %d not found\n", name_t);
	}
	anykey_f();
}

void modify_f(void)
{
	char name_t[20], score_t[4];
	system("cls");
	printf(" Please enter student name to update: ");
	gets(name_t);
	this_n = root;
	/* 尋找欲更改資料所在節點 */
	while((this_n != NULL) && (strcmp(name_t, this_n->name) != 0))
	{
		if(strcmp(name_t, this_n->name) < 0) this_n = this_n->llink;
		else this_n = this_n->rlink;
	}
	/* 若找到欲更改資料，則列出原資料，並要求輸入新的資料 */
	if(this_n != NULL)
	{
		printf(" ****************************\n");
		printf("  Student name : %s\n", this_n->name);
		printf("  Student score: %d\n", this_n->score);
		printf(" ****************************\n");
		printf(" Please enter new score: ");
		gets(score_t);
		this_n->score = atoi(score_t);
		printf(" Data update successfully\n");
	}
	/* 沒有找到資料則顯示錯誤 */
	else printf(" Student %s not found\n", name_t);
	anykey_f();
}

void list_f(void)
{
	system("cls");
	if(root == NULL) printf(" No student record\n");
	else
	{
		printf(" *****************************\n");
		printf("   Name                Score\n");
		printf("  ---------------------------\n");
		inorder(root);   /* 使用中序法輸出資料 */
		printf(" *****************************\n");
	}
	anykey_f();
}

void inorder(struct student *trees)  /* 中序使用遞迴 */
{
	if(trees != NULL)
	{
		inorder(trees->llink);
		printf("   %-20s %3d\n", trees->name, trees->score);
		inorder(trees->rlink);
	}
}

void preorder(FILE *fptr, struct student *trees) /* 前序採遞迴法 */
{
	if(trees != NULL)
	{
		fprintf(fptr, "%s %d\n", trees->name, trees->score);
		preorder(fptr, trees->llink);
		preorder(fptr, trees->rlink);
	}
}

void bf_count(struct student *trees)  /* 計算BF值，使用後序法逐一計算 */
{
	if(trees != NULL)
	{
		bf_count(trees->llink);
		bf_count(trees->rlink);
		/* BF值計算方式為左子樹高減去右子樹高 */
		trees->bf = height_count(trees->llink) - height_count(trees->rlink);
	}
}

int height_count(struct student *trees)
{
	if(trees == NULL) return 0;
	else
		if(trees->llink == NULL && trees->rlink == NULL) return 1;
		else return 1 + (height_count(trees->llink) > height_count(trees->rlink) ?
					height_count(trees->llink) : height_count(trees->rlink));
}

void pivot_find(void)
{
	this_n = root;
	pivot = NULL;
	while(this_n != ptr)
	{
		/* 當BF值的絕對值大於等於1，則將PIVOT指向此節點 */
		if(this_n->bf < -1 || this_n->bf > 1)
		{
			pivot = this_n;
			if(pivot != root) pivot_prev = prev;
		}
		if(strcmp(ptr->name, this_n->name) < 0)
		{
			prev = this_n;
			this_n = this_n->llink;
		}
		else
		{
			prev = this_n;
			this_n = this_n->rlink;
		}
	}
}

/* 因刪除資料時，並不存在判斷PIVOT所需的PTR指標，利用此函數找出 */
void ptr_find(struct student *temp)
{
	struct student *ltemp, *rtemp;
	int lcount = 0, rcount = 0;
	ltemp = rtemp = temp;
	while(ltemp->llink != NULL && ltemp->rlink != NULL)
	{
		while(ltemp->llink != NULL)
		{
			ltemp = ltemp->llink;
			lcount++;
		}
		while(ltemp->rlink != NULL)
		{
			ltemp = ltemp->rlink;
			lcount++;
		}
	}
	while(rtemp->rlink != NULL && rtemp->llink != NULL)
	{
		while(rtemp->rlink != NULL)
		{
			rtemp = rtemp->rlink;
			rcount++;
		}
		while(rtemp->llink != NULL)
		{
			rtemp = rtemp->llink;
			rcount++;
		}
	}
	/* 距離TEMP最遠的節點才為PTR可能的所在位置 */
	ptr = lcount > rcount ? ltemp : rtemp;
}

int type_find(void)
{
	int i, op_r = 0;
	this_n = pivot;
	for(i = 0; i < 2; i++)
	{
		if(strcmp(ptr->name, this_n->name) < 0)
		{
			this_n = this_n->llink;
			if(op_r == 0) op_r+=10;
			else op_r++;
		}
		else
		{
			this_n = this_n->rlink;
			if(op_r == 0) op_r+=20;
			else op_r+=2;
		}
	}
	/* 傳回值11、22、12、21分別代表LL、RR、LR、RL型態 */
	return op_r;
}

void type_ll(void)  /* LL型態 */
{
	struct student *pivot_next, *temp;
	pivot_next = pivot->llink;
	temp = pivot_next->rlink;
	pivot_next->rlink = pivot;
	pivot->llink = temp;
	if(pivot == root) root = pivot_next;
	else
		if(pivot_prev->llink == pivot)
			pivot_prev->llink = pivot_next;
		else
			pivot_prev->rlink = pivot_next;
}

void type_rr(void)  /* RR型態 */
{
	struct student *pivot_next, *temp;
	pivot_next = pivot->rlink;
	temp = pivot_next->llink;
	pivot_next->llink = pivot;
	pivot->rlink = temp;
	if(pivot == root) root = pivot_next;
	else
		if(pivot_prev->llink == pivot)
			pivot_prev->llink = pivot_next;
		else
			pivot_prev->rlink = pivot_next;
}

void type_lr(void)  /* LR型態 */
{
	struct student *pivot_next, *temp;
	pivot_next = pivot->llink;
	temp = pivot_next->rlink;
	pivot->llink = temp->rlink;
	pivot_next->rlink = temp->llink;
	temp->llink = pivot_next;
	temp->rlink = pivot;
	if(pivot == root) root = temp;
	else
		if(pivot_prev->llink == pivot)
			pivot_prev->llink = temp;
		else
			pivot_prev->rlink = temp;
}

void type_rl(void)  /* RL型態 */
{
	struct student *pivot_next, *temp;
	pivot_next = pivot->rlink;
	temp = pivot_next->llink;
	pivot->rlink = temp->llink;
	pivot_next->llink = temp->rlink;
	temp->rlink = pivot_next;
	temp->llink = pivot;
	if(pivot == root) root = temp;
	else
		if(pivot_prev->llink == pivot)
			pivot_prev->llink = temp;
		else
			pivot_prev->rlink = temp;
}

void anykey_f(void)
{
	printf(" Press any key to continue...");
	getch();
}
