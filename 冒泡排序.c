/* 冒泡排序为稳定排序: 平均、最坏时间复杂度 O( n^2 ),
 * 最好时间复杂度 O( n ), 空间复杂度 O( 1 )
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 10
#define swap(arr, j, i) { int tmp = 0; tmp = arr[ i ]; arr[ i ] = arr[ j ]; arr[ j ] = tmp; }

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

void ordering(int *base, int size) {
	int i, j, get;
    for (i = 0; i < size; get = i, ++i) 
		for (j = i + 1; j < size; j++) {
			if (base[ get ] > base[ j ]) swap(base, get, j);
			if (!get) break;
		}
}

int main( ) {
	int *gather = init(MAXN, 1, MAXN);
    print(gather, MAXN);
    ordering(gather, MAXN);
    print(gather, MAXN);
    destroy(gather);
    return 0;
}
