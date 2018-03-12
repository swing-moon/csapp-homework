#include <stdio.h>
#include <iostream>

using namespace std;

//判断x-y溢出，返回1
int tsub_ok(int x,int y)
{
    return ( (y>0 && x-y>x) || (y<0 && x-y<x) );
}

void show_tsub_ovf(int x, int y)
{
    printf("%d-%d=%d %s\n",x,y,x-y,tsub_ok(x,y)?"overflow":"not_overflow");
}

int main()
{
    int x,y;
    scanf("%x%x",&x,&y);
    show_tsub_ovf(x,y);

}
