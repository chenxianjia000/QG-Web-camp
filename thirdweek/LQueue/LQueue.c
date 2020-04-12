#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InitLQueue(LQueue *Q)
{
    Q->front = Q->rear = NULL;
    Q->length = 0;
}

void DestoryLQueue(LQueue *Q)
{
    ClearLQueue(Q);
    free(Q);
    exit(0);
}

Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q->length == 0) return TRUE;
    return FALSE;
}
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if (IsEmptyLQueue(Q)) return FALSE;
    size_t temp = sizeof(Q->front->data);
    memcpy(e,Q->front->data,temp);
    return TRUE;
}

int LengthLQueue(LQueue *Q)
{
    return Q->length;
}

Status EnLQueue(LQueue *Q, void *data)
{
    Node * pnew;
    size_t temp;

    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL) {
        printf("内存不足！\n");
        return FALSE;
    }
    pnew->next = NULL;
    pnew->data = (void*)malloc(typeSize);
    memcpy(pnew->data,data,typeSize);
    if (IsEmptyLQueue(Q))
        Q->front = pnew;
    else
        Q->rear->next = pnew;
    Q->rear = pnew;
    Q->length++;
    return TRUE;
}

Status DeLQueue(LQueue *Q)
{
    Node * pt;

    if(IsEmptyLQueue(Q))
        return FALSE;
    pt = Q->front;
    Q->front = Q->front->next;
    free(pt->data);
    free(pt);
    Q->length--;
    if (!Q->length)
        Q->rear = NULL;

    return TRUE;
}

void ClearLQueue(LQueue *Q)
{
    while (!IsEmptyLQueue(Q))
        DeLQueue(Q);
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    if (IsEmptyLQueue(Q))
    {
        puts("队列为空！");
        return FALSE;
    }
    Node * pt;
    pt = Q->front;
    while (pt)
    {
        LPrint(pt->data);
        pt = pt->next;
    }
    printf("\n");
    return TRUE;
}

void LPrint(void *q)
{
    if  (type == 'd')
            printf("--> %.2lf", *(double*)q);
    else if (type == 'c')
            printf("--> %c", *(char*)q);
    else if (type == 'i')
            printf("--> %d ", *(int*)q);
    else if (type == 's')
            printf("--> %s ", (char*)q);
   

}







































