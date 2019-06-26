/* 基数排序为稳定排序: 平均、最好、最坏时间复杂度 O( d( n + r ) ),
 * 空间复杂度 O( n + r )
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

/* ( 计数排序 )
 * arr（ 待排数组 ）;
 * brr（ 排序后数组 ）;
 * crr（ 保存 0 ~ n 中每个值出现的次数 ）
 * fet（ 保存从 0 ~ n中取出的值 ）
 * len（ 数组长度 ）
 */
void count_sort(int *arr, int *brr, int *crr, int *fet, int n, int len) {
	int i;
    for (i = 0; i <= n; ++i)       crr[ i ] = 0;
    for (i = 0; i < len; ++i)      crr[ fet[ i ] ]++;
    for (i = 1; i <= n; ++i)       crr[ i ] += crr[ i - 1 ];
    for (i = len - 1; i >= 0; --i) brr[ crr[ fet[ i ] ] - 1 ] = arr[ i ], crr[ fet[ i ] ]--; 
    for (i = 0; i < len; ++i)      arr[ i ] = brr[ i ];
}

/* 基数排序, 参数 dig 为元素位数  */
void basic_sort(int *arr, int *brr, int *crr, int *fet, int n, int len, int dig) {
	int i, j, val = 1;
    for (i = 1; i <= dig; ++i) {
    	for (j = 0; j < len; ++j) 
			fet[ j ] = ( arr[ j ] / val ) % 10;
		count_sort( arr, brr, crr, fet, n, len ), val *= 10;
	}
}

int main( ) {
	int *gather = init(MAXN, 1, MAXN);
	int brr[ MAXN ]; /* 保存每次计数排序后结果            */
    int fet[ MAXN ]; /* 保存每次遍历该位上的数            */
    int crr[ MAXN ]; /* 保存每次遍历该位上的数出现的次数  */
    print(gather, MAXN);
    basic_sort(gather, brr, crr, fet, MAXN - 1, MAXN, 6);
    print(gather, MAXN);
    destroy(gather);
    return 0;
}
