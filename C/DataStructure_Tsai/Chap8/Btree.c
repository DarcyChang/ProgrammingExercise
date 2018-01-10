/* �Q��B-TREE�ӳB�z���--���J�B�x�s�B�s�W�B�R���B�ק�B�d�ߡB��X */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define MAX 2    /* �C�@�`�I���ܦh�i���Ƶ��� */
#define MIN 1    /* �C�@�`�I���ܤֻݩ��Ƶ��� */

typedef struct student {    /* ��Ƶ��c */
	int count;                /* �`�I��Ƽ� */
	int id[MAX+1];            /* ID���X--��� */
	char name[MAX+1][11];     /* �m�W */
	int score[MAX+1];         /* ���� */
	struct student *link[MAX+1];    /* �l�쵲 */
} Node_type;

Node_type *root;

void init_f(FILE *);  /* ��l�ƨ�� */
void insert_f(void);  /* �s�W��� */
Node_type *access(int, char *, int, Node_type *);  /* �N�s�W��ƥ[�JB-tree�� */
int topdown(int, char *, int, Node_type *, int *, char *, int *,
			Node_type **);  /* �q�ڸ`�I���U�v�@�M�䴡�J�I�A�N��Ʒs�W����� */
/* �N��Ƹm��Y�S�w�`�I�� */
void putdata(int, char *, int, Node_type *, Node_type *, int);
void broken(int, char *, int, Node_type *, Node_type *, int, int *, char *,
			int *, Node_type **);  /* �N�@�`�I�������G */
void update_f(void);  /* �ק��� */
void delete_f(void);  /* �R����� */
Node_type *removing(int, Node_type *);  /* �N��ƱqB-tree���R�� */
int deldata(int, Node_type *);  /* �R����ƨ�� */
void move(Node_type *, int);  /* �N�`�I������Ƴv�@������ */
void replace(Node_type *, int);  /* �M����N�`�I */
void restore(Node_type *, int);  /* ��ƧR���᪺�վ�u�@ */
void getleft(Node_type *, int);  /* �V���S�̸`�I�ɤ@����� */
void getright(Node_type *, int);  /* �V�k�S�̸`�I�ɤ@����� */
void combine(Node_type *, int);  /* �`�I�X�� */
void list_f(void);  /* ��X��� */
void show(Node_type *);  /* �H���j�覡�̧ǱN��ƿ�X */
void query_f(void);  /* �d�ߨ�� */
void save(Node_type *, FILE *);  /* �x�s��� */
void quit(void);  /* ������� */
Node_type * search(int, Node_type *, int *);  /* ����ȷj�M�Y�S�w�`�I��� */
int searchnode(int, Node_type *, int *);  /* ����ȷj�M�`�I���Y�S�w��ƨ�� */

void main(void)
{
	int flag=0, times=1;  /* times�O�P�_�O�_���Ĥ@���i�J�ݭn���J��J�ɮ� */
	FILE *infile, *outfile;
	char choice, filename[11], ans;
	system("cls");
	while(1)
	{
		if(times == 1)
		{
			do
			{
				/* �n�D��J���J�ɮצW�� */
				printf("\n  Please enter input file name: ");
				scanf("%s", filename);
				if((infile = fopen(filename, "r")) == NULL)
				{
					puts("  File name not found!!");
					flag = 0;
				}
				else
					flag = 1;
			}  while(flag == 0);  /* flag��0�ɡA��ܿ�J���~�A�|�n�D���s��J */
			times++;
		}
		fseek(infile, 0, 0);
		init_f(infile);
		do
		{
			printf("\n");
			puts("  *********************");
			puts("        1.insert");
			puts("        2.update");
			puts("        3.delete");
			puts("        4.list");
			puts("        5.query");
			puts("        6.save");
			puts("        7.quit");
			puts("  *********************");
			printf("  Please enter your choice(1..7): ");
			choice = getche();
			printf("\n");
			switch(choice)
			{
				case '1':
					insert_f();
					break;
				case '2':
					update_f();
					break;
				case '3':
					delete_f();
					break;
				case '4':
					list_f();
					break;
				case '5':
					query_f();
					break;
				case '6':
					flag = 0;
					do
					{
						puts("\n  ---- SAVE ----");
						printf("  Please enter saving file name: ");
						scanf("%s", filename);
						if((outfile = fopen(filename, "w")) == NULL)
						{
							puts(" File name can not be used!!");
							flag = 0;
						}
						else
							flag = 1;
					}  while(flag == 0);
					save(root, outfile);
					printf("  Save OK!\n");
					fclose(outfile);
					break;
				case '7': printf("  Are you sure? (Y/N): ");
					ans = getche();
					ans = toupper(ans);
					if(ans == 'Y')
					{
						fclose(infile);
						quit();
					}
					break;
				default: puts("  Choice error!!");
			}
		}  while(choice != '7');
	}
}


/* Ū�J��J�ɸ�Ʀ�B-tree���Ainfile����J�ɮצW�� */
void init_f(FILE *infile)
{
	int init_id, init_score;
	char init_name[11];
	root = NULL;
	while(fscanf(infile, "%d %10s %d\n", &init_id, init_name, &init_score)
					!= EOF)
	{
		root = access(init_id, init_name, init_score, root);
	}
}

/* �s�W�@����ơA�ýվ㬰B-tree */
void insert_f(void)
{
	int position, insert_id, insert_score; /* position�O����Ʀb�`�I���s�W����m */
	Node_type *node;
	char ans, insert_name[11];
	puts("\n  ---- INSERT ----");
	puts("  Please enter detail data");
	printf("  ID number: ");
	scanf("%d", &insert_id);
	/* ��M�s�W��ƬO�_�w�s�b�A�Y�s�b�A�h��ܿ��~ */
	node = search(insert_id, root, &position);
	if(node != NULL)
		puts(" ID number has existed!!");
	else
	{
		printf("  Name: ");  /* �n�D��J��L�ԲӸ�� */
		scanf("%s'", insert_name);
		printf("  Score: ");
		scanf("%d", &insert_score);
		printf("  Are you sure? (Y/N): ");
		ans = getche();
		printf("\n");
		ans = toupper(ans);
		if(ans == 'Y')
			root = access(insert_id, insert_name, insert_score, root);
	}
}

/* �N�s�W��ƥ[�JB-TREE�Anode���[�J�`�I�A�Ǧ^�Ȭ�root�Ҧb */
Node_type *access(int app_id, char *app_name, int app_score, Node_type *node)
{
	int x_id, x_score, pushup;  /* pushup�P�_�`�I�O�_�ݹ����ө��W�s�W�@�`�I */
	char x_name[11];
	Node_type *xr, *p;
	pushup = topdown(app_id, app_name, app_score, node, &x_id, x_name,
						&x_score, &xr);
	if(pushup)  /* �Ypushup��1�A�h�t�m�@�ӷs�`�I�A�N��Ʃ�J */
	{
		p = (Node_type *) malloc(sizeof(Node_type));
		p->link[0] = NULL;
		p->link[1] = NULL;
		p->link[2] = NULL;
		p->count = 1;
		p->id[1] = x_id;
		strcpy(p->name[1], x_name);
		p->score[1] = x_score;
		p->link[0] = root;
		p->link[1] = xr;
		return p;
	}
	return node;
}


/* �q��ک��U�M���ƥ[�J�`�I�A�N��Ʒs�W��B-tree���A�Ѽ�p���ثe�Ҧb�`�I�A
   xr�O����Ʃҹ������l�쵲 */
int topdown(int new_id, char *new_name, int new_score, Node_type *p,
			int *x_id, char *x_name, int *x_score, Node_type **xr)
{
	int k;
	if(p == NULL)  /* p��NULL��ܷs�W�Ĥ@����� */
	{
		*x_id = new_id;
		strcpy(x_name, new_name);
		*x_score = new_score;
		*xr = NULL;
		return 1;
	}
	else
	{
		if(searchnode(new_id, p, &k))  /* ��M�s�W�����ȬO�_���СA�Y���Ыh��ܿ��~ */
		{
			puts("  Data error, ID number has existed!!");
			quit();
			return 0;
		}
		/* �~�򩹤U��M�s�W�`�I */
		if(topdown(new_id, new_name, new_score, p->link[k], x_id, x_name,
					x_score, xr))
		{
			if(p->count < MAX)  /* �Y�s�W�`�I���������Ŷ��s���ơA�h�N��ƪ����[�J�Ӹ`�I */
			{
			putdata(*x_id, x_name, *x_score, *xr, p, k);
			return 0;
			}
			else
			{
				/* �Y�L�����Ŷ��A�h�������`�I */
				broken(*x_id, x_name, *x_score, *xr, p, k, x_id, x_name, x_score, xr);
				return 1;
			}
		}
		else
			return 0;
	}
}

/* �N�s�W��ƪ����[�J��`�I���Axr���s�W��ƹ������l�쵲�Ҧb�Ap����ƥ[�J���`�I */
void putdata(int x_id, char *x_name, int x_score, Node_type *xr,
				Node_type *p, int k)
{
	int i;
	/* �N�`�I������Ƴv�@�k���A�H�ťX�s�W��ƥ[�J����m */
	for(i = p->count; i > k; i--)
	{
		p->id[i+1] = p->id[i];
		strcpy(p->name[i+1], p->name[i]);
		p->score[i+1] = p->score[i];
		p->link[i+1] = p->link[i];
	}
	p->id[k+1] = x_id;
	strcpy(p->name[k+1], x_name);
	p->score[k+1] = x_score;
	p->link[k+1] = xr;
	p->count++;
}

/* �N�`�I�@�����G�Ayr��������s�W�[���`�I */
void broken(int x_id, char *x_name, int x_score, Node_type *xr, Node_type *p,
			int k, int *y_id, char *y_name, int *y_score, Node_type **yr)
{
	int i;
	int median;  /* median�O���q��B�����`�I */
	if(k <= MIN)
		median = MIN;
	else
		median = MIN + 1;
	*yr = (Node_type *) malloc(sizeof(Node_type));
	/* �N��Ʊq�����B�}�l�h���ܷs�`�I�� */
	for(i = median + 1; i <= MAX; i++)
	{
		(*yr)->id[i-median] = p->id[i];
		strcpy((*yr)->name[i-median], p->name[i]);
		(*yr)->score[i-median] = p->score[i];
		(*yr)->link[i-median] = p->link[i];
	}
	(*yr)->count = MAX - median;
	p->count = median;
	if(k <= MIN)
		putdata(x_id, x_name, x_score, xr, p, k);
	else
		putdata(x_id, x_name, x_score, xr, *yr, k - median);
	*y_id = p->id[p->count];
	strcpy(y_name, p->name[p->count]);
	*y_score = p->score[p->count];
	(*yr)->link[0] = p->link[p->count];
	p->count--;
}

/* �ק��ƨ�� */
void update_f(void)
{
	int update_id, update_score, position;
	char ans, update_name[11];
	Node_type *node;
	puts("\n  ---- UPDATE ----");
	printf("  Please enter ID number: ");
	scanf("%d", &update_id);
	node = search(update_id, root, &position);  /* ��M���ק��ƩҦb�`�I��m */
	if(node != NULL)
	{
		printf("  Original name: %s\n", node->name[position]);
		printf("  Please enter new name: ");
		scanf("%10s", update_name);
		printf("  Original score: %d\n", node->score[position]);
		printf("  Please enter new score: ");
		scanf("%d", &update_score);
		printf("  Are you sure? (Y/N): ");
		ans = getche();
		printf("\n");
		ans = toupper(ans);
		if(ans == 'Y')
		{
			node->score[position] = update_score;
			strcpy(node->name[position], update_name);
		}
	}
	else
		puts("  ID number not found!!");
}

/* �R����ƨ�� */
void delete_f(void)
{
	int del_id, position;  /* position�O���R����Ʀb�`�I������m */
	char ans;
	Node_type *node;
	puts("\n  ---- DELETE ----");
	printf("  Please enter ID number: ");
	scanf("%d", &del_id);
	node = search(del_id, root, &position);
	if(node != NULL)
	{
		printf("  Are you sure? (Y/N): ");
		ans = getche();
		printf("\n");
		ans = toupper(ans);
		if(ans == 'Y')
			root = removing(del_id, root);
	}
	else
		puts("  ID number not found!!");
}

/* �N��ƱqB-tree���R���A�Y�R����`�I����Ƶ��Ƭ�0�A�h�@�֧R���Ӹ`�I */
Node_type *removing(int del_id, Node_type *node)
{
	Node_type *p;
	if(!deldata(del_id, node));
	else
		if(node->count == 0)
		{
			p = node;
			node = node->link[0];
			free(p);
		}
	return node;
}

/* �N��ƱqB-tree�������A�Y�R�����ѫh�Ǧ^0�A�_�h�Ǧ^��Ʀb�`�I���Ҧb��m */
int deldata(int del_id, Node_type *p)
{
	int k;
	int found;
	if(p == NULL)
		return 0;
	else
	{
		if((found = searchnode(del_id, p, &k)) != 0)
		{
			if(p->link[k-1])
			{
			replace(p, k);
			if(!(found = deldata(p->id[k], p->link[k])))
				printf("  Key not found");
			}
			else
			move(p,k);
		}
		else
			found = deldata(del_id, p->link[k]);
		if(p->link[k] != NULL)
		{
			if(p->link[k]->count < MIN)
			restore(p, k);
		}
		return found;
	}
}

/* �N�`�I������Ʊqk����m�v�@���� */
void move(Node_type *p, int k)
{
	int i;
	for(i = k+1; i <= p->count; i++)
	{
		p->id[i-1] = p->id[i];
		strcpy(p->name[i-1], p->name[i]);
		p->score[i-1] = p->score[i];
		p->link[i-1] = p->link[i];
	}
	p->count--;
}

/* �M��R���D�𸭮ɪ����N��� */
void replace(Node_type *p, int k)
{
	Node_type *q;
	for(q = p->link[k]; q->link[0]; q = q->link[0]);
	p->id[k] = q->id[1];
	strcpy(p->name[k], q->name[1]);
	p->score[k] = q->score[1];
}

/* ��ƧR����A���s�վ㬰B-tree */
void restore(Node_type *p, int k)
{
	if(k == 0)  /* �R����Ƭ��`�I�����Ĥ@����� */
	{
		if(p->link[1]->count > MIN)
			getright(p, 1);
		else
			combine(p, 1);
	}
	else
		if(k == p->count)  /* �R����Ƭ��`�I�����̫�@����� */
		{
			if(p->link[k-1]->count > MIN)
				getleft(p, k);
			else
				combine(p, k);
		}
		else  /* �R����Ƭ��`�I����L��m����� */
			if(p->link[k-1]->count > MIN)
				getleft(p, k);
			else
				if(p->link[k+1]->count > MIN)
					getright(p, k+1);
				else
					combine(p, k);
}

/* �V���S�̸`�I�ɸ�ƮɡA����ƥk�����ʧ@ */
void getleft(Node_type *p, int k)
{
	int c;
	Node_type *t;
	t = p->link[k];
	for(c = t->count; c > 0; c--)
	{
		t->id[c+1] = t->id[c];
		strcpy(t->name[c+1], t->name[c]);
		t->score[c+1] = t->score[c];
		t->link[c+1] = t->link[c];
	}
	t->link[1] = t->link[0];
	t->count++;
	t->id[1] = p->id[k];
	strcpy(t->name[1], p->name[k]);
	t->score[1] = p->score[k];
	t = p->link[k-1];
	p->id[k] = t->id[t->count];
	strcpy(p->name[k], t->name[t->count]);
	p->score[k] = t->score[t->count];
	p->link[k]->link[0] = t->link[t->count];
	t->count--;
}

/* �V�k�S�̸`�I�ɸ�ƮɡA���������ʧ@ */
void getright(Node_type *p, int k)
{
	int c;
	Node_type *t;
	t = p->link[k-1];
	t->count++;
	t->id[t->count] = p->id[k];
	strcpy(t->name[t->count], p->name[k]);
	t->score[t->count] = p->score[k];
	t->link[t->count] = p->link[k]->link[0];
	t = p->link[k];
	p->id[k] = t->id[1];
	strcpy(p->name[k], t->name[1]);
	p->score[k] = t->score[1];
	t->link[0] = t->link[1];
	t->count--;
	for(c = 1; c <= t->count; c++)
	{
		t->id[c] = t->id[c+1];
		strcpy(t->name[c], t->name[c+1]);
		t->score[c] = t->score[c+1];
		t->link[c] = t->link[c+1];
	}
}

/* �N�T�Ӹ`�I������ƦX�֦ܤ@�Ӹ`�I�� */
void combine(Node_type *p, int k)
{
	int c;
	Node_type *l, *q;
	q = p->link[k];
	l = p->link[k-1];
	l->count++;
	l->id[l->count] = p->id[k];
	strcpy(l->name[l->count], p->name[k]);
	l->score[l->count] = p->score[k];
	l->link[l->count] = q->link[0];
	for(c = 1; c <= q->count; c++)
	{
		l->count++;
		l->id[l->count] = q->id[c];
		strcpy(l->name[l->count], q->name[c]);
		l->score[l->count] = q->score[c];
		l->link[l->count] = q->link[c];
	}
	for(c = k; c < p->count; c++)
	{
		p->id[c] = p->id[c+1];
		strcpy(p->name[c], p->name[c+1]);
		p->score[c] = p->score[c+1];
		p->link[c] = p->link[c+1];
	}
	p->count--;
	free(q);
}

/* ��ƿ�X��� */
void list_f(void)
{
	puts("\n  ---- LIST ----");
	puts("  *******************************");
	puts("      ID     NAME       SCORE");
	puts("   =============================");
	show(root);
	puts("  *******************************");
}

/* �H���j�覡��X�`�I��ơA��X��ƱĤ��Ǫk�And������X��ƪ��`�I */
void show(Node_type *nd)
{
	if(nd != NULL)
	{
		if(nd->count > 0)
		{
			if(nd->count == 1)
			{
				show(nd->link[0]);
				printf("      %-6d %-10s %4d\n",
					nd->id[1], nd->name[1], nd->score[1]);
				show(nd->link[1]);
			}
			else
			if(nd->count == 2)
			{
				show(nd->link[0]);
				printf("      %-6d %-10s %4d\n",
						nd->id[1], nd->name[1], nd->score[1]);
				show(nd->link[1]);
				printf("      %-6d %-10s %4d\n",
						nd->id[2], nd->name[2], nd->score[2]);
				show(nd->link[2]);
			}
		}
	}
}

/* �d�߬Y�@�S�w��� */
void query_f(void)
{
	int query_id, position;
	Node_type *quenode;
	puts("\n  ---- QUERY ----");
	printf("  Please enter ID number: ");
	scanf("%d", &query_id);
	quenode = search(query_id, root, &position);
	if(quenode != NULL)
	{
		printf("  ID number: %d\n", quenode->id[position]);
		printf("  Name: %s\n", quenode->name[position]);
		printf("  Score: %d\n", quenode->score[position]);
	}
	else
		puts("  ID number not found!!");
}

/* �NB-tree��������x�s���ɮפ� */
void save(Node_type *node, FILE *outfile)
{
	if(node->count != 0)
	{
		if(node->count == 1)
		{
			save(node->link[0], outfile);
			fprintf(outfile, "  %6d %10s %4d\n", node->id[1], node->name[1],
				  node->score[1]);
			save(node->link[1], outfile);
		}
		else
		if(node->count == 2)
		{
			save(node->link[0], outfile);
			fprintf(outfile, "  %6d %10s %4d\n", node->id[1], node->name[1],
				node->score[1]);
			save(node->link[1], outfile);
			fprintf(outfile, "  %6d %10s %4d\n", node->id[2], node->name[2],
				node->score[2]);
			save(node->link[2], outfile);
		}
	}
}

/* �������t�� */
void quit(void)
{
	printf("\n  Thanks for using, bye bye!!");
	exit(0);
}

/* �j�M�Y�@��ȩҦb�`�I�Atarget���j�M��ȡA�Ǧ^�Ȭ�target�Ҧb�`�I���СA�Y�S����
   ��h�Ǧ^NULL */
Node_type *search(int target, Node_type *node, int *targetpos)
{
	if(node == NULL)
		return NULL;
	else
		if(searchnode(target, node, targetpos))
			return node;
		else
			return search(target, node->link[*targetpos], targetpos);
}

/* �j�M�Y�@��Ȧb�`�I������m�Atarget���j�M��ȡAk�O����ȩҦb��m�A�Ǧ^0��
   �ܷj�M���ѡA�Ǧ^1��ܷj�M���\ */

int searchnode(int target, Node_type *p, int *k)
{
	if(target < p->id[1])
	{
		*k = 0;
		return 0;
	}
	else
	{
		*k = p->count;
		while((target < p->id[*k]) && *k > 1)
			(*k)--;
		if(target == p->id[*k])
			return 1;
		else
			return 0;
	}
}
