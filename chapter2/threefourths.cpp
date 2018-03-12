#include <stdio.h>
#include <limits.h>

int threefourths(int x)
{
    int is_neg = x & INT_MIN;
    int low = x & 0x3;
    int high = x & ~0x3;

    int highd4 = high >> 2;
    int highd4m3 = highd4 + (highd4 << 1);

    int lowm3 = low + (low << 1);
    int bias = (1<<2) - 1;
    if(is_neg)
        lowm3 += bias;
    int lowm3d4 = lowm3 >> 2;

    return lowm3d4 + highd4m3;
}

int main()
{
    int x;
    scanf("%d",&x);

    printf("Test: %d\n",threefourths(x));
    printf("Real: %d\n",x*3/4);
}
