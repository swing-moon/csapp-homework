#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

typedef unsigned float_bits;

float_bits float_half(float_bits f);

/*
    本例中要求舍入到偶数
    0b00 --> 0b00 + addition(0) = 0b00
    0b01 --> 0b00 + addition(0) = 0b00
    0b10 --> 0b01 + addition(0) = 0b01
    0b11 --> /2=1.5=2 --> 0b01 + addition(1) = 0b10

    only 0b11 --> addition = 1
    if &0b11 == 0b11
        addition = 1
    else
        addition = 0

    addition = (frac & 0x3) == 0x3
*/

float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    unsigned remain = f & 0x7FFFFFFF;

    int is_NAN_or_infinity = (exp == 0xFF);
    if(is_NAN_or_infinity){
        return f;
    }

    int addition = (frac & 0x3) == 0x3;

    if(exp == 0)
    {
        //Denormalized
        frac >>= 1;
        frac += addition;
    }
    else if(exp == 1)
    {
        //Normalized to Denormalized
        remain >>= 1;
        remain += addition;
        exp = (remain >> 23) & 0xFF;
        frac = remain & 0x7FFFFF;
    }
    else
    {
        //include factor 2
        exp -= 1;
    }

    return sign << 31 | exp << 23 | frac;
}

float u2f(unsigned u)
{
    return *(float*) &u;
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
    float real = f_test / 2;

    cout << "real: " << real << endl;
    cout << "test: " << u2f(float_half(u_test)) << endl;
}
