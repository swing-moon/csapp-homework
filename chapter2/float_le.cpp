#include <stdio.h>

unsigned f2u(float x)
{
    return *(unsigned*) &x;
}

int float_le(float x,float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return sx==sy ? (sx==0 ? ux<=uy : ux>=uy) : sx>sy;
}

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);

    int flag = float_le(x,y);
    printf("%d\n",flag);
}
