#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <assert.h>
#include <ctime>

using namespace std;

/*int create_random()
{
    srand((unsigned)time(NULL));
    return rand();
}*/

int A(int x,double dx)
{
    return (float) x == (float) dx;
}

int B(int x,int y,double dx,double dy)
{
    return (dx-dy) == (double) (x-y);
}

int C(double dx,double dy,double dz)
{
    return (dx+dy)+dz == dx+(dy+dz);
}

int D(double dx,double dy,double dz)
{
    return (dx*dy)*dz == dx*(dy*dz);
}

int E(double dx,double dz)
{
    return dx/dx == dz/dz;
}

int main()
{
    srand( (unsigned)time(NULL) );
    int x = rand();
    int y = rand();
    int z = rand();
    printf("x: %d\n",x);
    printf("y: %d\n",y);
    printf("z: %d\n",z);

    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;

    printf("check:\n");
    cout<<"A: "<<A(x,dx)<<endl;
    cout<<"Another A: "<<A(0x20001,(double)0x20001)<<endl;
    cout<<"B: "<<B(0,INT_MIN,(double)0,(double)INT_MIN)<<endl;
    dx = (double)0x2001;
    dy = (double)INT_MIN;
    dz = (double)100;
    cout<<"C: "<<C(dx,dy,dz)<<endl;

    cout<<"rand c:"<<endl;
    dx = (double)rand();
    dy = (double)rand();
    dz = (double)rand();
    cout<<C(dx,dy,dz)<<endl;

    dx = (double)rand();
    dy = (double)0xFFFFFFFF;
    dz = (double)INT_MIN;
    cout<<"D: "<<D(dx,dy,dz)<<endl;

    dx = (double)rand();
    cout<<"E: "<<E(dx,(double)0)<<endl;
}
