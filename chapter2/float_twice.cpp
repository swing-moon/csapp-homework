/*
 * float-twice.h
 */

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

typedef unsigned float_bits;

float_bits float_twice(float_bits f);

float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_NAN_or_infinity = (exp == 0xFF);

    if(is_NAN_or_infinity)
    {
        return f;
    }
    
    if(exp == 0)
    {
        frac <<= 1;
    }
    else if(exp == 0xFF-1)
    // 乘以2趋于无穷大
    {
        exp = 0xFF;
        frac = 0;
    }
    else
    {
        exp += 1;
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
    cout<< "input float :";
    cin >> f_test;

    unsigned u_test = f2u(f_test);
    float real = f_test * 2;

    cout << "real " << real << endl;
    cout << "test " << u2f(float_twice(u_test)) << endl;
}