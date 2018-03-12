#include <stdio.h>

int lower_one_mask(int n)
{
    unsigned mark = 0xffffffff;
    mark = mark >> (32-n);
    return mark;
}

int main()
{
    int n;
    scanf("%d",&n);
    int res = lower_one_mask(n);
    printf("%x",res);
}
