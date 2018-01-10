/* �r��j�M�мɤO�k */
#include <stdio.h>
#include <string.h>
#define MAX 50

int strfind(char *, char *); /* �r��j�M��� */

void main()
{
	char string[MAX] = "abcaabcaabbabaabbabbababcabcaa";
	char pattern[MAX] = "aabbabb";
	int found;
	puts(string);
	if((found = strfind(string, pattern)) != -1)
		printf("String found: position %d\n", found);
	else
		printf("String not found!\n");
}

/* �r��j�M��ơA�j�Mpattern�O�_�bstring��
   �Ǧ^�ȷ|�Ǧ^pattern�bstring���ĴX�Ӥ����Q�j�M��
   �Ǧ^�Ȭ�-1�A���pattern not found in string */
int strfind(char *string, char *pattern)
{
	int pos_s, pos_p, len_s, len_p, i;
	len_s = strlen(string);
	len_p = strlen(pattern);
	/* �r��qstring���Ĥ@�Ӥ����̧Ǥ���ܤ���(len_s-len_p) */
	for(pos_s = 0; pos_s <= len_s - len_p; pos_s++)
	{
		for(i = 0; i < pos_s; i++) /* ��X�j�M�L�{ */
			printf(" ");
		puts(pattern);
		for(pos_p = 0; pos_p < len_p; pos_p++)
		{
			/* �r����藍���T�A�h���_�o������� */
			if(pattern[pos_p] != string[pos_s+pos_p])
				break;
			/* �Ypos_p��pattern���̫�@�Ӧr���A��ܷj�M���\ */
			if(pos_p == len_p - 1)
				return pos_s;
		}
	}
	return -1; /* �j�M���� */
}
