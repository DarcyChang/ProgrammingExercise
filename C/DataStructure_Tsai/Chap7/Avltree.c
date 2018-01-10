/* �Q��AVL-TREE �B�z�ǥ͸��--���ɡB�s�ɡB���J�B�R���B�ק�B��X */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void load_f(void);    /* ���ɨ�� */
void save_f(void);    /* �s�ɨ�� */
void insert_f(void);  /* ���J��� */
void delete_f(void);  /* �R����� */
void modify_f(void);  /* �ק��� */
void list_f(void);    /* ��X��� */
void sort_f(char[], char[]);      /* ���J�ɮ׫�Ƨ� */
void inorder(struct student *);   /* ��X�ϥΤ��ǰl�� */
void preorder(FILE *, struct student *);  /* �s�ɨϥΫe�ǰl�� */
void bf_count(struct student *);  /* �p��`�IBF�� */
int height_count(struct student *);   /* �p��`�I���� */
void pivot_find(void);   /* ��Xpivot�Ҧb�`�I */
void ptr_find(struct student *);  /* ��R���ɧ�XPTR�Ҧb��m */
int type_find(void);     /* ��X�ﵽ��k */
void type_ll(void);      /* �ϥ�LL���A */
void type_rr(void);      /* �ϥ�RR���A */
void type_lr(void);      /* �ϥ�LR���A */
void type_rl(void);      /* �ϥ�RL���A */
void anykey_f(void);
struct student {
	char name[20];  /* �m�W */
	int score;  /* ���� */
	int bf;  /* �`�IBF�� */
	struct student *llink, *rlink;  /* �`�I�l�쵲 */
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
	/* �}�ɮɡA�Y�䤣���ɮסA�h�n�D��J�Ĥ@����� */
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
	preorder(fptri, root);   /* ��Ƽg�J�ɮ׬O�ϥΫe�Ǫk�g�J */
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
	sort_f(name_t, score_t);   /* �I�sSORT_F��Ƨ@�ƧǤΥ��� */
}

void sort_f(char name_t[], char score_t[])
{
	int op;
	this_n = root;
	while((this_n != NULL) && (strcmp(name_t, this_n->name) != 0))
	{
		if(strcmp(name_t, this_n->name) < 0)  /* ���J��Ƥp��ثe��m�A�h������ */
		{
			prev = this_n;
			this_n = this_n->llink;
		}
		else   /* �Y�j��ثe��m�A�h���k�� */
		{
			prev = this_n;
			this_n = this_n->rlink;
		}
	}
	if(this_n == NULL || strcmp(name_t, this_n->name) != 0)  /* ��촡�J��m�A�L���и�Ʀs�b */
	{
		ptr = (struct student *) malloc(sizeof(struct student));
		strcpy(ptr->name, name_t);
		ptr->score = atoi(score_t);
		ptr->llink = NULL;
		ptr->rlink = NULL;
		if(root == NULL) root = ptr;   /* ROOT���s�b�A�h�NROOT���V���J��� */
			if(prev != NULL)
				if(strcmp(ptr->name, prev->name) < 0) prev->llink = ptr;
				else prev->rlink = ptr;
		bf_count(root);
		pivot_find();
		if(pivot != NULL)   /* PIVOT�s�b�A�h���ﵽ��AVL-TREE */
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
		bf_count(root);  /* ���s�p��C�Ӹ`�I��BF�� */
	}
	else
	{ /* �����J���KEY�w�s�b�A�h��ܿ��~ */
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
	/* �Y�ڤ��s�b�A�h��ܿ��~ */
	if(root == NULL)
		printf(" No student record\n");
	else
	{
		printf(" Please enter student name to delete: ");
		gets(name_t);
		this_n = root;
		while(this_n != NULL && strcmp(name_t, this_n->name) != 0)
		{
			/* �Y�R�������Ȥp��ثe�Ҧb��ơA�h�����l�� */
			if(strcmp(name_t, this_n->name) < 0)
			{
				prev = this_n;
				this_n = this_n->llink;
			}
			/* �_�h�h���k�l�� */
			else
			{
				prev = this_n;
				this_n = this_n->rlink;
			}
		}
		/* �����R����ƪ����p */
		if(strcmp(name_t, this_n->name) == 0)
		{
			/* ����R����Ʃ��U�L���k�l��s�b�����p */
			if(this_n->llink == NULL && this_n->rlink == NULL)
			{
				clear = this_n;
				if(strcmp(name_t, root->name) == 0)  /* ���R����Ƭ��� */
					root = NULL;
				else
				{
					/* �Y�����ڡA�h�P�_�䬰���l��Υk�l�� */
					if(strcmp(name_t, prev->name) < 0)
						prev->llink = NULL;
					else
						prev->rlink = NULL;
					ptr_find(prev);    /* �qPREV����m�}�l���U��PTR */
				}
				free(clear);
			}
			else
			{
				/* �H���l��̤j�I�N���R����� */
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
				/* �H�k�l��̤p�I�N���R����� */
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
				ptr_find(this_n);    /* �qthis_n����m�}�l���U��PTR */
				free(clear);
			}
			bf_count(root);
			if(root != NULL)     /* �Y�ڤ��s�b�A�h�L�ݧ@���ŧﵽ */
			{
				pivot_find();      /* �M��PIVOT�Ҧb�`�I */
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
		/* �䤣��R����ơA�h��ܿ��~ */
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
	/* �M�������ƩҦb�`�I */
	while((this_n != NULL) && (strcmp(name_t, this_n->name) != 0))
	{
		if(strcmp(name_t, this_n->name) < 0) this_n = this_n->llink;
		else this_n = this_n->rlink;
	}
	/* �Y��������ơA�h�C�X���ơA�ín�D��J�s����� */
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
	/* �S������ƫh��ܿ��~ */
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
		inorder(root);   /* �ϥΤ��Ǫk��X��� */
		printf(" *****************************\n");
	}
	anykey_f();
}

void inorder(struct student *trees)  /* ���Ǩϥλ��j */
{
	if(trees != NULL)
	{
		inorder(trees->llink);
		printf("   %-20s %3d\n", trees->name, trees->score);
		inorder(trees->rlink);
	}
}

void preorder(FILE *fptr, struct student *trees) /* �e�ǱĻ��j�k */
{
	if(trees != NULL)
	{
		fprintf(fptr, "%s %d\n", trees->name, trees->score);
		preorder(fptr, trees->llink);
		preorder(fptr, trees->rlink);
	}
}

void bf_count(struct student *trees)  /* �p��BF�ȡA�ϥΫ�Ǫk�v�@�p�� */
{
	if(trees != NULL)
	{
		bf_count(trees->llink);
		bf_count(trees->rlink);
		/* BF�ȭp��覡�����l�𰪴�h�k�l�� */
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
		/* ��BF�Ȫ�����Ȥj�󵥩�1�A�h�NPIVOT���V���`�I */
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

/* �]�R����ƮɡA�ä��s�b�P�_PIVOT�һݪ�PTR���СA�Q�Φ���Ƨ�X */
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
	/* �Z��TEMP�̻����`�I�~��PTR�i�઺�Ҧb��m */
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
	/* �Ǧ^��11�B22�B12�B21���O�N��LL�BRR�BLR�BRL���A */
	return op_r;
}

void type_ll(void)  /* LL���A */
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

void type_rr(void)  /* RR���A */
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

void type_lr(void)  /* LR���A */
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

void type_rl(void)  /* RL���A */
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
