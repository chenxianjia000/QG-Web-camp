#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

void randNum( int* a, int count);
void timeTest(int *a,int size);

int main()
{

    int a1[10000],a2[50000],a3[200000];
    puts("10000数量级的排序时间测试如下：");
    timeTest(a1,10000);
    puts("50000数量级的排序时间测试如下：");
    timeTest(a2,50000);
    puts("200000数量级的排序时间测试如下：");
    timeTest(a3,200000);
}


void randNum( int* a, int count )
{

    int i = 0;

    while( i < count )
    {

        a[i++] = rand() % count;

    }

}

void timeTest(int *a,int size)
{
    int t[200000];
    clock_t start, finish;

    randNum(a,size);
	start = clock();
	insertSort(a,size);
	finish = clock();
	printf("插入排序用时%ld ms\n",finish-start);

	randNum(a,size);
	start = clock();
	MergeSort(a,0,size-1,t);
	finish = clock();
	printf("归并排序用时%ld ms\n",finish-start);

	randNum(a,size);
	start = clock();
	QuickSort_Recursion(a, 0,size-1);
	finish = clock();
	printf("快速排序(递归版)用时%ld ms\n",finish-start);

	randNum(a,size);
	start = clock();
	QuickSort(a,10000);
	finish = clock();
	printf("快速排序(非递归版)用时%ld ms\n",finish-start);

	randNum(a,size);
	start = clock();
	RadixCountSort(a,size);
	finish = clock();
	printf("基数排序用时%ld ms\n\n\n",finish-start);
}









































