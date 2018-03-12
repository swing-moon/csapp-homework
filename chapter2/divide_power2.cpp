
#include <stdio.h>
#include <assert.h>
#include <limits.h>

int divide_power2(int x, int k)
{
    int is_neg = x & INT_MIN;
    if(is_neg)
        x += (1<<k)-1;
    return x>>k;
}

int mul3div4(int x)
{
    int mul3 = x+(x<<1);
    return divide_power2(mul3,2);
}

int main()
{
    int x;
    scanf("%x",&x);
    printf("%8x\n",divide_power2(x,2));
    printf("%8x\n",x/4);

    int y;
    scanf("%x",&y);

    printf("mul3div4: %x\n",mul3div4(y));
    printf("check: %x\n",3*y/4);
    return 0;
}
