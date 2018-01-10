/* 字串搜尋－KMP法 */
#include <stdio.h>
#include <string.h>
#define MAX 50

int fastfind(char *, char *);  /* KMP字串搜尋函數 */
void fail(char *, int *);  /* 計算pattern的fail值 */

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

/* KMP字串搜尋函數，引數string為被搜尋字串，pattern為搜尋字串
   傳回值會傳回pattern於string中的第幾個元素被找到
   傳回值為-1，表示pattern not found in string */
int fastfind(char *string, char *pattern)
{
	int pos_p = 0, pos_s = 0, i, done = 0;
	/* len_p、len_s分別為pattern與string的長度 */
	int len_p = strlen(pattern), len_s = strlen(string);
	int pat_fail[MAX];  /* 存放pattern的failure值 */
	fail(pattern, pat_fail);  /* 計算pattern的failure值 */
	/* 當pattern尚未找到，且string尚未比較完畢，則繼續比較 */
	while((pos_p < len_p) && (len_s - pos_s) >= len_p - 1)
	{
		if(done == 0) /* 輸出比較過程 */
		{
			for(i = 0; i < pos_s - pos_p; i++)
				printf(" ");
			puts(pattern);
		}
		/* pattern中的字元與string相等的情況 */
		if(pattern[pos_p] == string[pos_s])
		{
			pos_p++;
			pos_s++;
			done = 1;
		}
		/* pattern中的字元與string不相等的情況 */
		else
		{
			if(pos_p == 0)
				pos_s++;
			else
				pos_p = pat_fail[pos_p-1] + 1;
			done = 0;
		}
	}
	if(pos_p < len_p) /* 搜尋不成功 */
		return -1;
	else  /* 搜尋成功 */
		return pos_s - len_p;
}

/* 計算pattern的failure值，引數pat_fail存放計算結果 */
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
