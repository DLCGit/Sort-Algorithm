/* 选择排序为不稳定排序: 平均、最好、最坏时间复杂度 O( n^2 ), 空间复杂度 O( 1 ) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 10
#define swap(base, j, i) { int tmp = 0; tmp = base[ i ]; base[ i ] = base[ j ]; base[ j ] = tmp; }

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
	for (i = 0; i < size - 1; ++i, get = i) { 
        for (j = i + 1; j < size; ++j) 
            if (base[ j ] < base[ get ]) get = j;
        if ( get != i ) swap( base, get, i ); 
    }
}

int main( ) {
	int *arr = init(MAXN, 1, MAXN), brr[ MAXN ], crr[ MAXN - 1 ];
	print(arr, MAXN);
    ordering(arr, MAXN);
    print(arr, MAXN);
    destroy(arr);
    return 0;
}
