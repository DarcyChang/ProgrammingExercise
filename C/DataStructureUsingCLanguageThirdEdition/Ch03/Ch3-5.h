/* 程式範例: Ch3-5.h */
char str[81];       /* 儲存字串的字元陣列 */
/* 抽象資料型態的操作函數宣告 */
extern int strLen(char *str);
extern char *strCpy(char *dest, char *source);
extern char *strCat(char *dest, char *source);
extern int strCmp(char *source, char *target);
extern char *strPos(char *source, char *target);
