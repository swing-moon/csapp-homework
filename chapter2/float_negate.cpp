#include <stdio.h>
#include <iostream>
#include "float_negate.h"
#include <math.h>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <cstring>
#include <limits.h>
#include <climits>
using namespace std;

float_bits float_negate(float_bits f)
{
    unsigned sign = f >> 31;
    cout << sign << endl;

    unsigned exp = f >> 23 & 0xFF;
    cout << exp << endl;

    unsigned frac = f & 0x7FFFFF;
    cout << frac << endl;

    if(exp == 0xFF && frac != 0)  //NAN
        return f;

    return (~sign << 31) | (exp << 23) | (frac);
}

int main()
{
    unsigned testV;
    cin >> testV;
    
    unsigned res = float_negate(testV);
    cout << "test value is " << *(float*) (&res) << endl;

    cout << "The real value is " << -(*(float*)(&testV)) << endl;
    
}