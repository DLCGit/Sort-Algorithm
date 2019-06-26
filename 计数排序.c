/*
* 计数排序为稳定排序: 平均、最好、最坏时间复杂度 O( d( n + k ) ),
 * 空间复杂度 O( n + k )
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

void print( int *arr, int n ) {
    int i;
    for (i = 0; i < MAXN; printf("%d ", arr[ i++ ])); 
    printf("\n");
}

/* ( 计数排序 )（ arr[ 0...len ] ）
 * arr（ 待排数组, 每一个元素的每一位数不能超过 0 - n 之间 ）
 * brr（ 排序后数组 ）
 * crr（ 保存 0 ~ n 中每个值出现的次数 ）
 * len（ 数组长度 ）
 */
void ordering(int *arr, int *brr, int *crr, int len, int n) {
	int i; 
    for (i = 0; i <= n; ++i)       crr[ i ] = 0;
    for (i = 0; i < len; ++i)      ++crr[ arr[ i ] ];
    for (i = 1; i <= n; ++i)       crr[ i ] += crr[ i - 1 ];
    for (i = len - 1; i >= 0; --i) brr[ crr[ arr[ i ] ] - 1 ] = arr[ i ], --crr[ arr[ i ] ]; 
}

int main( ) {
	int *arr = init(MAXN, 1, MAXN - 1), brr[ MAXN ], crr[ MAXN - 1 ];
    print(arr, MAXN);
    ordering(arr, brr, crr, MAXN, MAXN - 1);
    print(brr, MAXN);
    return 0;
}
