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

    puts("��ѡ�����Ҫ��ȡ����������:\n a.int��\t b.char�� \n c.double��\t d.string��");
    setType();
    puts("��ȷ��������󳤶�Ϊ:");
    max = getInt();
    if (max <= 0) {
        puts("�����������������");
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

    puts("��ѡ����Ĳ���");
    switch(getInt())
    {
        case 1:DestoryLQueue(Q);
        case 2:if (IsEmptyLQueue(Q)) puts("����Ϊ��");
                else puts("���в�Ϊ��");
                break;
        case 3:if (GetHeadLQueue(Q,t))
                {
                    printf("�����ɹ�,ͷ�������Ϊ");
                    LPrint(t);
                    printf("\n");
                }
                else puts("����ʧ��,����Ϊ��");
                break;
        case 4:i = LengthLQueue(Q);printf("���г���Ϊ%d\n",i);
                break;
        case 5:if (Q->length == max) puts("����ʧ��,��������");
                else {
                    setVoid(Q);
                    puts("�����ɹ�");
                }
                break;
        case 6:if (DeLQueue(Q)) puts("�����ɹ�");
                else puts("����ʧ�ܣ�����Ϊ��");
                break;
        case 7:ClearLQueue(Q);puts("�����");break;
        case 8:if (TraverseLQueue(Q,LPrint)) puts("�����ɹ�");
                else puts("����ʧ��");
                break;
       
        default :puts("�������");
    }
    fflush(stdin);
	getchar(); 
    system("cls");
	menu();
    select(Q,max);
}

void menu()
{
    puts("\t\t1.ɾ�����в��˳�ϵͳ");
    puts("\t\t2.�ж϶����Ƿ�Ϊ��");
    puts("\t\t3.���ͷ�������");
    puts("\t\t4.��������ִ泤��");
    puts("\t\t5.��Ӳ���");
    puts("\t\t6.���Ӳ���");
    puts("\t\t7.��ն���");
    puts("\t\t8.�������в�����Ԫ��");

}

void setVoid(LQueue * Q)
{
    char c[100];

    if (type == 'i')
    {
        int a = 0;

        puts("����������");
        a = getInt();
        EnLQueue(Q,&a);
    }
    else if (type == 'c')
    {
        puts("����������");
        s_gets(c,3);
        if (c[2] != '\0')
        {
            puts("���ʹ�������������");
            s_gets(c,3);
        }
        EnLQueue(Q,&c[0]);
    }
    else if (type == 'd')
    {
        double d;


        puts("����������");
        s_gets(c,100);
skip :  d = atof(c);
        if (d == 0 ) {
            int i = 0;
            while (c[i++] != '\0')
            {
                if (c[i] != '0' && c[i] != '.')
                {
                    puts("�����������������\n");
                    s_gets(c,100);
                    goto skip;
                }
            }
        }
        EnLQueue(Q,&d);
    }
    else if (type == 's')
    {
        puts("����������");
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
                printf("����������������룡\n");
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
        puts("�����������������");
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

