#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void select(LinkedList h);
LinkedList getNode(LinkedList h,int n);
LinkedList creatNode();
void pri(ElemType e);
int sgets();
int main(void)
{
    int n = 0;
    LinkedList p1,h;

    while(n <= 0){
        puts("������Ҫ����������ڵ���(����0):");
        n = sgets();
    }
	
	int i;
    for(i=1;i<=n;i++)
        if(i == 1) {
            InitList(&h);
            h->data = i;
        }
        else{
            p1 = (LinkedList)malloc(sizeof(LNode));
            p1->data = i;
            p1->next = h;
            h = p1;
        }
        puts("\t****��ѡ��ÿ��ǰ���Ӧ��ŵ�ѡ���������****");
        puts("\t\t\t\t1.���������˳�����");
        puts("\t\t\t\t2.����һ���ڵ㵽����");
        puts("\t\t\t\t3.ɾ��һ���ڵ㲢����ڵ�����");
        puts("\t\t\t\t4.�������������������");
        puts("\t\t\t\t5.��ѯ�����Ƿ����ĳ������");
        puts("\t\t\t\t6.��ת����");
        puts("\t\t\t\t7.�ж������Ƿ����ѭ��");
        puts("\t\t\t\t8.�����м�ڵ�");

        select(h);

        return 0;
}
//ѡ�����
void select(LinkedList h)
{
    char ch;
    ElemType a,*e;
    LinkedList t;
    fflush(stdin);
    e = &a;
    puts("��ѡ����Ҫ���еĲ�����");
    switch(ch = getchar()){
            case '1':
                DestroyList(&h);
                exit(0);
            case '2':
                puts("��������Ҫ�ڵڼ����ڵ����룺");
                a = sgets();
                if(InsertList(getNode(h,a), creatNode()))puts("�����ɹ�");
                else puts("����ʧ��");
                break;
            case '3':
                puts("��������Ҫɾ���ڼ����ڵ�֮��Ľڵ㣺");
                a = sgets();
                if(DeleteList(getNode(h,a),e))printf("�����ɹ���ɾ���ڵ�����Ϊ%d\n",*e);
                else puts("����ʧ��");
                break;
            case '4':
                TraverseList(h,pri);break;
            case '5':
                puts("������Ҫ��ѯ������");
                a = sgets();
                if(SearchList(h, a))puts("�������и�����");
                else puts("�����в����ڸ�����");
                break;
            case '6':
                if(ReverseList(&h))puts("�����ɹ�");
                else puts("����ʧ��");
                break;
            case '7':
                if(IsLoopList(h))puts("�������ѭ��");
                else puts("��������ѭ��");
                break;
            case '8':
                t = FindMidNode(&h);
                printf("�м�ڵ�����Ϊ%d\n",t->data);
                break;
            default :puts("������ȷ�ķ�Χ���룡");
        }
        select(h);
}

//�ҵ���Ҫ�õ��Ľڵ�
LinkedList getNode(LinkedList h,int n)
{
    if(n<1) return NULL;
    LinkedList p = h;
	
	int i; 
    for(i = 1;i < n;i++)
    {
        p = p->next;
        if(i < n-1 && p->next == NULL)
            return NULL;
    }
    return p;
}

//����һ���ڵ�
LinkedList creatNode()
{
    LinkedList q;
    q = (LinkedList)malloc(sizeof(LNode));
    puts("��������Ҫ��������ݣ�");
    q->data = sgets();
    return q;
}

//�Զ���������� 
void pri(ElemType e)
{
    printf("%d->",e);
}

//�Զ������뺯��
int sgets()
{
    char * ret_val;
    char * find;
    char  st[100];

    fflush(stdin);
    ret_val = fgets(st,100,stdin);
    if(ret_val){
        find = strchr(st,'\n');
        if(find)*find = '\0';
        else while(getchar() != '\n')
                continue;
    }
    return atoi(ret_val);
}
