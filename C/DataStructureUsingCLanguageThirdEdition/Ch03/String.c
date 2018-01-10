/* 程式範例: String.c */
/* 函數: 字串長度 */ 
int strLen(char *str) {
    /* 宣告變數 */
    char *ptr = str;
    /* 計算字串長度 */
    while ( *ptr != '\0' ) ptr++;
    return ptr - str;
}
/* 函數: 字串複製 */ 
char *strCpy(char *dest, char *source) {
    /* 宣告變數 */
    char *ptr = dest;
    /* 複製字串 */
    while ( (*ptr++=*source++) != '\0' );
    return dest;
}
/* 函數: 字串連接 */ 
char *strCat(char *dest, char *source) {
    /* 宣告變數 */
    char *ptr = dest;
    /* 找到字串dest的最後 */
    while ( *ptr++ != '\0' );    
    ptr--;
    /* 複製字串source */
    while ( (*ptr++=*source++) != '\0' );
    return dest;
}
/* 函數: 字串比較 */ 
int strCmp(char *source, char *target) {
    /* 比較字串是否相等 */
    for ( ; *source == *target; source++, target++)
         if ( *source == '\0')
             return 0;  /* 字串相等 */ 
    /* 比較字元 */
    if ((*source-*target) < 0 )
       return -1; /* source比較小 */ 
    else
       return 1;  /* source比較大 */  
}
/* 函數: 子字串搜尋 */
char *strPos(char *source, char *target) {
    /* 宣告變數 */
    char *s = source;
    char *t = target; 
    char *ptr;
    if ( *t == '\0' ) /* target是空字串 */ 
           return NULL;
    /* 搜尋子字串target */
    while ( *s != '\0' ) {
        ptr = s;
        t = target;
        while ( *t != '\0' && *ptr == *t ) {
            ptr++;
            t++;
        }
        if ( *t == '\0' )
           return s;
        s++;
    }
    return NULL;  
}
