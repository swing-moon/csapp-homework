#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void* my_calloc(size_t nmemb,size_t size)
{
    if(nmemb==0 || size==0)
        return NULL;
    size_t buf_size = nmemb * size;

    if(nmemb == buf_size/size)
    {
        void* ptr = malloc(buf_size);
        memset(ptr,0,buf_size);
        return ptr;
    }
    return NULL;
}

int main()
{
    void* p;
    p = my_calloc(0x1234,1);
    //一共有0x1234个元素，每个元素1字节
    bool flag = (p!=NULL);
    if(flag)
        printf("Case 1 :Not Null \n");
    else
        printf("Case 1 :Null\n");
    free(p);

    p = my_calloc(SIZE_MAX,2);
    flag = (p==NULL);
    if(flag)
        printf("Case 2 :NULL\n");
    else
        printf("Case 2 :Not Null\n");
}
