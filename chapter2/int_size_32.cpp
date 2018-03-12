#include <stdio.h>

bool int_size_is_32()
{
    int set_msb = ~(1<<31);
    return (set_msb+1<0);
}

int main()
{
    bool res = int_size_is_32();
    printf("%d\n",res);
}
