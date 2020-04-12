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
 
    puts("��ѡ�����Ҫ��ȡ����������:\n a.int��\t b.char�� \n c.double��\t d.string�� \n ");
    setType();
    InitAQueue(Q);
    menu();
    select(Q);
    return 0;
}

//ѡ�����
void select(AQueue * Q)
{
    int i =0;
    void *t;

    puts("��ѡ����Ĳ���");
    switch(getInt())
    {
        case 1:DestoryAQueue(Q);
        case 2:if (IsEmptyAQueue(Q)) puts("����Ϊ��");
                else puts("���в�Ϊ��");
                break;
        case 3:if (IsFullAQueue(Q)) puts("��������");
                else puts("����δ��");
                break;
        case 4:if (GetHeadAQueue(Q,t))
                {
                    printf("�����ɹ�,ͷ�������Ϊ");
                    APrint(t);
                    printf("\n");
                }
                else puts("����ʧ��,����Ϊ��");
                break;
        case 5:i = LengthAQueue(Q);printf("���г���Ϊ%d\n",i);
                break;
        case 6:if (IsFullAQueue(Q)) puts("����ʧ��,��������");
                else {
                    setVoid(Q);
                    puts("�����ɹ�");
                }
                break;
        case 7:if (DeAQueue(Q)) puts("�����ɹ�");
                else puts("����ʧ�ܣ�����Ϊ��");
                break;
        case 8:ClearAQueue(Q);puts("�����");break;
        case 9:if (TraverseAQueue(Q,APrint)) puts("�����ɹ�");
                else puts("����ʧ��");
                break;
        default :puts("�������");
    }
    fflush(stdin);
	getchar();  
    system("cls");
	menu();
    select(Q);
}

//��ӡ�˵�
void menu()
{
    puts("\t\t1.ɾ�����в��˳�ϵͳ");
    puts("\t\t2.�ж϶����Ƿ�Ϊ��");
    puts("\t\t3.�ж϶����Ƿ�����");
    puts("\t\t4.���ͷ�������");
    puts("\t\t5.��������ִ泤��");
    puts("\t\t6.��Ӳ���");
    puts("\t\t7.���Ӳ���");
    puts("\t\t8.��ն���");
    puts("\t\t9.�������в�����Ԫ��");
}

//ȷ������
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

//���int
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

//��ȡ��������
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

//������ݲ���
void setVoid(AQueue * Q)
{
    char c[100];

    if (type == 'i')
    {
        int a = 0;

        puts("����������");
        a = getInt();
        EnAQueue(Q,&a);
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
        EnAQueue(Q,&c[0]);
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
        EnAQueue(Q,&d);
    }
    else if (type == 's')
    {
        puts("����������");
        s_gets(c,100);
        EnAQueue(Q,&c);
    }

}

