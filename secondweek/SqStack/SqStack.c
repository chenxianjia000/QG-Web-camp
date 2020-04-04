#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

//初始化栈
Status initStack(SqStack *s,int sizes)
{
    s->elem = (ElemType *)malloc(sizes*sizeof(ElemType));
    if (!s->elem) {
        puts("内存空间无法分配！");
        return ERROR;
    }
    s->top = s->elem;
    s->size = sizes;
    return SUCCESS;
}

//判断栈是否为空
Status isEmptyStack(SqStack *s)
{
    if (s->top == s->elem) return SUCCESS;
    return ERROR;
}

//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e)
{
    if (isEmptyStack(s)) {
        puts("栈为空！");
        return ERROR;
    }
    *e = *(s->top-1);
    return SUCCESS;
}

//清空栈
Status clearStack(SqStack *s)
{
    s->top = s->elem;
    return SUCCESS;
}

//销毁栈
Status destroyStack(SqStack *s)
{
    free(s->elem);
    free(s);
    return SUCCESS;
}

//检测栈长度
Status stackLength(SqStack *s,int *length)
{
    *length = s->top - s->elem;
    return SUCCESS;
}

//入栈
Status pushStack(SqStack *s,ElemType data)
{
    if(s->top - s->elem == s->size)
    {
        puts("栈已满，无法入栈");
        return ERROR;
    }
    *(s->top++) = data;
    return SUCCESS;
}

//出栈
Status popStack(SqStack *s,ElemType *data)
{
    if (isEmptyStack(s)) {
        puts("栈为空！");
        return ERROR;
    }
    *data = *(--s->top);
    return SUCCESS;
}





























