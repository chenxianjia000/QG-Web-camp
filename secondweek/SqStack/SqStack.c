#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ��ջ
Status initStack(SqStack *s,int sizes)
{
    s->elem = (ElemType *)malloc(sizes*sizeof(ElemType));
    if (!s->elem) {
        puts("�ڴ�ռ��޷����䣡");
        return ERROR;
    }
    s->top = s->elem;
    s->size = sizes;
    return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s)
{
    if (s->top == s->elem) return SUCCESS;
    return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e)
{
    if (isEmptyStack(s)) {
        puts("ջΪ�գ�");
        return ERROR;
    }
    *e = *(s->top-1);
    return SUCCESS;
}

//���ջ
Status clearStack(SqStack *s)
{
    s->top = s->elem;
    return SUCCESS;
}

//����ջ
Status destroyStack(SqStack *s)
{
    free(s->elem);
    free(s);
    return SUCCESS;
}

//���ջ����
Status stackLength(SqStack *s,int *length)
{
    *length = s->top - s->elem;
    return SUCCESS;
}

//��ջ
Status pushStack(SqStack *s,ElemType data)
{
    if(s->top - s->elem == s->size)
    {
        puts("ջ�������޷���ջ");
        return ERROR;
    }
    *(s->top++) = data;
    return SUCCESS;
}

//��ջ
Status popStack(SqStack *s,ElemType *data)
{
    if (isEmptyStack(s)) {
        puts("ջΪ�գ�");
        return ERROR;
    }
    *data = *(--s->top);
    return SUCCESS;
}





























