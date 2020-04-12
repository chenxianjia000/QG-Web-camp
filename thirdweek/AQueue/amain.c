#include "AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * s_gets(char *st,int n);
void setType();
int getInt();
void menu();
void select(AQueue * Q);
void setVoid(AQueue * Q);

int main()
{
    AQueue * Q;

    Q = (AQueue *)malloc(sizeof(AQueue));
 
    puts("请选择队列要存取的数据类型:\n a.int型\t b.char型 \n c.double型\t d.string型 \n ");
    setType();
    InitAQueue(Q);
    menu();
    select(Q);
    return 0;
}

//选择操作
void select(AQueue * Q)
{
    int i =0;
    void *t;

    puts("请选择你的操作");
    switch(getInt())
    {
        case 1:DestoryAQueue(Q);
        case 2:if (IsEmptyAQueue(Q)) puts("队列为空");
                else puts("队列不为空");
                break;
        case 3:if (IsFullAQueue(Q)) puts("队列已满");
                else puts("队列未满");
                break;
        case 4:if (GetHeadAQueue(Q,t))
                {
                    printf("操作成功,头结点数据为");
                    APrint(t);
                    printf("\n");
                }
                else puts("操作失败,队列为空");
                break;
        case 5:i = LengthAQueue(Q);printf("队列长度为%d\n",i);
                break;
        case 6:if (IsFullAQueue(Q)) puts("操作失败,队列已满");
                else {
                    setVoid(Q);
                    puts("操作成功");
                }
                break;
        case 7:if (DeAQueue(Q)) puts("操作成功");
                else puts("操作失败，队列为空");
                break;
        case 8:ClearAQueue(Q);puts("已清空");break;
        case 9:if (TraverseAQueue(Q,APrint)) puts("操作成功");
                else puts("操作失败");
                break;
        default :puts("输入错误");
    }
    fflush(stdin);
	getchar();  
    system("cls");
	menu();
    select(Q);
}

//打印菜单
void menu()
{
    puts("\t\t1.删除队列并退出系统");
    puts("\t\t2.判断队列是否为空");
    puts("\t\t3.判断队列是否已满");
    puts("\t\t4.输出头结点数据");
    puts("\t\t5.输出队列现存长度");
    puts("\t\t6.入队操作");
    puts("\t\t7.出队操作");
    puts("\t\t8.清空队列");
    puts("\t\t9.遍历队列并输入元素");
}

//确定泛型
void setType()
{
    char t[3];

    s_gets(t,3);
    if (t[0] == 'a' && t[1] == '\0')
    {
        type = 'i';
        typeSize = sizeof(int);
    }
    else if (t[0] == 'b' && t[1] == '\0')
    {
        type = 'c';
        typeSize = sizeof(char);
    }
    else if (t[0] == 'c' && t[1] == '\0')
    {
        type = 'd';
        typeSize = sizeof(double);
    }
    else if (t[0] == 'd' && t[1] == '\0')
    {
        type = 's';
        typeSize = sizeof(char)*100;
    }
    else {
        puts("输入错误！请重新输入");
        setType();
    }

}

//获得int
int getInt()
{
    char in[11];
    int t;

    s_gets(in,11);
    t = atoi(in);
    if (t == 0) {
            if (in[1] != 0 || in[2] != '\0')
            {
                printf("输入错误，请重新输入！\n");
                t = getInt();
            }
    }
    return t;
}

//读取键盘输入
char * s_gets(char *st,int n)
{
    char * ret_val;
    char * find;

    fflush(stdin);
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        find = strchr(st,'\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                    continue;
    }
    return ret_val;
}

//入队数据操作
void setVoid(AQueue * Q)
{
    char c[100];

    if (type == 'i')
    {
        int a = 0;

        puts("请输入数据");
        a = getInt();
        EnAQueue(Q,&a);
    }
    else if (type == 'c')
    {
        puts("请输入数据");
        s_gets(c,3);
        if (c[2] != '\0')
        {
            puts("类型错误，请重新输入");
            s_gets(c,3);
        }
        EnAQueue(Q,&c[0]);
    }
    else if (type == 'd')
    {
        double d;


        puts("请输入数据");
        s_gets(c,100);
skip :  d = atof(c);
        if (d == 0 ) {
            int i = 0;
            while (c[i++] != '\0')
            {
                if (c[i] != '0' && c[i] != '.')
                {
                    puts("输入错误，请重新输入\n");
                    s_gets(c,100);
                    goto skip;
                }
            }
        }
        EnAQueue(Q,&d);
    }
    else if (type == 's')
    {
        puts("请输入数据");
        s_gets(c,100);
        EnAQueue(Q,&c);
    }

}

