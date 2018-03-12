#include <stdio.h>
#include <iostream>

int A(int k)
{
    return -1 << k;
    //表示-1重复k次
}

int B(int k,int j)
{
    return (~A(k)) << j;
}

int main()
{
    int x;
    scanf("%d",&x);
    printf("%8x\n",A(x));
    printf("0xFFFFFF00\n");

    printf("%8x\n",B(16,8));
    printf("0x00FFFF00\n");
}
