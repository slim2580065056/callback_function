#include<stdio.h>
//#include <pthread.h>
#include <stdlib.h>
 
typedef void (* def_func)(int n); 
 
typedef struct param_s{
    int a;
    def_func call_back;
} param_t;
 
// 线程回调函数
void *thread_func(void *param)
{
    param_t *p = (param_t *)param;
    
    int b = 100;    // 需要在此处得到的资源
    printf("thread_func..\n");
    
    // 此处 底层在耗时操作，得到相关资源， 然后才能调用用户提供的程序
    sleep(5);
    // 执行回调函数
    p->call_back(p->a);
 
    p->call_back(b);                 // 让用户调用我们本地的资源
    printf("a = %d\n", p->a);           // 我们调用用户的资源
}
 
// 注册函数   -- .dll
void Register_func(def_func func, int n)
{
    pthread_t thrd;
    param_t *param = (param_t *)malloc(sizeof(param_t));
 
    param->a = n;
    param->call_back = func;
 
    pthread_create(&thrd, NULL, thread_func, (void *)param);   
    
    pthread_detach(thrd);
    // pthread_join(thrd, NULL);      // 会阻塞在这里
 
}
 
// 回调函数  --用户去写        
// 尽管用户写了该函数，
// 却不是自己去调用，而是通过指针由底层的 注册函数去调用 称为回调函数
void func(int b){ 
    printf("This is func.\t  b = %d\n", b); 
}
 
 
int main(int argc, const char *argv[])
{
    
    int c = 10; 
 
    def_func real = func;
 
    // 把用户写的函数注册上去
    Register_func(real, c);
 
    // 注册之后， 自己想干嘛干嘛， 5s时间到后，自然会操作func 函数， 即实现异步操作
    printf("This is client func after Register_func\n");
 
    pause();   // 查看异步操作
    return 0;
}
