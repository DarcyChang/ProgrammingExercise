/* 字串搜尋－暴力法 */
#include <stdio.h>
#include <string.h>
#define MAX 50

int strfind(char *, char *); /* 字串搜尋函數 */

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

/* 字串搜尋函數，搜尋pattern是否在string中
   傳回值會傳回pattern在string中第幾個元素被搜尋到
   傳回值為-1，表示pattern not found in string */
int strfind(char *string, char *pattern)
{
	int pos_s, pos_p, len_s, len_p, i;
	len_s = strlen(string);
	len_p = strlen(pattern);
	/* 字串從string的第一個元素依序比較至元素(len_s-len_p) */
	for(pos_s = 0; pos_s <= len_s - len_p; pos_s++)
	{
		for(i = 0; i < pos_s; i++) /* 輸出搜尋過程 */
			printf(" ");
		puts(pattern);
		for(pos_p = 0; pos_p < len_p; pos_p++)
		{
			/* 字元比對不正確，則中斷這次的比較 */
			if(pattern[pos_p] != string[pos_s+pos_p])
				break;
			/* 若pos_p為pattern的最後一個字元，表示搜尋成功 */
			if(pos_p == len_p - 1)
				return pos_s;
		}
	}
	return -1; /* 搜尋失敗 */
}
