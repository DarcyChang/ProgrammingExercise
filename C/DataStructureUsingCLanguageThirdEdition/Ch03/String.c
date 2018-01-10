/* �{���d��: String.c */
/* ���: �r����� */ 
int strLen(char *str) {
    /* �ŧi�ܼ� */
    char *ptr = str;
    /* �p��r����� */
    while ( *ptr != '\0' ) ptr++;
    return ptr - str;
}
/* ���: �r��ƻs */ 
char *strCpy(char *dest, char *source) {
    /* �ŧi�ܼ� */
    char *ptr = dest;
    /* �ƻs�r�� */
    while ( (*ptr++=*source++) != '\0' );
    return dest;
}
/* ���: �r��s�� */ 
char *strCat(char *dest, char *source) {
    /* �ŧi�ܼ� */
    char *ptr = dest;
    /* ���r��dest���̫� */
    while ( *ptr++ != '\0' );    
    ptr--;
    /* �ƻs�r��source */
    while ( (*ptr++=*source++) != '\0' );
    return dest;
}
/* ���: �r���� */ 
int strCmp(char *source, char *target) {
    /* ����r��O�_�۵� */
    for ( ; *source == *target; source++, target++)
         if ( *source == '\0')
             return 0;  /* �r��۵� */ 
    /* ����r�� */
    if ((*source-*target) < 0 )
       return -1; /* source����p */ 
    else
       return 1;  /* source����j */  
}
/* ���: �l�r��j�M */
char *strPos(char *source, char *target) {
    /* �ŧi�ܼ� */
    char *s = source;
    char *t = target; 
    char *ptr;
    if ( *t == '\0' ) /* target�O�Ŧr�� */ 
           return NULL;
    /* �j�M�l�r��target */
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
