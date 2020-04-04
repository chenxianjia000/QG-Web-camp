#include"LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

//³õÊ¼»¯Õ»
Status initLStack(LinkStack *s)
{
    //s = (LinkStack *)malloc(sizeof(LinkStack));
    s->top = NULL;
    s->count = 0;
    return SUCCESS;

}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack *s)
{
    if (!s->top) return SUCCESS;
    return ERROR;
}

//µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack *s,ElemType *e)
{
    if (!s->top)
    {
        puts("Õ»Îª¿Õ£¡");
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

//Çå¿ÕÕ»
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

//Ïú»ÙÕ»
Status destroyLStack(LinkStack *s)
{
    clearLStack(s);
    free(s);
    return SUCCESS;
}

//¼ì²âÕ»³¤¶È
Status LStackLength(LinkStack *s,int *length)
{
    *length = s->count;
    return SUCCESS;
}

//ÈëÕ»
Status pushLStack(LinkStack *s,ElemType data)
{
    LinkStackPtr p =(LinkStackPtr) malloc(sizeof(StackNode));
    p->next = s->top;
    p->data = data;
    s->top = p;
    s->count++;
    return SUCCESS;
}

//³öÕ»
Status popLStack(LinkStack *s,ElemType *data)
{
    if (isEmptyLStack(s)) {
        puts("Õ»Îª¿Õ!");
        return ERROR;
    }
    LinkStackPtr t = s->top;
    s->top = s->top->next;
    s->count--;
    free(t);
    return SUCCESS;
}
