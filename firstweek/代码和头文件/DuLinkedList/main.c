#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void select(DuLinkedList h);
void pri(ElemType e);
DuLinkedList refresh(DuLinkedList h);
DuLinkedList getNode(DuLinkedList h,int n);
DuLinkedList creatNode();
int sgets();

int main(void)
{
    int n = 0;
    DuLinkedList p1,p2,h;

    while(n <= 0){
        puts("������Ҫ����������ڵ���(����0):");
        n = sgets();
    }
	
	int i;
    for( i = 1;i <= n;i++)
        if(i == 1) {
            InitList_DuL(&h);
            h->data = i;
            p1 = h;
        }
        else{
            p2 = (DuLinkedList)malloc(sizeof(DuLNode));
            p2->data = i;
            p2->next = NULL;
            p2->prior = p1;
            p1->next = p2;
            p1 = p2;
        }
        puts("\t****��ѡ��ÿ��ǰ�������Ӧ���������****");
        puts("\t\t\t\t1.���������˳�����");
        puts("\t\t\t\t2.����һ���ڵ㵽����ָ���ڵ�ǰ");
        puts("\t\t\t\t3.����һ���ڵ㵽����ָ���ڵ��");
        puts("\t\t\t\t4.ɾ��һ���ڵ㲢����ڵ�����");
        puts("\t\t\t\t5.�������������������");
        select(h);
    return 0;
}
void select(DuLinkedList h)
{
    char ch;
    ElemType a,*e;
    fflush(stdin);
    e = &a;
    puts("��ѡ����Ҫ���еĲ�����");
    switch(ch = getchar()) {
        case '1':
            DestroyList_DuL(&h);
            exit(0);
        case '2':
            puts("��������Ҫ�ڵڼ����ڵ�ǰ���룺");
            a = sgets();
            if(InsertBeforeList_DuL(getNode(h,a), creatNode())) puts("�����ɹ�");
            else puts("����ʧ��");
            h = refresh(h);
            break;
        case '3':
            puts("��������Ҫ�ڵڼ����ڵ�����룺");
            a = sgets();
            if(InsertAfterList_DuL(getNode(h,a), creatNode())) puts("�����ɹ�");
            else puts("����ʧ��");
            break;
        case '4':
            puts("��������Ҫɾ���ڼ����ڵ�֮��Ľڵ㣺");
            a = sgets();
            if(DeleteList_DuL(getNode(h,a),e)) printf("�����ɹ���ɾ���ڵ�����Ϊ%d\n",*e);
            else puts("����ʧ��");
            break;
        case '5':
            TraverseList_DuL(h,pri);break;
        default :puts("������ȷ�ķ�Χ���룡");
    }
     select(h);

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
//�ҵ���Ҫ�õ��Ľڵ�
DuLinkedList getNode(DuLinkedList h,int n)
{
    if(n<1) return NULL;
    DuLinkedList p = h;
    
    int i; 
    for(i = 1;i < n;i++)
    {
        p = p->next;
        if(i < n && p->next == NULL)
            return NULL;
    }
    return p;
}
//����һ���ڵ�
DuLinkedList creatNode()
{
    DuLinkedList q;
    q = (DuLinkedList)malloc(sizeof(DuLNode));
    puts("��������Ҫ��������ݣ�");
    q->data = sgets();
    q->next = q->prior = NULL;
    return q;
}

//�Զ������뺯��
void pri(ElemType e)
{
    printf("%d->",e);
}


DuLinkedList refresh(DuLinkedList h)
{
    while(h->prior) h = h->prior;
    return h;
}
