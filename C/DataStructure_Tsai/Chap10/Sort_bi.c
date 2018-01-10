/* �G����Ƨ� */
#include <stdio.h>
#include <stdlib.h>

struct data {
	int num;
	struct data *lbaby, *rbaby;
} *root, *tree, *leaf;

void find(int, struct data *);
void output(struct data *);

void main()
{
	int data[10] = {75, 23, 98, 44, 57, 12, 29, 64, 38, 82};
	int i;
	printf("\n<< Binary tree sort >>\n");
	printf("\nNumber : ");
	for(i = 0; i < 10; i++)
		printf("%d  ", data[i]);
	puts("");
	for(i = 0; i < 60; i++) printf("-");
	root = (struct data *) malloc(sizeof(struct data));
	root->num = data[0];     /* �ؾ�� */
	root->lbaby = NULL;
	root->rbaby = NULL;
	printf("\nAccess : ");
	output(root);
	leaf = (struct data *) malloc(sizeof(struct data));
	for(i = 1; i < 10; i++)  /* �ؾ�K */
	{
		leaf->num = data[i];
		leaf->lbaby = NULL;
		leaf->rbaby = NULL;
		find(leaf->num, root);
		if(leaf->num > tree->num)  /* �Y����`�I�j�A�h��k�l�� */
			tree->rbaby = leaf;
		else                       /* �_�h��b���l�� */
			tree->lbaby = leaf;
		printf("\nAccess : ");
		output(root);
		leaf = (struct data *) malloc(sizeof(struct data));
	}
	puts("");
	for(i = 0; i < 60; i++) printf("-");
	printf("\nSorting: ");
	output(root);
}

/* �M��s�`�I�s�񪺦�m */
void find(int input, struct data *papa)
{
	if((input > papa->num) && (papa->rbaby != NULL))
		find(input, papa->rbaby);
	else if((input < papa->num) && (papa->lbaby != NULL))
		find(input, papa->lbaby);
	else
		tree = papa;
}

/* �L�X��� */
void output(struct data *node)   /* �Τ��ǰl�ܱN��ƦL�X */
{
	if(node != NULL)
	{
		output(node->lbaby);
		printf("%d  ", node->num);
		output(node->rbaby);
	}
}
