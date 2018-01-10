/* �إߤ@��M-WAY TREE�ӳB�z���--���J�B�x�s�B���J�B�R���B��X */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 3    /* �]�wM-WAY TREE���̤j�`�I�� */

typedef struct mway_tree {      /* �w�q������ */
	char id;                      /* ��X���ѧO�`�I */
	int n;                        /* �`�I������ȼ� */
	int key[MAX];                 /* �`�I��� */
	struct mway_tree *link[MAX];  /* �`�I�l��` */
} Node_type;

void load_f(void);      /* ���J��� */
void save_f(void);      /* �x�s��� */
void insert_f(void);    /* ���J��� */
void delete_f(void);    /* �R����� */
void display_f(void);   /* ��X��� */
void create(int);       /* �[�J��ƫ�վ㬰M-WAY TREE */
void removes(Node_type *, int);  /* ������ƫ�վ㬰M-WAY TREE */
void initial(void);     /* �`�I��l�� */
int search_num(int);    /* �j�M��ȩҦb�`�I��m */
Node_type *search_node(int);  /* �j�M��ȩҦb�`�I */
void moveright(int, int);     /* �`�I����Ʃ��k�� */
void moveleft(int);           /* �`�I����Ʃ����� */
Node_type *find_next(Node_type *);  /* �M����~�`�I */
Node_type *find_prev(Node_type *);  /* �M��e��`�I */
void preorder_id(Node_type *);    /* �����C�Ӹ`�I�ѧO�s�� */
void preorder_num(Node_type *);   /* ��X�`�I */
void preorder_save(Node_type *);  /* �N��ƿ�X���ɮ� */

Node_type *ptr, *root, *node, *prev, *parent, *replace;
char id_seq;
FILE *fptri, *fptro;

void main(void)
{
	char option;
	load_f();
	do
	{
		printf("\n ***************************\n");
		printf("        <1> insert\n");
		printf("        <2> delete\n");
		printf("        <3> display\n");
		printf("        <4> quit\n");
		printf(" ***************************\n");
		printf(" Please enter your choice: ");
		option = getche();
		printf("\n");
		switch(option)
		{
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
				save_f();
				break;
			default : printf("\n Option error!!\n");
		}
	} while(option != '4');
}

/* ���J���--�N�ɮ׸�Ƹ��J */
void load_f(void)
{
	int add_num;
	if((fptri = fopen("dfile.dat", "r")) == NULL)  /* �}�ɥ�����ܿ��~�T�� */
	{
		printf(" File dfile.dat not found!!\n");
		printf(" Data can\'t be loaded!!\n");
	}
	else
	{
		printf(" Loading...");
		while(fscanf(fptri, "%d", &add_num) != EOF)
			create(add_num);
		printf("OK\n");
		fclose(fptri);
	}
}

/* �x�s���--�N����x�s���ɮ� */
void save_f(void)
{
	fptro = fopen("dfile.dat", "w");
	printf("\n Data save...");
	preorder_save(root);
	printf("OK\n");
	fclose(fptro);
}

/* ���J���--�s�W�@����� */
void insert_f(void)
{
	int add_num;
	printf("\n Please enter insert number: ");
	scanf("%d", &add_num);
	create(add_num);
}

/* �R�����--�R���@����� */
void delete_f(void)
{
	int del_num, ans;
	if(root == NULL)  /* ���ڬ�NULL�A��ܿ��~�T�� */
		printf("\n No data found!!\n");
	else
	{
		printf("\n Please enter delete number: ");
		scanf("%d", &del_num);
		ans = search_num(del_num);  /* �j�M��ƬO�_�s�b */
		if(ans == 0)  /* ���Ƥ��s�b�A��ܿ��~�T�� */
			printf(" Number %d not found!!\n", del_num);
		else
		{
			removes(node, ans);
			printf(" Number %d deleted!!\n", del_num);
		}
	}
}

/* ��X���--�NM-WAY TREE�����Ҧ���ƿ�X */
void display_f(void)
{
	if(root == NULL)  /* ���ڬ�NULL�A��ܿ��~�T�� */
		printf("\n No data found!!\n");
	else
	{
		id_seq = 'a';  /* �`�I�s����a�}�l */
		preorder_id(root);  /* �����C�Ӹ`�I�s�I */
		printf("\n =================================================\n");
		preorder_num(root); /* ��X�`�I��� */
		printf(" =================================================\n");
	}
}

/* �N��ƥ[�J�A�ýվ㬰M-WAY TREE�ANUM���s�W�������� */
void create(int num)
{
	int ans, i;
	if(root == NULL)  /* ��ڬ�NULL�����p */
	{
		initial();
		ptr->key[1] = num;
		ptr->n++;
		root = ptr;
	}
	else
	{
		ans = search_num(num);  /* �j�M��ƬO�_�w�s�b */
		if(ans != 0)  /* ��Ʀs�b�A�h��ܿ��~�T�� */
			printf(" Number %d has existed!!\n", num);
		else
		{
			node = search_node(num);  /* ��M���J�I */
			if(node != NULL)  /* ���J�I�٦��Ŷ��s���ƪ����p */
			{
				for(i = 1; i < MAX-1; i++)
					if(num < node->key[i]) break;
				moveright(i, num);
			}
			else  /* �s�W�[�@�Ӹ`�I�[�J��ƪ����p */
			{
				initial();
				ptr->key[1] = num;
				ptr->n++;
				for(i = 1; i < MAX; i++)
					if(num < prev->key[i]) break;
				prev->link[i-1] = ptr;
			}
		}
	}
}

/* �N��Ʋ����A�ýվ㬰M-WAY TREE�ANODE_TEMP���R����ƩҦb�`�I�A
   LOCATION����Ʀb�`�I������m */
void removes(Node_type *node_temp, int location)
{
	int i;
	node = node_temp;
	replace = find_next(node->link[location]); /* ��M���N�����~�`�I */
	if(replace == NULL)  /* �S�����~�`�I�����p */
	{
		replace = find_prev(node->link[location-1]); /* ��M���N���e��`�I */
		if(replace == NULL)  /* �S���e��`�I�����p */
		{
			moveleft(location);
			replace = node;
			if(node->n == 0)  /* �R����ƫ�A�`�I����Ƭ�0���B�z */
			{
				if(node == root)  /* ��`�I���ڪ����p */
					root = NULL;
				else  /* �`�I���O�ڡA�h�վ��쵲 */
					for(i = 0; i <= parent->n; i++)
						if(node == parent->link[i])
						{
							parent->link[i] = NULL;
							break;
						}
				free(replace);
			}
		}
		else  /* ���e��`�I�����p */
		{
			/* �H�e��`�I����ƥN���R����� */
			node->key[location] = replace->key[replace->n];
			parent = prev;
			removes(replace, replace->n);  /* �������N��� */
		}
	}
	else  /* �����~�`�I�����p */
	{
		/* �H���~�`�I����ƥN���R����� */
		node->key[location] = replace->key[1];
		parent = prev;
		removes(replace, 1);  /* �������N��� */
	}
}

/* ��l�Ƹ`�I--�s�W�@�Ӹ`�I�A�N��Ҧ��쵲���VNULL�A�]��`�I�Ƭ�0 */
void initial(void)
{
	int i;
	ptr = (Node_type *) malloc(sizeof(Node_type));
	for(i = 0; i < MAX; i++)
		ptr->link[i] = NULL;
	ptr->n = 0;
}

/* �j�M�`�I��m--�j�MNUM�A�s�b�h�^��NUM�b�`�I������m�A���s�b�h�^��0 */
int search_num(int num)
{
	int done, i;
	node = root;
	while(node != NULL)
	{
		parent = prev;
		prev = node;
		for(i = 1, done = 0; i <= node->n; i++)
		{
			if(num == node->key[i])
				return i;   /* ���NUM�A�^�Ǩ�b�`�I������m */
			if(num < node->key[i])
			{
				node = node->link[i-1];
				done = 1;
				break;
			}
		}
		if(done == 0)
			node = node->link[i-1];
	}
	return 0;   /* �S�����h�^��0 */
}

/* �j�M�`�I--�M�䴡�JNUM���`�I�A�æ^�Ǵ��J�`�I */
Node_type *search_node(int num)
{
	int i, done;
	Node_type *node_temp;
	node_temp = root;
	while(node_temp != NULL)
	{
		if(node_temp->n < MAX-1)
			return node_temp;  /* ��즳�h�l�Ŷ��s��NUM�A�h�^�Ǧ��`�I */
		else
		{
			for(i = 1, done = 0; i < MAX; i++)
			{
				if(node_temp->n < i)
					break;
				if(num < node_temp->key[i])
				{
					node_temp = node_temp->link[i-1];
					done = 1;
					break;
				}
			}
			if(done == 0)
				node_temp = node_temp->link[i-1];
		}
	}
	return node_temp;  /* �Y�S����즳�h�l�Ŷ��s��NUM���`�I�A�^��NULL */
}

/* �N�`�I����ƥk��--�N�`�I��ƥk����INDEX��m�A�ñNNUM���J */
void moveright(int index, int num)
{
	int i;
	for(i = node->n+1; i > index; i--)  /* ��ƥk����INDEX�B */
	{
		node->key[i] = node->key[i-1];
		node->link[i] = node->link[i-1];
	}
	node->key[i] = num;  /* ���JNUM */
	/* �վ�NUM���k�쵲 */
	if(node->link[i-1] != NULL && node->link[i-1]->key[0] > num)
	{
		node->link[i] = node->link[i-1];
		node->link[i-1] = NULL;
	}
	node->n++;
}

/* �N�`�I����ƥ���--�N�`�I��ƱqINDEX��m���� */
void moveleft(int index)
{
	int i;
	for(i = index; i < node->n; i++)  /* �`�I��ƥ��� */
	{
		node->key[i] = node->key[i+1];
		node->link[i] = node->link[i+1];
	}
	node->n--;
}

/* �M����~�`�I--�M��NODE_TEMP�����~�`�I�A�^�ǧ�쪺���~�`�I */
Node_type *find_next(Node_type *node_temp)
{
	prev = node;
	if(node_temp != NULL)
		while(node_temp->link[0] != NULL)
		{
			prev = node_temp;
			node_temp = node_temp->link[0];
		}
	return node_temp;
}

/* �M��e��`�I--�M��NODE_TEMP���e��`�I�A�^�ǧ�쪺�e��`�I */
Node_type *find_prev(Node_type *node_temp)
{
	prev = node;
	if(node_temp != NULL)
		while(node_temp->link[MAX-1] != NULL)
		{
			prev = node_temp;
			node_temp = node_temp->link[MAX-1];
		}
	return node_temp;
}

/* �����`�I�s��--�ϥΫe�ǻ��j�覡�����C�Ӹ`�I�s�� */
void preorder_id(Node_type *tree)
{
	int i;
	if(tree != NULL)
	{
		tree->id = id_seq++;
		for(i = 0; i <= tree->n; i++)
			preorder_id(tree->link[i]);
	}
}

/* ��X���--�ϥΫe�����j�覡��X�`�I��� */
void preorder_num(Node_type *tree)
{
	int i;
	char link_id;
	if(tree != NULL)
	{
		/* ��`�I��`��NULL�A�h����쵲��0 */
		if(tree->link[0] == NULL) link_id = '0';
		else link_id = tree->link[0]->id;
		printf("  %c, %d, %c", tree->id, tree->n, link_id);
		for(i = 1; i <= tree->n; i++)
		{
			if(tree->link[i] == NULL) link_id = '0';
			else link_id = tree->link[i]->id;
			printf(", (%d, %c)", tree->key[i], link_id);
		}
		printf("\n");
		for(i = 0; i <= tree->n; i++)
			preorder_num(tree->link[i]);
	}
}

/* �x�s��Ʀ��ɮ�--�ϥΫe�ǻ��j�x�s��� */
void preorder_save(Node_type *tree)
{
	int i;
	if(tree != NULL)
	{
		for(i = 1; i <= tree->n; i++)
			fprintf(fptro, "%d\n", tree->key[i]);
		for(i = 0; i <= tree->n; i++)
			preorder_save(tree->link[i]);
	}
}
