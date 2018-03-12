#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

typedef unsigned float_bits;

float_bits float_i2f(int i);

unsigned mask(unsigned bits)
{
    return (1 << bits) - 1;
}
unsigned leftmost(unsigned bits)
{
    return 1 << bits;
}

float_bits float_i2f(int i)
{
    unsigned val = i;
    unsigned sign = i < 0 ? 1 : 0;

    if(sign)
        val = ~val + 1;
    
    unsigned expe = 0;
    unsigned frac = 0;
    unsigned temp = val;


    if(val >> 16)
    {
        expe += 0x10; //除以16，再加回来
        val = val >> 0x10;
    }
    if(val >> 8)
    {
        expe += 0x8;
        val = val >> 0x8;
    }
    if(val >> 4)
    {
        expe += 0x4;
        val = val >> 0x4;
    }
    if(val >> 2)
    {
        expe += 0x2;
        val = val >> 0x2;
    }
    if(val >> 1)
    {
        expe += 0x1;
        val = val >> 0x1;
    }
    //此时expe表示小数点从右边开始，往左多少位

    //去掉小数点最高位1
    val = temp;
    val = (~(1 << expe)) & val;
    //此时val为小数点后面的部分

    if(temp >> 23)
    {
        unsigned offset = expe - 23;
        //溢出部分
        frac = val >> offset;
        unsigned roundv = 0;
        unsigned round_bits = val & mask(offset);
        int cond1 = ( (val & mask(offset)) > leftmost(offset-1));
        int cond2 = ( (frac & 0x1) && (round_bits == leftmost(offset-1)) );

        if( (expe != 23) && (cond1 || cond2) )
        {
            frac += 1;
        }
        //向偶数舍入溢出了怎么办？
        //小数点从右边开始，往左边多移动1位
        if(frac >> 23)
        {
            expe += 1;
            frac = frac & 0x7fffff;
        }
    }
    else
        frac = val << (23 - expe);

    if(temp)
        expe += 127;

    return sign << 31 | expe << 23 | frac;
}

float u2f(unsigned u)
{
    return *(float*)&u;
}

int main()
{
    int i_test;
    cout << "input int: ";
    scanf("%d",&i_test);

    float real = (float) i_test;

    printf("real: %f\n",real);
    printf("test: %f\n",u2f(float_i2f(i_test)));
}