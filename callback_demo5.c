#include <stdio.h>

struct operation
{
	void (*callback)();
};

void trigger(struct operation *ops, int ops_len)
{
	int i = 0;;
	while(i++ < ops_len)
	{
		ops->callback();
		ops++;
	}
}

void a_callback(void){	printf("I'm A\n");}
void b_callback(void){	printf("I'm B\n");}

int main(void)
{
	struct operation A,B;
	A.callback = a_callback;
	B.callback = &b_callback;
	struct operation ops[2];
	ops[0] = A;
	ops[1] = B;
	trigger(ops, 2);
	return 0;
}
