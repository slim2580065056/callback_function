#include <stdio.h>

#define MAXSIZE 4
enum OPT{ADD, RED, MUL, DIV}; //加，减，乘，除
typedef int (*OptFun)(int, int);

int add(int a, int b){return a + b;}
int reduce(int a, int b){return a - b;} 
int multiply(int a, int b){return a * b;}
int divide(int a, int b){
	if(b != 0) return a / b;
	else exit(-1);
}

static OptFun cb_fun_list[MAXSIZE] = {add, reduce, multiply, divide};

typedef struct
{
	int index;
	int (*call_fun)(int, int);
}CALL_BACK_INFO;


int regCBFun(CALL_BACK_INFO *cb_info)
{
	if(cb_info)
	{
		switch(cb_info->index)
		{
			case ADD:
				cb_info->call_fun = cb_fun_list[ADD];
			break;
			case RED:
				cb_info->call_fun = cb_fun_list[RED];
			break;
			case MUL:
				cb_info->call_fun = cb_fun_list[MUL];
			break;
			case DIV:
				cb_info->call_fun = cb_fun_list[DIV];
			break;
			default:
			break;
		}
		return cb_info->index;
	}
	return -1;
}

int main()
{
	CALL_BACK_INFO cbInfo;
	cbInfo.index = MUL;
	
	int cb_fun_id;
	int a = 10, b = 4;
	if((cb_fun_id = regCBFun(&cbInfo)) != -1)
	{
		printf("%d\n",cbInfo.call_fun(a, b));
	}
	return 0;
}
