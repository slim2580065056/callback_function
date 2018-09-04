#include <stdio.h>

int add(int a, int b) { return a+b; } 
int sub(int a, int b) { return a-b; } 
int mul(int a, int b) { return a*b; } 
int div(int a, int b) { return a/b; }

struct operations{
    int (*ADD)(int a, int b); 
    int (*SUB)(int a, int b);  
    int (*MUL)(int a, int b);
    int (*DIV)(int a, int b);  
};

int main()
{
    int a=8,b=2,result;
    struct operations FUN;
    FUN.ADD = add;
    FUN.SUB = sub;
    FUN.MUL = mul;
    FUN.DIV = div;

    result = FUN.ADD(a,b);
    printf("result is %d\n\r",result);
    result = FUN.SUB(a,b);
    printf("result is %d\n\r",result);
    result = FUN.MUL(a,b);
    printf("result is %d\n\r",result);
    result = FUN.DIV(a,b);
    printf("result is %d\n\r",result);
	return 0;
}
