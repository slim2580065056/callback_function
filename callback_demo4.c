#include "stdio.h"
//定义回调函数-别名,方便后续使用------需提供给模块B
typedef void (*TestCB)(char testData);
//模块A内部的全局回调变量,用于模块A内部绑定注册回调用
TestCB CbHandle;
/*****************************************************
模块A对外函数---------需提供给模块B
模块A内部定义的全局callback变量与外部模块注册的回调函数绑定起来,
用于后续模块A,满足触发条件后,触发回调
******************************************************/
void A_SetTestCb(TestCB pTestCb)
{
	CbHandle = pTestCb;
}
/*****************************************************
模块A内部函数
通常为A模块因为某些条件符合了,触发了对应的事件从而调用对应的callback函数
******************************************************/
void A_CallTestCb()
{
	char testData = 100;
	//触发调用回调实现函数
	CbHandle(testData);
}
/*****************************************************
模块B内部函数
模块B实现的回调函数-具体操作
******************************************************/
void B_UserTestCbDetail(char testData)
{
	printf("step 3\n");
	printf("[do] call-back\n");
	//具体实现
	printf("UserTestCbDetail, call back is achieve! testData = %d\n", testData);
}
void main()
{
	printf("step 1\n");
	printf("[register] call-back\n");
	A_SetTestCb(B_UserTestCbDetail);
	printf("step 2\n");
	printf("[call] call-back\n");
	A_CallTestCb();
}
