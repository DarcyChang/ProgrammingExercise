/* P. 117, Do strchr function. */
/* Reference information.
 * https://blog.wu-boy.com/2010/08/cc-cstring-string-h-%E5%87%BD%E5%BC%8F%EF%BC%9Astrstr-strchr/
 * */

#include <stdio.h>
#include <string.h>


char *StringChr(char *x, char y)
{
//    printf("[DEBUG] %s, %c\n", x, y);
    for( ; *x != y; x++)
    {
//        printf("[DEBUG] %s\n", x);
        if(x == '\0')
            return NULL;
    }
//    printf("[DEBUG] %s\n", x);
//    return (char*)x;  // We don't need cast.
    return x;
}


int main()
{
    char str[] = "This is a sample string";
    char *pch01, *pch02;
    printf("Looking for the 's' character in \"%s\"...\n",str);
    pch01 = strchr(str,'s');
    while (pch01!=NULL)
    {
        printf ("pch01 = [%s]\n",pch01);
        printf ("found at %ld\n",pch01-str+1);
        pch01=strchr(pch01+1,'s');
    }

    pch02 = StringChr(str, 's');
    while (pch02!=NULL)
    {
        printf ("pch02 = [%s]\n",pch02);
        printf ("found at %ld\n",pch02-str+1);
        pch02=strchr(pch02+1,'s');
    }

    return 0;
}
