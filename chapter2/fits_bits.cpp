#include <stdio.h>

//一个数能够用二进制补码表示
//可以知道这个数为正数
int fits_bits(int x, int n)
{
    //对最高位进行缩进表示
    int bias = (sizeof(int) << 3)-n;
    return ((x<<bias)>>bias)==x;
}

int main()
{
    int x,n;
    scanf("%d%d",&x,&n);
    int res = fits_bits(x,n);
    printf("%d\n",res);
}
