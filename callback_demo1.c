#include <stdio.h>

typedef void (*callback_t)(void *);
void repeat_three_times(callback_t f, void *para)
{
	f(para);
	f(para);
	f(para);
}

void say_hello(void *str){ printf("Hello %s\n", (const char *)str);}
void count_numbers(void *num)
{
     int i;
     for(i=1; i<=(int)num; i++)
	 	printf("%d ", i);
     putchar('\n');
}

int main(void)
{
     repeat_three_times(say_hello, "slim素");
     repeat_three_times(count_numbers, (void *)8);
     return 0;
}
