#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * s_gets(char *st,int n);
void setType();
int getInt();
void menu();
void select(LQueue * Q,size_t max);
void setVoid(LQueue * Q);

int main()
{
    size_t max;
    LQueue * Q;

    Q = (LQueue *)malloc(sizeof(LQueue));

    puts("请选择队列要存取的数据类型:\n a.int型\t b.char型 \n c.double型\t d.string型");
    setType();
    puts("请确定队列最大长度为:");
    max = getInt();
    if (max <= 0) {
        puts("输入错误，请重新输入");
        max = getInt();
    }
    InitLQueue(Q);
    menu();
    select(Q,max);
    return 0;
}

void select(LQueue * Q,size_t max)
{
    int i =0;
    void *t;

    puts("请选择你的操作");
    switch(getInt())
    {
        case 1:DestoryLQueue(Q);
        case 2:if (IsEmptyLQueue(Q)) puts("队列为空");
                else puts("队列不为空");
                break;
        case 3:if (GetHeadLQueue(Q,t))
                {
                    printf("操作成功,头结点数据为");
                    LPrint(t);
                    printf("\n");
                }
                else puts("操作失败,队列为空");
                break;
        case 4:i = LengthLQueue(Q);printf("队列长度为%d\n",i);
                break;
        case 5:if (Q->length == max) puts("操作失败,队列已满");
                else {
                    setVoid(Q);
                    puts("操作成功");
                }
                break;
        case 6:if (DeLQueue(Q)) puts("操作成功");
                else puts("操作失败，队列为空");
                break;
        case 7:ClearLQueue(Q);puts("已清空");break;
        case 8:if (TraverseLQueue(Q,LPrint)) puts("操作成功");
                else puts("操作失败");
                break;
       
        default :puts("输入错误");
    }
    fflush(stdin);
	getchar(); 
    system("cls");
	menu();
    select(Q,max);
}

void menu()
{
    puts("\t\t1.删除队列并退出系统");
    puts("\t\t2.判断队列是否为空");
    puts("\t\t3.输出头结点数据");
    puts("\t\t4.输出队列现存长度");
    puts("\t\t5.入队操作");
    puts("\t\t6.出队操作");
    puts("\t\t7.清空队列");
    puts("\t\t8.遍历队列并输入元素");

}

void setVoid(LQueue * Q)
{
    char c[100];

    if (type == 'i')
    {
        int a = 0;

        puts("请输入数据");
        a = getInt();
        EnLQueue(Q,&a);
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
        EnLQueue(Q,&c[0]);
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
        EnLQueue(Q,&d);
    }
    else if (type == 's')
    {
        puts("请输入数据");
        s_gets(c,100);
        EnLQueue(Q,&c);
    }
   
}
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

