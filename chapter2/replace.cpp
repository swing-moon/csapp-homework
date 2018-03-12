#include <stdio.h>

//注意：不要打0x作为输入

int main()
{
    int x,y;
    int res;
    printf("Please int x(H) and y(H): ");
    scanf("%x%x",&x,&y);
    res = ((x & 0x000000ff) | (y & 0xffffff00));
    printf("The result is %.8x(H)\n",res);
}
