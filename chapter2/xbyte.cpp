#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    int move_to_high = (3-bytenum)<<3;
    //将要处理的字节移动到首字节
    unsigned mask = (0xff) << 24;
    //第一个字节设置掩码

    int res = (word << move_to_high) & mask;
    res = res >> 24;
    return res;

}

int main()
{
    int hex,n;
    scanf("%x%d",&hex,&n);
    printf("%x\n",xbyte(hex,n));
    return 0;
}
