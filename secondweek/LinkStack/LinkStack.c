#include"LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ��ջ
Status initLStack(LinkStack *s)
{
    //s = (LinkStack *)malloc(sizeof(LinkStack));
    s->top = NULL;
    s->count = 0;
    return SUCCESS;

}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
    if (!s->top) return SUCCESS;
    return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e)
{
    if (!s->top)
    {
        puts("ջΪ�գ�");
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s)
{
    LinkStackPtr p1,p2;
    p1 = p2 = s->top;
    s->top = NULL;
    s->count = 0;
    while(p2){
        p2 = p2->next;
        free(p1);
        p1 = p2;
    }
    return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s)
{
    clearLStack(s);
    free(s);
    return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length)
{
    *length = s->count;
    return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data)
{
    LinkStackPtr p =(LinkStackPtr) malloc(sizeof(StackNode));
    p->next = s->top;
    p->data = data;
    s->top = p;
    s->count++;
    return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data)
{
    if (isEmptyLStack(s)) {
        puts("ջΪ��!");
        return ERROR;
    }
    LinkStackPtr t = s->top;
    s->top = s->top->next;
    s->count--;
    free(t);
    return SUCCESS;
}
