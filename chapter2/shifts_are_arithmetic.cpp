#include <stdio.h>
#include <iostream>
using namespace std;

//int_shifts_are_arithmetic()
//对int类型数使用算术右移返回1，否则返回0；
//显然，只需考虑负数即可（非负数算术右移与逻辑右移相同）。
//显这里以-这里以-这里以-这里以-1为例，
//-1算术右移一位，所产生的二进制码代表的数值不变；
//-而逻辑右移则会使最高位为0，变成（1<<31）-1，最大值。

int int_shifts_are_arithmetic()
{
    printf("%x %x\n", ((-1)>>1),-1);
    return ((-1)>>1)==-1;
}

int main()
{
    cout<<int_shifts_are_arithmetic()<<endl;
    return 0;
}
