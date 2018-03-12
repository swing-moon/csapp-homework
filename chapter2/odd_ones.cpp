#include <stdio.h>
#include <iostream>

using namespace std;

//不用位运算的方法
int even_ones_without_bit(unsigned x)
{
    int result = 0;
    for(int i=0;i<(sizeof(int)<<3);i++)
    {
        int y = x>>i;
        y=y&1;
        if(y)
          result++;
    }
    if(result%2)
        return 1;
    else
        return 0;
}

int odd_ones(unsigned x)
{
    //用异或运算消除偶数
    x ^= (x>>16);
    x ^= (x>>8);
    x ^= (x>>4);
    x ^= (x>>2);
    x ^= (x>>1);
    return (x&1);
}
int main()
{
    int x;
    scanf("%x",&x);
    int res=odd_ones(x);
    printf("%d\n",res);
}
