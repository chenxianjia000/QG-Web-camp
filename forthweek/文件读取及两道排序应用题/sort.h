
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K小的数
 *  @param       : 数组指针a，数组长度size
 */
void Findk(int *a,int begin,int end,int k);

int onceSort(int * a,int begin,int end);

typedef enum Status
{
    ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s,int *length);//检测栈长度
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s,ElemType *data);//出栈
#endif // QUEUE_H_INCLUDED
