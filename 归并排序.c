/* 归并排序为稳定排序: 平均、最好、最坏时间复杂度 O( n ),
 * 空间复杂度 O( nlog^2 n )
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXN 10

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

/* 合并两个已排好序的子数组索引 A[ left...mid ] 与 A[ mid + 1...right ]  */
void Merge(int *base, int mid, int left, int right) {
    int i = left, j = mid + 1, k; 
	int len = right - left + 1; 
	int index = 0; 
    int *iTemp = (int *)malloc(len * sizeof(int));
    while (i <= mid && j <= right) iTemp[ index++ ] = (base[ i ] <= base[ j ] ? base[ i++ ] : base[ j++ ]);
    while (i <= mid) iTemp[ index++ ] = base[ i++ ];  
    while (j <= right) iTemp[ index++ ] = base[ j++ ];
    for (k = 0; k < len; ++k) base[ left++ ] = iTemp[ k ];
}

/* 递归归并  */
void MergeSortRecursion(int *base, int left, int right) {
    int mid = (left + right) / 2;  
    if (left == right) return ;
    MergeSortRecursion(base, left, mid);
    MergeSortRecursion(base, mid + 1, right);
    Merge(base, mid, left, right); 
}

/* 迭代归并（非递归） */
void MergeSortIteration(int *arr, int size) {
    int left = 0, mid = 0, right = 0, i;
    for (i = 1; i < size; left = 0, i *= 2) { 
        while (left + i <= size) { 
            mid = left + i - 1;
            right = mid + i < size ? mid + i : size - 1; 
            Merge(arr, mid, left, right);
            left = right + 1; 
        }
    }
}

int main( ) {
	int *arr1 = init(MAXN, 1, MAXN), *arr2 = init(MAXN, 1, MAXN);
    printf("递归归并排序前:     "); 
	print(arr1, MAXN); 
    MergeSortRecursion(arr1, 0, MAXN - 1); 
    
    printf("非递归归并排序前:   "); 
	print(arr2, MAXN); 
    MergeSortIteration(arr2, MAXN); 
    
    printf("递归归并排序结果:   "); print(arr1, MAXN); 
    printf("非递归归并排序结果: "); print(arr2, MAXN); 
    destroy(arr1), destroy(arr2);
    return 0;
}
