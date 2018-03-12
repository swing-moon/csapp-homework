#include <stdio.h>

unsigned rotate_left(unsigned x, int n)
{
    if(n==0)
        return x;
    else
    {
        unsigned low = x<<n;
        unsigned high = x>>(32-n);
        return low | high;
    }
}

int main()
{
    int x,n;
    scanf("%x%d",&x,&n);
    int res=rotate_left(x,n);
    printf("%x\n",res);
}
