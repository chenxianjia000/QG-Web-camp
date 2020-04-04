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
        puts("�����뽫����ջ�Ĵ�С(1~999):");
        size = checkinput();
    }
    initStack(s,size);
    system("cls");
    menu();
    puts("���������ѡ��");
    select(s);
    return 0;
}
//�˵�
void menu()
{
    puts("\t\t\t**˳��ջ����**");
    puts("\t\t\t1.�ж�ջ�Ƿ�Ϊ��");
    puts("\t\t\t2.���ջ��Ԫ��");
    puts("\t\t\t3.���ջ��Ԫ��");
    puts("\t\t\t4.����ջ��ʵ�ʳ���");
    puts("\t\t\t5.��ջ����");
    puts("\t\t\t6.��ջ����");
    puts("\t\t\t7.����ջ���˳�ϵͳ");
}
//ѡ����
void select(SqStack *s)
{
    ElemType e;

    switch(checkinput())
    {
        case 1:if (isEmptyStack(s)) puts("ջ��Ϊ��");
                else puts("ջ��Ϊ��");
                break;
        case 2:if (getTopStack(s,&e))printf("ջ��Ԫ��Ϊ%d\n",e);
                else puts("ջΪ�գ�����ʧ��");
                break;
        case 3:clearStack(s);puts("�����ɹ�");
                break;
        case 4:stackLength(s,&e);printf("ջ��ʵ�ʳ���Ϊ%d\n",e);
                break;
        case 5:puts("��������ջ���ݣ�");
                if(pushStack(s,checkinput()))puts("�����ɹ�");
                else puts("����ʧ��");
                break;
        case 6:if (popStack(s,&e)) puts("�����ɹ�");
                else puts("����ʧ��");
                break;
        case 7:destroyStack(s);exit(0);
        default :puts("���ڷ�Χ�����룺");
    }
    fllush(stdin);
    getchar();
	system("cls");menu();
    puts("���������ѡ��");
    select(s);
}
//�Զ������뺯��
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
