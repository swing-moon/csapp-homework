#include <stdio.h>
#include <iostream>

using namespace std;

int judge_if_all_1(int x)
{
    return !(~x);
}

int judge_if_all_0(int x)
{
    return !x;
}

int judge_low_is_0(int x)
{
    //最低有效字节：x & 0xff
    return !(x & 0xff);
}

int judge_low_is_1(int x)
{
    return (x & 0xff);
}

int judge_high_is_0(int x)
{
    //除最高字节以外的位数
    //howmanybit=(sizeof(int)-1)<<3
    // a<<3表示a*8，因为一位有8个比特

    //右移howmanybit位
    return !( (x>>((sizeof(x)-1)<<3)) );
}

int main()
{
    int a;
    scanf("%x",&a);

    cout<<judge_low_is_0(a)<<endl;
    cout<<judge_low_is_1(a)<<endl;
    cout<<judge_high_is_0(a)<<endl;
    cout<<judge_if_all_0(a)<<endl;
    cout<<judge_if_all_1(a)<<endl;
}
