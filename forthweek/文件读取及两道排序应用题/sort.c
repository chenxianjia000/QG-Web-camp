#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n)
{
   int t,i,j;
   for(i = 2;i < n;i++)
   {
       t = a[i];
       for(j = i;j > 0;j--)
       {
           if (t<a[j-1])
           {
               a[j] = a[j-1];
           }
           else
            {
                break;
            }
       }
       a[j] = t;
   }
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{

    int index = begin,i = begin,j = mid+1;
    while (i <= mid && j <= end)
    {
        if(a[i] < a[j])
        {
            temp[index++]=a[i++];
        }
        else {
            temp[index++]=a[j++];
        }
    }
    while (i <= mid)
    {
        temp[index++] = a[i++];
    }
    while (j <= end)
    {
        temp[index++] = a[j++];
    }
    memcpy(a + begin, temp + begin, sizeof(int)*(end - begin + 1));
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
    if (begin >= end) {
        return;
    }
    int mid = (begin+end)/2;

    MergeSort(a,begin,mid,temp);
    MergeSort(a,mid+1,end,temp);
    MergeArray(a,begin,mid,end,temp);
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
    if (begin >= end) return;
    int t = a[begin];
    int i = begin,j = end;
    while (i < j)
    {
        while (i < j && a[j] >= t) j--;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] <= t) i++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = t;
    QuickSort_Recursion(a,begin,i-1);
    QuickSort_Recursion(a,i+1,end);
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size)
{
    LinkStack *s ;
    int left = 0,right = 0,position;

    s = (LinkStack*)malloc(sizeof(LinkStack));
    initLStack(s);
    pushLStack(s,0);
    pushLStack(s,size-1);
    while (!isEmptyLStack(s))
    {
        popLStack(s,&right);
        popLStack(s,&left);
        if (left >= right) continue;
        position = onceSort(a,left,right);

        if (position - 1 > left)
        {
            pushLStack(s, left);
            pushLStack(s, position - 1);
        }
        if (right > position + 1)
        {
            pushLStack(s, position + 1);
            pushLStack(s, right);
        }
    }
    destroyLStack(s);
}

int onceSort(int * a,int begin,int end)
{
    int t = a[begin];
    int i = begin,j = end;
    while (i < j)
    {
        while (i < j && a[j] >= t) j--;
        if (i == j) break;
        a[i] = a[j];
        while (i < j && a[i] <= t) i++;
        a[j] = a[i];
    }
    a[i] = t;
    return i;
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end)
{
   
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max)
{
    int *t, i, j;
    t = (int *)malloc(sizeof(int)*(max+1));
    for( i = 0;i <= max;i++) t[i] = 0;
    for( i = 0;i < size; i++)
    {
        t[a[i]]++;
    }
    for( i = 0,j = 0;i <= max;i++)
    {
        while (t[i] != 0)
        {
            a[j++] = i;
            t[i]--;
        }
    }
    free(t);
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size)
{
    int *t,*d,i,j,k,temp;
    int max = a[0],weishu = 0,h=0,c[10];
    t = (int *)malloc(sizeof(int)*size);
    d = (int *)malloc(sizeof(int)*size);

    //for(i = 0;i<size;i++) t[i] = d[i] = 0;
    for(i = 1;i < size;i++)
        if (a[i] > max) max = a[i];
    while (max != 0){
        weishu++;
        max = max/10;
    }
    for(i = 1,temp = 10;i <= weishu;i++,temp *= 10)
    {
        for(j = 0;j < size;j++)
        {
            d[j] = (a[j]%temp)/(temp/10);
        }
        for(j = 0; j <= 9; j++) c[j] = 0;
        h = 0;
        for(j = 0; j < size; j++) c[d[j]]++;

		for(j = 0;j <= 9;j++)
        {
            if (c[j] == 0) continue;
            for(k = 0;k < size;k++)
            {
                if (d[k] == j)
                {
                    t[h++] = a[k];
                    c[j]--;
                    if(c[j] == 0) break;
                }
            }
        }

        for(j = 0;j < size;j++)
        {
            a[j] = t[j];
        }
    }
    free(t);
    free(d);
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size)
{
    int *p,*p0,*p2;

    p = p0 = a;
    p2 = a+size-1;

    while (p2-p > 0)
    {
        while(*p == 1) p++;
        if (*p == 0)
        {
            while (*p0 == 0) p0++;
            *p = *p0;
            *p0 = 0;
        }
        else {
            while (*p2 == 2) p2--;
            if (p - p2 > 0) break;
            *p = *p2;
            *p2 = 2;
        }

    }
}

/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���KС����
 *  @param       : ����ָ��a�����鳤��size
 */
void Findk(int *a,int begin,int end,int k)
{
    int t = a[begin];
    int i = begin,j = end;
    while (i < j)
    {
        while (i < j && a[j] >= t) j--;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] <= t) i++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = t;
    if(i == k) printf("��kС����Ϊ:%d",a[i]);
    else if (i > k) Findk(a,begin,i-1,k);
    else if (i < k) Findk(a,i+1,end,k);
}

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
    *data = s->top->data;
    LinkStackPtr t = s->top;
    s->top = s->top->next;
    s->count--;
    free(t);
    return SUCCESS;
}




