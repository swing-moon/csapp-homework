#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <iostream>

using namespace std;

float u2f(unsigned x)
//这里涉及到无符号数转换成浮点数
//使用引用
{
    return *(float*) &x;
    // &x是变量x的地址
    // (float*) &x 获取float型指针
    // *(float*) &x 对指针解引用，得到float型的值
}

float fpwr2(int x)
{
    unsigned expr,frac;
    unsigned u;

    if(x < 2-pow(2,7)-23)
    {
        expr = 0;
        frac = 0;
    }
    else if(x < 2-pow(2,7))
    {
        expr = 0;
        frac = 1 << (unsigned)(x - (2-pow(2,7)-23) );
    }
    else if(x < pow(2,7)-1+1)
    {
        expr = x + pow(2,7) - 1;
        frac = 0;
    }
    else
    {
        expr = 0xFF;
        frac = 0;
    }

    u = expr << 23 | frac;
    return u2f(u);
}

int main()
{
    cout<<"calculate: "<<powf(2,0)<<" test: "<<fpwr2(0)<<endl;
    cout<<"calculate: "<<powf(2,100)<<" test: "<<fpwr2(100)<<endl;
    cout<<"calculate: "<<powf(2,-100)<<" test: "<<fpwr2(-100)<<endl;
    cout<<"calculate: "<<powf(2,10000)<<" test: "<<fpwr2(10000)<<endl;
    cout<<"calculate: "<<powf(2,-10000)<<" test: "<<fpwr2(-10000)<<endl;
    return 0;
}