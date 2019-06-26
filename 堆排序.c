/* 堆排序为不稳定排序: 平均、最坏、最好时间复杂度 O( n ),
 * 空间复杂度 O( 1 )
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 10
#define RANDOMMAXN 100
#define swap(j, i) { int tmp = 0; tmp = i; i = j; j = tmp; }

void init(int *base) {
	srand(time(NULL));
	int i;
    for (printf("排序前: "), i = 1; i <= MAXN; base[ i ] = rand( ) % RANDOMMAXN, printf("%d ", base[ i ]), ++i); 
    printf("\n");
}

void print(int *base, int size) {
    int i;
    for (i = size; i > 0; printf("%d ", base[ i-- ]));  
    printf("\n");
}

/* 创建堆 */
void create_heap(int *base, int *heap) {
	int i;
    for (i = 1; i <= MAXN; heap[ i ] = base[ i ], ++i) {
		int s = i, p = i / 2;
		while (s >= 2 && heap[ s ] < heap[ p ]) {
			swap(heap[ p ], heap[ s ]); 
			s = p, p = s / 2;
		}
    }
    for (i = 0; i <= MAXN; base[ i ] = heap[ i ], ++i); 
}

/* 建立堆  */
void build_heap(int *base) {
    create_heap(base, base);
    int i;
    for (printf("建立树堆: "), i = 1;  i <= MAXN; printf("%d ", base[ i++ ])); 
    printf("\n");
}

/* 堆排 */
void ordering(int *base) {
    int m = MAXN;
    while (m >= 1) {
        swap( base[ 1 ], base[ m ] );
		m--;
		int p = 1, s = 2 * p;
		while (m >= s) {
		    if (m > s && base[ s ] > base[ s + 1 ]) s++;
		    if (base[ s ] >= base[ p ]) break;
		    swap(base[ p ], base[ s ]);
		    p = s, s = 2 * p;
		}
		print(base, MAXN);
    }
    printf("\n");
}

int main( ) {
	int heap[ MAXN + 1 ] = { -1 }; 
	init(heap);
    build_heap(heap);
    ordering(heap);
    return 0;
}
