/*
 * float-f2i.h
 */

#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

typedef unsigned float_bits;

int float_f2i(float_bits f);

int float_f2i(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned bias = 0x7F;

    /*
        consider positive numbers

        0 00000000 00000000000000000000000
        ===>
        0 01111111 00000000000000000000000
        1.0*(2^0),now E=exp-bias=0,means exp=7
        exp=1111111
        now 0<=f<=1
        we get integer 0


        0 01111111 00000000000000000000000
        now E=exp-bias=0 2^E=1
        ===>
        NaN的取值为多少？我们注意到浮点数可以表示32位整数，最高位是符号位
        所以能表示的最大的值是2^{31}-1
        上面这个数用浮点数表示是：
        0 (01111111+31) 00000000000000000000
    */
    unsigned M;
    unsigned E;
    int val;

    if(exp >=0 && exp < 0 + bias)
    {
        val = 0;
    }
    else if(exp >= 31 + bias)
    {
        //overflow
        val = 0x80000000;
    }
    else
    {
        E = exp - bias;
        M = frac | 0x800000;
        if(E > 23)
            val = M << (E - 23);
        else
            val = M >> (23 - E);
    }

    return sign ? -val : val;
}

int u2i(unsigned u)
{
    return *(int*) &u;
}

unsigned i2u(int u)
{
    return *(unsigned*) &u;
}

unsigned f2u(float u)
{
    return *(unsigned*) &u;
}

int main()
{
    float f_test;
    cout << "input float : ";
    cin >> f_test;

    unsigned u_test = f2u(f_test);
    int real = (int)f_test;
    //注意，float转换为int，要舍入，直接(int) float_v
    //而不是*(int*) float_v

    cout << "real : " << real << endl;
    cout << "test : " << float_f2i(u_test) << endl;
}