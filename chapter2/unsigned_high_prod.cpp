#include <stdio.h>
#include <inttypes.h>

int signed_high_prod(int x,int y)
{
    int64_t mul = (int64_t) x*y;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x,unsigned y)
{
    int sig_x = x >> 31;
    int sig_y = y >> 31;
    int signed_prod = signed_high_prod(x,y);
    return signed_prod + sig_x * y + sig_y * x;
}

unsigned compared_high_prod(unsigned x,unsigned y)
{
    uint64_t mul = (uint64_t) x*y;
    return mul >> 32;
}

int main()
{
    unsigned x = 0x12345678;
    unsigned y = 0xffffffff;

    int test = unsigned_high_prod(x,y);
    int compared = compared_high_prod(x,y);

    printf("Test: %8x\n",test);
    printf("compared: %8x\n",compared);
}
