#include <stdio.h>

//首先使用typedef声明执行函数的指针类型，返回值类型、参数类型。
//typedef int (*POINTER)()  即：返回值（指针名）（参数列表）
typedef int (*CallBackFun)(char *p);

//编写回调函数（方法）原型，格式应符合上面声明的CallBackFun    
//格式：int Afun(char *p)  即：返回值 函数名（参数列表）
int Afun(char *p)
{
    printf("Afun %s!\n\r",p);
    return 0;
}

int Bfun(char *p)
{
    printf("Bfun %s!\n\r",p);
    return 0;
}
//格式一：int call(CallBackFun pCallBack, char *p)    通过命名方式
int call1(CallBackFun pCallBack,char *p)
{
    printf("pfunc print %s! \n\r",p);
    pCallBack(p);
    return 0;
}
//格式二：int call2(char *p, int (*ptr)())   通过回调函数指针 
int call2(int(*ptr)(),char *p)
{
    printf("cbfunc print %s! \n\r",p);
    (*ptr)(p);
    return 0;
}

int main()
{
    char *p = "hello";
  
    printf("**\n\n\r");
    call1(Afun, p);
    call1(Bfun, p);
    printf("\n\r");

    call2(Afun, p);  
    call2(Bfun, p);
    printf("\n\r");

	return 0;
}
