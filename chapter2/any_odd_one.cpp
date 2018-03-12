#include <stdio.h>
#include <iostream>


bool any_odd_one(unsigned x)
{
    //将所有的奇数位全部置为0，偶数位不变
    //考虑&1010
    //&0xaaaaaaaa(32bits)
    //若奇数位有1，则最后结果不为0，return 1
    //else return 0
    return 0!=(x&0x55555555);
}

int main()
{
    printf("%d\n",any_odd_one(0x5) );
    printf("%d\n",any_odd_one(0x25) );
    printf("%d\n",any_odd_one(0x7) );
    return 0;
}
