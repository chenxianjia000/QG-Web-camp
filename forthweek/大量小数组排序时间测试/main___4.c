#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qgsort.h"

void randNum( int* a, int count);
void timeTest(int *a,int size);

int main()
{
    int a[100];
    puts("��100k��������������ʱ������:");
    timeTest(a,100);
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
    int i, t[200000];
    clock_t start, finish;

	start = clock();
	
	for( i =0 ;i < 100000;i++)
	{
	    randNum(a,size);
	    insertSort(a,size);
	}
	finish = clock();
	printf("����������ʱ%ld ms\n",finish-start);

	start = clock();

	for( i =0 ;i < 100000;i++)
	{
	    randNum(a,size);
	    MergeSort(a,0,size-1,t);
	}
	finish = clock();
	printf("�鲢������ʱ%ld ms\n",finish-start);

	start = clock();
	for( i =0 ;i < 100000;i++)
	{
	    randNum(a,size);
	    QuickSort_Recursion(a, 0,size-1);
	}
	finish = clock();
	printf("��������(�ݹ��)��ʱ%ld ms\n",finish-start);

	start = clock();
	for( i =0 ;i < 100000;i++)
	{
	    randNum(a,size);
	    QuickSort(a,size);
	}
	finish = clock();
	printf("��������(�ǵݹ��)��ʱ%ld ms\n",finish-start);

	start = clock();
	for( i =0 ;i < 100000;i++)
	{
	    randNum(a,size);
	    RadixCountSort(a,size);
	}
	finish = clock();
	printf("����������ʱ%ld ms\n",finish-start);
}
