/* 二分插入排序为不稳定排序: 平均、最坏时间复杂度 O( n^2 ),
 * 最好时间复杂度 O( n ), 空间复杂度 O( 1 )
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

void ordering( int *base, int n ) {
	int i, j;
    for (i = 1; n > i; ++i) {
        int get = base[ i ], left = 0, right = i - 1;
        while (right >= left) {
            int mid = (left + right) / 2; 
            if (get < base[ mid ]) right = mid - 1;
            else left  = mid + 1;
        }
        for (j = i - 1; left <= j; --j) base[ j + 1 ] = base[ j ];
        base[ left ] = get; 
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
