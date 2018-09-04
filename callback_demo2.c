#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define HELP_LEN 64  // 函数说明的最大长度 
#define TABLE_LEN 10 // 函数表中的最大的函数个数

typedef void(*PFUNCMD)();   //声明回调函数类型
typedef struct CmdEntry
{
    PFUNCMD pfuncmd;    // 定义函数指针，用于接收函数的入口地址
    char cHelp[HELP_LEN];
}CmdEntry;

void CreateFile() { printf("CreateFile\n"); }   //回调函数CreateFile
void OpenFile() { printf("OpenFile\n"); }       //回调函数OpenFile
void SaveFile() { printf("SaveFile\n"); }       //回调函数SaveFile
void myfile() {	printf("My File\n");}
void AddFile() { printf("AddFile\n\r");}        //回调函数AddFile，待向函数表中新增的回调函数

 // 定义结构体数组（函数表）并初始化  
static CmdEntry cmdArray[TABLE_LEN] =
{
    {CreateFile,"CreateFile HELP"},       // 取CreatFile()函数地址，帮助信息
    {OpenFile,"OpenFile HELP"},            // 取OpenFile()函数地址，帮助信息
    {&SaveFile,"SaveFile HELP"},            // 取SaveFile()函数地址，帮助信息
    {myfile, "slim_File"},
     // <标注1>在这里添加函数                    
    {0,0}                                   // 退出
};
//显示函数表中的内容
void ShowHelp()
{
    int i;
    for(i=0;(i<TABLE_LEN)&&cmdArray[i].pfuncmd;i++)
    {
        printf("%d\t%s\n\r",i,cmdArray[i].cHelp);
    }
}
//执行功能的命令函数
void CmdRunning()
{
    int iCmdNum;
    while(1)
    {
        ShowHelp();     //“帮助信息”显示初始化
        printf("Please select!\n\r");
        //iCmdNum = 1;2
        scanf("%d",&iCmdNum);
        if(iCmdNum>=0 && iCmdNum<TABLE_LEN && cmdArray[iCmdNum].pfuncmd)
        {
            cmdArray[iCmdNum].pfuncmd();
        }
        else
        {
            printf("Your selection doesn't exist!\n\r");
        }
    }
}
/*
 *如果采用上述方式注册函数，则必须在这个文件的函数表中
 *修改源代码，但是在很多时候，需要扩展菜单功能时不允
 *许随意修改源码，那么唯一的解决方法就是为系统增加一
 *个可动态扩展的接口函数。
*/
void AddCmd(CmdEntry cmdentry)
{
    int i;
    for(i=0;(i<TABLE_LEN) && cmdArray[i].pfuncmd;i++)
    { printf("hello world\n"); }
     // 找到空的功能条目位置
    if(TABLE_LEN == i) {printf("Sorry,Table if full!\n\r");}
    else {cmdArray[i] = cmdentry;}
}

int main()
{
    CmdEntry CmdAdd = 
    {
        AddFile,
        "AddFile Help"
    };
    AddCmd(CmdAdd);

    CmdRunning();
	while(1)
	{
	}
}
