#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

/*
 * float-absval.h
 */

typedef unsigned float_bits;

float_bits float_absval(float_bits f);


float_bits float_absval(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_NAN = (exp == 0xFF) && (frac != 0);
    if(is_NAN)
        return f;
    
    return 0 << 31 | exp << 23 | frac;
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
    unsigned testV;
    float f_test;
    cin >> testV >> f_test;

    float testF = u2f(testV);

    unsigned u_test = f2u(f_test);
    

    if(isnan(testF))
    {
        cout << "test " << testF;
        cout << "real " << testV;
    }
    else
    {
        cout << "test1= " << u2f(float_absval(testV)) << endl;
        cout << "real1= " << fabs(testF) << endl;

        cout << "test2= " << u2f(float_absval(u_test)) << endl;
        cout << "real2= " << fabs(f_test) << endl;
    }
}