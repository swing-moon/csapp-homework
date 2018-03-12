#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

int A(int x)
{
    return x + (x << 4);
}

int B(int x)
{
    return x - (x << 3);
}

int C(int x)
{
    return (x << 6) - (x << 2);
}

int D(int x)
{
    return (x << 4) - (x << 7);
}

int main()
{
    int x = 0x1;
    printf("Case A: %d\n",A(x));
    printf("Case B: %d\n",B(x));
    printf("Case C: %d\n",C(x));
    printf("Case D: %d\n",D(x));
}
