/* 快速排序为不稳定排序: 平均、最好时间复杂度 O( n ),
 * 最坏时间复杂度 O( n^2 ), 空间复杂度 O( n )
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 10
//#define swap(base, j, i) { int tmp = 0; tmp = base[ i ]; base[ i ] = base[ j ]; base[ j ] = tmp; }

void swap(int *base, int j, int i) { int tmp = 0; tmp = base[ i ], base[ i ] = base[ j ], base[ j ] = tmp; }
void destroy(int *base) { free(base); }
int *init(int size, int left, int right) {
	int i, *base = (int *)malloc(size * sizeof(int)); 
	srand(time(NULL));
	for (i = 0; i < size; ++i) base[ i ] = rand( ) % (right - left + 1) + left;
	return base;
}

void print(int *base, int size) {
    int i;
    for (i = 0; i < size; printf("%d ", base[ i++ ]));  
    printf("\n");
}

int part(int *base, int left, int right) {
    int pivot = base[ right ];         /* 将最后一个元素作为基准, 也就是二分之一  */
    int tail  = left - 1, i;           /* 小于基准的子数组最后一个元素的索引, 即 -1  */
    for (i = left; i < right; ++i)     /* 从左往右遍历基准以外其它元素  */
        if (base[ i ] <= pivot)        /* 将小于等于基准元素放到前一个子数组末尾, 小于等于稳定  */
            swap(base, ++tail, i);     /* 先执行 ++ 防止 tail 索引越界  */
    swap(base, tail + 1, right);       /* 最后将基准放到前一个子数组后边, 剩下子数组即为大于基准子数组  */
    return tail + 1;                   /* 返回基准索引  */
}

void ordering(int *base, int left, int right) {
    if (left >= right) return ;
    int pivot_Index = part(base, left, right); /* 基准索引  */
    ordering(base, left, pivot_Index - 1);     /* 左边一半  */
    ordering(base, pivot_Index + 1, right);    /* 右边一半  */
}

int main( ) {
	int *gather = init(MAXN, 1, MAXN);
	print(gather, MAXN);
    ordering(gather, 0, MAXN - 1);
    print(gather, MAXN);
    destroy(gather);
    return 0;
}
