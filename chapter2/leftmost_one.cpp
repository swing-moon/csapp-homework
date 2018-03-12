#include <stdio.h>

int leftmost_one(unsigned x)
{
    x |= (x>>1);
    x |= (x>>2);
    x |= (x>>4);
    x |= (x>>8);
    x |= (x>>16);

    x &= ~(x>>1);
    return x;
}

int main()
{
    int x;
    scanf("%x",&x);
    int res=leftmost_one(x);
    printf("%x\n",res);
}
