#include <stdio.h>
 
struct argv
{
    char a[64];
    int b;
};
 
int func(struct argv a)
{
     printf("argv.a=%s argv.b=%d\n",a.a,a.b);
} 
 
int main(int argc,char *argv[])
{
    struct argv a = {
      .a = "hello world",
      .b = 24
    };
 
    func(a);
 
    func((struct argv){"hello ZiMianLiang",24});
    
    return 0;
}
