/* 利用B-TREE來處理資料--載入、儲存、新增、刪除、修改、查詢、輸出 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define MAX 2    /* 每一節點內至多可放資料筆數 */
#define MIN 1    /* 每一節點內至少需放資料筆數 */

typedef struct student {    /* 資料結構 */
	int count;                /* 節點資料數 */
	int id[MAX+1];            /* ID號碼--鍵值 */
	char name[MAX+1][11];     /* 姓名 */
	int score[MAX+1];         /* 分數 */
	struct student *link[MAX+1];    /* 子鏈結 */
} Node_type;

Node_type *root;

void init_f(FILE *);  /* 初始化函數 */
void insert_f(void);  /* 新增函數 */
Node_type *access(int, char *, int, Node_type *);  /* 將新增資料加入B-tree中 */
int topdown(int, char *, int, Node_type *, int *, char *, int *,
			Node_type **);  /* 從根節點往下逐一尋找插入點，將資料新增的函數 */
/* 將資料置於某特定節點中 */
void putdata(int, char *, int, Node_type *, Node_type *, int);
void broken(int, char *, int, Node_type *, Node_type *, int, int *, char *,
			int *, Node_type **);  /* 將一節點劃分為二 */
void update_f(void);  /* 修改函數 */
void delete_f(void);  /* 刪除函數 */
Node_type *removing(int, Node_type *);  /* 將資料從B-tree中刪除 */
int deldata(int, Node_type *);  /* 刪除資料函數 */
void move(Node_type *, int);  /* 將節點中的資料逐一往左移 */
void replace(Node_type *, int);  /* 尋找替代節點 */
void restore(Node_type *, int);  /* 資料刪除後的調整工作 */
void getleft(Node_type *, int);  /* 向左兄弟節點借一筆資料 */
void getright(Node_type *, int);  /* 向右兄弟節點借一筆資料 */
void combine(Node_type *, int);  /* 節點合併 */
void list_f(void);  /* 輸出函數 */
void show(Node_type *);  /* 以遞迴方式依序將資料輸出 */
void query_f(void);  /* 查詢函數 */
void save(Node_type *, FILE *);  /* 儲存函數 */
void quit(void);  /* 結束函數 */
Node_type * search(int, Node_type *, int *);  /* 依鍵值搜尋某特定節點函數 */
int searchnode(int, Node_type *, int *);  /* 依鍵值搜尋節點中某特定資料函數 */

void main(void)
{
	int flag=0, times=1;  /* times是判斷是否為第一次進入需要載入輸入檔案 */
	FILE *infile, *outfile;
	char choice, filename[11], ans;
	system("cls");
	while(1)
	{
		if(times == 1)
		{
			do
			{
				/* 要求輸入載入檔案名稱 */
				printf("\n  Please enter input file name: ");
				scanf("%s", filename);
				if((infile = fopen(filename, "r")) == NULL)
				{
					puts("  File name not found!!");
					flag = 0;
				}
				else
					flag = 1;
			}  while(flag == 0);  /* flag為0時，表示輸入錯誤，會要求重新輸入 */
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


/* 讀入輸入檔資料至B-tree中，infile為輸入檔案名稱 */
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

/* 新增一筆資料，並調整為B-tree */
void insert_f(void)
{
	int position, insert_id, insert_score; /* position記錄資料在節點中新增的位置 */
	Node_type *node;
	char ans, insert_name[11];
	puts("\n  ---- INSERT ----");
	puts("  Please enter detail data");
	printf("  ID number: ");
	scanf("%d", &insert_id);
	/* 找尋新增資料是否已存在，若存在，則顯示錯誤 */
	node = search(insert_id, root, &position);
	if(node != NULL)
		puts(" ID number has existed!!");
	else
	{
		printf("  Name: ");  /* 要求輸入其他詳細資料 */
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

/* 將新增資料加入B-TREE，node指加入節點，傳回值為root所在 */
Node_type *access(int app_id, char *app_name, int app_score, Node_type *node)
{
	int x_id, x_score, pushup;  /* pushup判斷節點是否需劃分而往上新增一節點 */
	char x_name[11];
	Node_type *xr, *p;
	pushup = topdown(app_id, app_name, app_score, node, &x_id, x_name,
						&x_score, &xr);
	if(pushup)  /* 若pushup為1，則配置一個新節點，將資料放入 */
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


/* 從樹根往下尋找資料加入節點，將資料新增於B-tree中，參數p為目前所在節點，
   xr記錄資料所對應的子鏈結 */
int topdown(int new_id, char *new_name, int new_score, Node_type *p,
			int *x_id, char *x_name, int *x_score, Node_type **xr)
{
	int k;
	if(p == NULL)  /* p為NULL表示新增第一筆資料 */
	{
		*x_id = new_id;
		strcpy(x_name, new_name);
		*x_score = new_score;
		*xr = NULL;
		return 1;
	}
	else
	{
		if(searchnode(new_id, p, &k))  /* 找尋新增資料鍵值是否重覆，若重覆則顯示錯誤 */
		{
			puts("  Data error, ID number has existed!!");
			quit();
			return 0;
		}
		/* 繼續往下找尋新增節點 */
		if(topdown(new_id, new_name, new_score, p->link[k], x_id, x_name,
					x_score, xr))
		{
			if(p->count < MAX)  /* 若新增節點有足夠的空間存放資料，則將資料直接加入該節點 */
			{
			putdata(*x_id, x_name, *x_score, *xr, p, k);
			return 0;
			}
			else
			{
				/* 若無足夠空間，則須劃分節點 */
				broken(*x_id, x_name, *x_score, *xr, p, k, x_id, x_name, x_score, xr);
				return 1;
			}
		}
		else
			return 0;
	}
}

/* 將新增資料直接加入於節點中，xr為新增資料對應的子鏈結所在，p為資料加入的節點 */
void putdata(int x_id, char *x_name, int x_score, Node_type *xr,
				Node_type *p, int k)
{
	int i;
	/* 將節點中的資料逐一右移，以空出新增資料加入的位置 */
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

/* 將節點一分為二，yr為劃分後新增加的節點 */
void broken(int x_id, char *x_name, int x_score, Node_type *xr, Node_type *p,
			int k, int *y_id, char *y_name, int *y_score, Node_type **yr)
{
	int i;
	int median;  /* median記錄從何處劃分節點 */
	if(k <= MIN)
		median = MIN;
	else
		median = MIN + 1;
	*yr = (Node_type *) malloc(sizeof(Node_type));
	/* 將資料從劃分處開始搬移至新節點中 */
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

/* 修改資料函數 */
void update_f(void)
{
	int update_id, update_score, position;
	char ans, update_name[11];
	Node_type *node;
	puts("\n  ---- UPDATE ----");
	printf("  Please enter ID number: ");
	scanf("%d", &update_id);
	node = search(update_id, root, &position);  /* 找尋欲修改資料所在節點位置 */
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

/* 刪除資料函數 */
void delete_f(void)
{
	int del_id, position;  /* position記錄刪除資料在節點中的位置 */
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

/* 將資料從B-tree中刪除，若刪除後節點內資料筆數為0，則一併刪除該節點 */
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

/* 將資料從B-tree中移除，若刪除失敗則傳回0，否則傳回資料在節點中所在位置 */
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

/* 將節點中的資料從k的位置逐一左移 */
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

/* 尋找刪除非樹葉時的替代資料 */
void replace(Node_type *p, int k)
{
	Node_type *q;
	for(q = p->link[k]; q->link[0]; q = q->link[0]);
	p->id[k] = q->id[1];
	strcpy(p->name[k], q->name[1]);
	p->score[k] = q->score[1];
}

/* 資料刪除後，重新調整為B-tree */
void restore(Node_type *p, int k)
{
	if(k == 0)  /* 刪除資料為節點中的第一筆資料 */
	{
		if(p->link[1]->count > MIN)
			getright(p, 1);
		else
			combine(p, 1);
	}
	else
		if(k == p->count)  /* 刪除資料為節點中的最後一筆資料 */
		{
			if(p->link[k-1]->count > MIN)
				getleft(p, k);
			else
				combine(p, k);
		}
		else  /* 刪除資料為節點中其他位置的資料 */
			if(p->link[k-1]->count > MIN)
				getleft(p, k);
			else
				if(p->link[k+1]->count > MIN)
					getright(p, k+1);
				else
					combine(p, k);
}

/* 向左兄弟節點借資料時，做資料右移的動作 */
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

/* 向右兄弟節點借資料時，做左移的動作 */
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

/* 將三個節點中的資料合併至一個節點中 */
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

/* 資料輸出函數 */
void list_f(void)
{
	puts("\n  ---- LIST ----");
	puts("  *******************************");
	puts("      ID     NAME       SCORE");
	puts("   =============================");
	show(root);
	puts("  *******************************");
}

/* 以遞迴方式輸出節點資料，輸出資料採中序法，nd為欲輸出資料的節點 */
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

/* 查詢某一特定資料 */
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

/* 將B-tree中的資料儲存到檔案中 */
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

/* 結束本系統 */
void quit(void)
{
	printf("\n  Thanks for using, bye bye!!");
	exit(0);
}

/* 搜尋某一鍵值所在節點，target為搜尋鍵值，傳回值為target所在節點指標，若沒有找
   到則傳回NULL */
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

/* 搜尋某一鍵值在節點中的位置，target為搜尋鍵值，k記錄鍵值所在位置，傳回0表
   示搜尋失敗，傳回1表示搜尋成功 */

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
