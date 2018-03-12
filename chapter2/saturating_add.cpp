#include <stdio.h>
#include <iostream>

using namespace std;

int saturating_add(int x, int y)
{
    int mask = INT_MIN;
    //INT_MIN所有位均为1，构成了掩码

    int sum = x+y;
    int w = sizeof(int)<<3;

    //负溢出的时候，获取最小值
    //负溢出的情况，原来x,y的第一位为1
    //即有(x & mask) (y & mask)
    //注意&&运算，() && ()，
    //注意&&运算，连接两个非0数，
    //结果也只为0或者1
    //(x & mask) && (y & mask) && !(sum & mask)
    //在负溢出的时候为1，1<<(w-1)>>(w-1)
    //会把所有的位置为1，因为有符号数要补上符号位
    //最后 & INT_MIN，保证INT_MIN正确输出

    int tmin = ( ((x&mask) && (y&mask) && !(sum&mask)) <<(w-1)>>(w-1) ) & INT_MIN;
    //这一步，关键是如果前半部分的值为1，说明溢出，溢出返回的是INT_MIN
    //不用if语句，我们要得到INT_MIN，需要INT_MIN & 11...1
    //前半部分的值为1，要让所有的位值都是1，需要<<(w-1)>>(w-1)
    //算术右移，前面是带上符号位的
    
    int tmax = ( ((~x&mask) && (~y&mask) && (sum&mask)) <<(w-1)>>(w-1) ) & INT_MAX;
    return (sum& ~(!(tmin | tmax))) | tmin | tmax;

    //这里重点说明一下没有溢出的情况：
    //[tmin,tmax) 其中tmin=11...1 tmax=011...1
    //tmin|tmax = 11...1，这样的目的是把符号位的1也参与进运算中
    //--> !(tmin | tmax)=00...0 --> ~(!(tmin|tmax))=11...1
    //sum & res = sum，符号位也原封不动地包含下来
}

void show_saturating_add(int x,int y)
{
    printf("satuarating_add(0x%08x,0x%08x)=0x%08x-->%d\n",x,y,saturating_add(x,y),saturating_add(x,y));
    printf("%d+%d=%d\n",x,y,x+y);
    printf("\n");
}
int main()
{
    int x,y;
    scanf("%x%x",&x,&y);
    show_saturating_add(x,y);
}
