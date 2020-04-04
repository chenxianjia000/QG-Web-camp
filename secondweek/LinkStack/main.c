#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s_get_int();
void menu();
void select(LinkStack *s);

int main()
{
    LinkStack *s = NULL;
    s = (LinkStack *)malloc(sizeof(LinkStack));
    initLStack(s);
    menu();
    puts("���������ѡ��:");
    select(s);
    return 0;
}

//ѡ��˵�
void menu()
{
    puts("\t\t\t**������ÿ��ǰ������Ӧ�Ĳ���**");
    puts("\t\t\t1.�ж�ջ�Ƿ�Ϊ��");
    puts("\t\t\t2.���ջ��Ԫ��");
    puts("\t\t\t3.���ջ");
    puts("\t\t\t4.����ջ��ʵ�ʳ���");
    puts("\t\t\t5.��ջ����");
    puts("\t\t\t6.��ջ����");
    puts("\t\t\t7.����ջ���˳�ϵͳ");
    puts("\t\t\t8.��ղ�����¼");
}

//ѡ����
void select(LinkStack *s)
{
    ElemType e;

    switch(s_get_int())
    {
        case 1:if (isEmptyLStack(s)) puts("ջ��Ϊ��");
                else puts("ջ��Ϊ��");
                break;
        case 2:if (getTopLStack(s,&e)) printf("ջ��Ԫ��Ϊ%d\n",e);
                else puts("ջΪ�գ�����ʧ��");
                break;
        case 3:clearLStack(s);puts("�����ɹ�");
                break;
        case 4:LStackLength(s,&e);printf("ջ��ʵ�ʳ���Ϊ%d\n",e);
                break;
        case 5:puts("��������ջ���ݣ�");
                if (pushLStack(s,s_get_int())) puts("�����ɹ�");
                else puts("����ʧ��");
                break;
        case 6:if (popLStack(s,&e)) puts("�����ɹ�");
                else puts("����ʧ��");
                break;
        case 7:destroyLStack(s);exit(0);
        case 8:system("cls");menu();break;
        default :puts("���ڷ�Χ�����룺");
    }
     puts("���������ѡ��");
    select(s);
}

//�Լ���ѡ����
int s_get_int()
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
            puts("�Ƿ�����,����������(����)��");
            fflush(stdin);
            i = 0;
            continue;
        }
        i++;
    }
    str[i] = '\0';
    return atoi(str);
}
