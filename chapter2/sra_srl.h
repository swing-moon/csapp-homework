int sra(int x,int k);
unsigned srl(unsigned x, int k);

int sra(int x,int k)
{
    //Perform shift logically
    int xsrl = (unsigned)x >> k; //转换成为无符号数
    int w = (sizeof(int))<<3;
    return xsrl |= (-1 << (w-k));
}

unsigned srl(unsigned x, int k)
{
    //Perform shift arithmetically
    unsigned xsra = (int) x >> k;
    int w = (sizeof(int)) << 3;
    return xsra &= ~(-1 << (w-k));
}