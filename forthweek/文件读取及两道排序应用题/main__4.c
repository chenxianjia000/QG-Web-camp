#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void menu();
int s_get_int();
void rand_checked( int* a, int count ,int max);
void a_randTxt(int *a,int size,int max);
void printArr(int *a,int size);

int main()
{
    int select = 0,temp = 0,*a;
    int size,max;
    menu();

    while(1) {
        puts("��������ȷ��ָ��");
        select = s_get_int();
        if (select == 10) exit(0);
        if (select == 9)
        {
            system("cls");
            menu();
            puts("��������ȷ��ָ��");
            select = s_get_int();
        }
        //���鸳ֵ����
        puts("���������鳤��");
        size = s_get_int();
        a = (int *)malloc(sizeof(int)*size);
        puts("������������������ֵ");
        max = s_get_int();
        puts("1.�������һ�����鲢�浽arr.txt�ļ�,�ٽ�������\t\t2.��arr.txt��ȡһ����������������");
        temp = s_get_int();
        do{
            if (temp == 1) rand_checked(a,size,max);
            else if (temp == 2) a_randTxt(a,size,max);
            else puts("�����������������");
        }while(temp != 1 && temp != 2);
        //�����������
        switch(select)
        {
            case 1:{
                puts("����ǰ����");
                printArr(a,size);
                insertSort(a,size);
                puts("���������");
                printArr(a,size);break;
            }
            case 2:{
                int *temp;
                temp = (int *)malloc(sizeof(int)*size);
                puts("����ǰ����");
                printArr(a,size);
                MergeSort(a,0,size-1,temp);
                puts("���������");
                printArr(a,size);
                free(temp);
                break;
            }
            case 3:{
                puts("����ǰ����");
                printArr(a,size);
                QuickSort_Recursion(a,0,size-1);
                puts("���������");
                printArr(a,size);break;
            }
            case 4:{
                puts("����ǰ����");
                printArr(a,size);
                QuickSort(a,size);
                puts("���������");
                printArr(a,size);break;
            }

            case 5:{
                puts("����ǰ����");
                printArr(a,size);
                CountSort(a, size ,max);
                puts("���������");
                printArr(a,size);break;
            }
            case 6:{
                puts("����ǰ����");
                printArr(a,size);
                RadixCountSort(a,size);
                puts("���������");
                printArr(a,size);break;
            }
            case 7:{
                if (max > 2)
                {
                    puts("��ɫ����ֻ������0,1,2��");
                    break;
                }
                puts("����ǰ����");
                printArr(a,size);
                ColorSort(a,size);
                puts("���������");
                printArr(a,size);break;
            }
            case 8:{
                puts("��Ҫ�ҵڼ�С������");
                int k = s_get_int();
                if(k == 0 || k > size)
                {
                    puts("k�����벻�Ϸ���");
                    break;
                }
                puts("����Ϊ");
                printArr(a,size);
                Findk(a,0,size-1,k);
                break;
            }
            default:puts("�������");
        }
    }
    return 0;
}

void a_randTxt(int *a,int size,int max)
{
    FILE *fp = fopen("arr.txt","r");
    int s = 0,m = 0,flag = 0;
    FILE *t;  
    t = tmpfile();

    while (!feof(fp)) {
        fscanf(fp,"%d %d",&s,&m);
        if (s == size && m == max)
        {	
			int i;
            for( i = 0;i < size;i++)
            {
                fscanf(fp,"%d",&a[i]);
            }
            flag = 1;
            break;
        }
        fgets(t,1024,fp);
    }
    fclose(fp);
    if (flag == 0)
    {
        puts("δ�ܴ�arr.txt�ļ����ҵ���������������");
        puts("���������һ���������������鲢����arr.txt");
        rand_checked(a,size,max);
    }
}

void rand_checked( int* a, int size ,int max)
{

    int i = 0;
    FILE *fp = fopen("arr.txt","a+");

    fprintf(fp,"%d %d ",size,max);
    while( i < size )
    {
        a[i] = rand() % (max+1);
        fprintf(fp,"%d ",a[i]);
        i++;
    }
    fprintf(fp,"\n");
    fclose(fp);
}


void menu()
{
    puts("\t\t������Գ���");
    puts("\t\t1.���Բ������");
    puts("\t\t2.���Թ鲢����");
    puts("\t\t3.���Կ������򣨵ݹ�棩");
    puts("\t\t4.���Կ������򣨷ǵݹ�棩");
    puts("\t\t5.���Լ�������");
    puts("\t\t6.���Ի�����������");
    puts("\t\t7.������ɫ����");
    puts("\t\t8.��һ�������������ҵ���KС����");
    puts("\t\t9.��ղ�����¼");
    puts("\t\t10.�˳�����ϵͳ");

}


void printArr(int *a,int size)
{  
	int i;
    for( i = 0;i < size;i++)
        printf("%d ",a[i]);
    puts("");
}


int s_get_int()
{
    char str[100];
    int i = 0;

    fflush(stdin);
    while ( (str[i] = getchar()) != '\n')
    {
        if (str[i]<'0' || str[i]>'9')
        {
            puts("�Ƿ�����,����������(����)");
            fflush(stdin);
            i = 0;
            continue;
        }
        i++;
    }
    str[i] = '\0';
    return atoi(str);
}


