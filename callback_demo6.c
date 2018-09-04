#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef void(*CBTest)(void *p); 
typedef struct _cbDemo CBDemo;
struct _cbDemo
{
    CBTest cb;
    void *cbParam;
    int k;
};
typedef struct _Data Data;
struct _Data
{
    int i;
    int j;
};
void Test(void *p)
{
    ((Data*)p)->i++;
    ((Data*)p)->j++;
}
void Test2(void *p)
{
    ((CBDemo*)p)->k = 10;
}
void RegisterCallback(CBDemo *pDemo,CBTest Test,void *p)
{
    pDemo->cb = Test;
    pDemo->cbParam = p;
}

int main()
{
    CBDemo demo;
    Data data;
    data.i = 10;
    data.j = 11;
    demo.k = 1;

    RegisterCallback(&demo,Test,&data);
    printf("RegisterCallback Test: %d,%d\n\r",data.i,data.j);
    
    demo.cb(demo.cbParam);
    printf("demo.cb: %d,%d\n\r",data.i,data.j);
    
    RegisterCallback(&demo,Test2,&demo);
    printf("RegisterCallback Test2: %d\n",demo.k);
    
    demo.cb(demo.cbParam);
    printf("demo.cb: %d\n\r",demo.k);
	return 0;
}
