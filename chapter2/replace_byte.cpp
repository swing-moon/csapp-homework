#include <stdio.h>
#include <iostream>

using namespace std;

unsigned replace_byte(unsigned x, unsigned char b, int i)
{
    return (x & ~(0xff<<(i<<3))) | (b<<(i<<3));
}

int main()
{
    printf("0x%x\n",replace_byte(0x12345678,0xab,2));
    printf("0x%x\n",replace_byte(0x12345678,0xab,0));
}
