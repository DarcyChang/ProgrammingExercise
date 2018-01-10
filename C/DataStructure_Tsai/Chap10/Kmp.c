/* �r��j�M��KMP�k */
#include <stdio.h>
#include <string.h>
#define MAX 50

int fastfind(char *, char *);  /* KMP�r��j�M��� */
void fail(char *, int *);  /* �p��pattern��fail�� */

void main()
{
	char string[MAX] = "aabaabcaabaabaabaabbababcabcaa";
	char pattern[MAX] = "aabaabb";
	int found;
	puts(string);
	if((found = fastfind(string, pattern)) != -1)
		printf("String found: position %d\n", found);
	else
		printf("String not found!\n");
}

/* KMP�r��j�M��ơA�޼�string���Q�j�M�r��Apattern���j�M�r��
   �Ǧ^�ȷ|�Ǧ^pattern��string�����ĴX�Ӥ����Q���
   �Ǧ^�Ȭ�-1�A���pattern not found in string */
int fastfind(char *string, char *pattern)
{
	int pos_p = 0, pos_s = 0, i, done = 0;
	/* len_p�Blen_s���O��pattern�Pstring������ */
	int len_p = strlen(pattern), len_s = strlen(string);
	int pat_fail[MAX];  /* �s��pattern��failure�� */
	fail(pattern, pat_fail);  /* �p��pattern��failure�� */
	/* ��pattern�|�����A�Bstring�|����������A�h�~���� */
	while((pos_p < len_p) && (len_s - pos_s) >= len_p - 1)
	{
		if(done == 0) /* ��X����L�{ */
		{
			for(i = 0; i < pos_s - pos_p; i++)
				printf(" ");
			puts(pattern);
		}
		/* pattern�����r���Pstring�۵������p */
		if(pattern[pos_p] == string[pos_s])
		{
			pos_p++;
			pos_s++;
			done = 1;
		}
		/* pattern�����r���Pstring���۵������p */
		else
		{
			if(pos_p == 0)
				pos_s++;
			else
				pos_p = pat_fail[pos_p-1] + 1;
			done = 0;
		}
	}
	if(pos_p < len_p) /* �j�M�����\ */
		return -1;
	else  /* �j�M���\ */
		return pos_s - len_p;
}

/* �p��pattern��failure�ȡA�޼�pat_fail�s��p�⵲�G */
void fail(char *pattern, int *pat_fail)
{
	int i, j, len_p = strlen(pattern);
	pat_fail[0] = -1;
	for(j = 1; j < len_p; j++)
	{
		i = pat_fail[j-1];
		while((*(pattern + j) != *(pattern+i+1)) && (i >= 0))
			i = pat_fail[i];
		if(*(pattern + j) == *(pattern + i + 1))
			pat_fail[j] = i + 1;
		else
			pat_fail[j] = -1;
	}
}
