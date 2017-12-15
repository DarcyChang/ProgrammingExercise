#include <stdio.h>
#include <stdio.h>

typedef unsigned int u32;
typedef unsigned short u16;

#if 0
//simple: not check varible types

#define BSWAP_16(x) \
          ( (((x) & 0x00ff) << 8 ) | \
     (((x) & 0xff00) >> 8 ) \
     )

//complex:check varible types

#else 
#define BSWAP_16(x) \
     (u16) ( ((((u16)(x)) & 0x00ff) << 8 ) | \
                 ((((u16)(x)) & 0xff00) >> 8 ) \
          )


#endif
#define BSWAP_32(x) \
     (u32) ( (( ((u32)(x)) & 0xff000000 ) >> 24) | \
                    (( ((u32)(x)) & 0x00ff0000 ) >> 8 ) | \
     (( ((u32)(x)) & 0x0000ff00 ) << 8 ) | \
     (( ((u32)(x)) & 0x000000ff ) << 24) \
              )

u16 bswap16(u16 x)
{
    return (x & 0x00ff) << 8 |
     (x & 0xff00) >> 8 
    ;
}

u32 bswap32(u32 x)
{
    return     ( x & 0xff000000 ) >>24 | 
        ( x & 0x00ff0000 ) >>8 | 
        ( x & 0x0000ff00 ) <<8 | 
        ( x & 0x000000ff ) << 24 
    ; 
}
    

int main(void)
{
    //u16 var_short = 0x123490;

    //u32 var_int = 0x1234567890;

    //關鍵是要能對錯誤進行處理，給一個0x123490 照樣能得出 0x9034的值，而且， 占內存要小的

    printf("macro conversion:%#x\n",BSWAP_16(0x123490 ));//要能正確轉換

    printf("macro conversion:%#x\n", BSWAP_32(0x1234567890)); //要能正確轉換

    
    printf("-----------------\n");
    
    printf("function conversion:%#x\n",bswap16(0x123490)); 
    printf("function conversion:%#x\n", bswap32(0x1234567890));
    
    
    return 0;
}
