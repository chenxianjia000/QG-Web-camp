#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqStack.h"


int s_get_int();
void select(SqStack *s);
void menu();

int main()
{
    int size = 0;
    SqStack *s ;
    s = (SqStack*)malloc(sizeof(SqStack));

    while(size <=0 ||size >999)
    {
        puts("请输入将创建栈的大小(1~999):");
        size = checkinput();
    }
    initStack(s,size);
    system("cls");
    menu();
    puts("请输入操作选项");
    select(s);
    return 0;
}
//菜单
void menu()
{
    puts("\t\t\t**顺序栈测试**");
    puts("\t\t\t1.判断栈是否为空");
    puts("\t\t\t2.输出栈顶元素");
    puts("\t\t\t3.清空栈内元素");
    puts("\t\t\t4.测试栈的实际长度");
    puts("\t\t\t5.入栈操作");
    puts("\t\t\t6.出栈操作");
    puts("\t\t\t7.销毁栈并退出系统");
}
//选择函数
void select(SqStack *s)
{
    ElemType e;

    switch(checkinput())
    {
        case 1:if (isEmptyStack(s)) puts("栈内为空");
                else puts("栈不为空");
                break;
        case 2:if (getTopStack(s,&e))printf("栈顶元素为%d\n",e);
                else puts("栈为空，操作失败");
                break;
        case 3:clearStack(s);puts("操作成功");
                break;
        case 4:stackLength(s,&e);printf("栈的实际长度为%d\n",e);
                break;
        case 5:puts("请输入入栈数据：");
                if(pushStack(s,checkinput()))puts("操作成功");
                else puts("操作失败");
                break;
        case 6:if (popStack(s,&e)) puts("操作成功");
                else puts("操作失败");
                break;
        case 7:destroyStack(s);exit(0);
        default :puts("请在范围内输入：");
    }
    fllush(stdin);
    getchar();
	system("cls");menu();
    puts("请输入操作选项");
    select(s);
}
//自定义输入函数
int checkinput()
{
   char str[100];
    int i = 0;

    fflush(stdin);
    while ( (str[i] = getchar()) != '\n')
    {
        if(i == 0 && (str[i] == '+' || str[i] == '-'))
        {
            i++;continue;
        }
        if (str[i]<'0' || str[i]>'9')
        {
            puts("非法输入,请重新输入(数字)：");
            fflush(stdin);
            i = 0;
            continue;
        }
        i++;
    }
    str[i] = '\0';
    return atoi(str);
}
