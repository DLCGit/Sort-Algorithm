
/* 堆排序为稳定排序:  时间复杂度 O( n ), 空间复杂度 O( 1 ) */

/* -----------------------------------------------------------  */
/* 相关接口  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 相关特殊宏  */
#define MAXSIZE 10
#define RANDOMMAXSIZE 100

#define swap( j, i ) { \
int tmp = 0; tmp = i; \
i = j; j = tmp; }
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 全局  */
/*extern*/ int heap[ MAXSIZE + 1 ] = { -1 }; /* 堆数组  */
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 函数原型  */
void createHeap( int *data/*, int *heap*/ ); /* 创建堆  */
void establishHeapTree();                    /* 建立堆  */
void beforeOrdering( void );                 /* 排序前数据  */
void isSorted( int *data );                  /* 排序中  */
void heapSort( int *data );                  /* 排序过程 */
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 主测试  */
int main( int argc ,char **argv ) {
	beforeOrdering();
	establishHeapTree();
	heapSort( heap );
	system("pause");
	return 0;
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 创建堆  */
void createHeap( int *data/*, int *heap*/ ) {
	for ( int i = 1; MAXSIZE >= i; ++i )  {
		heap[ i ] = data[ i ];

		int s = i, p = i / 2;
		while ( ( 2 <= s ) and ( heap[ s ] < heap[ p ] ) ) {
			swap( heap[ p ], heap[ s ] );
			s = p;
			p = s / 2;
		}
	}

	for ( int i = 0; MAXSIZE >= i; ++i )
		data[ i ] = heap[ i ];
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 建立堆  */
void establishHeapTree() {
	createHeap( heap );
	printf( "\n建立树堆: " );
	for (int i = 1; MAXSIZE >= i; ++i )
		printf( "%d \t", heap[ i ] );
	putchar( '\n' );
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 排序前数据  */
void beforeOrdering( void ) {
	srand( ( unsigned int )time( NULL ) );
	printf( "排序前:   " );
	for ( int i = 1; MAXSIZE >= i; ++i ) {
		heap[ i ] = rand() % RANDOMMAXSIZE;
		printf( "%d \t", heap[ i ] );
	}
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 排序中  */
void isSorted( int *data ) {
	printf( "\n排序中: " );
	for ( int i = MAXSIZE; 0 < i; --i )
		printf( "%d\t", data[ i ] );
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 排序过程 */
void heapSort( int *data ) {
	int m = MAXSIZE;
	while ( 1 <= m ) {
		swap( data[ 1 ], data[ m ] );
		m--;

		int p = 1, s = 2 * p;
		while ( m >= s ) {
			if ( ( m > s ) and ( data[ s ] > data[ 1 + s ] ) )
				s++;
			if ( data[ s ] >= data[ p ] )
				break;

			swap( data[ p ], data[ s ] );
			p = s;
			s = 2 * p;
		}
		isSorted( data );
	}
	putchar( '\n' );
}
/* -----------------------------------------------------------  */

