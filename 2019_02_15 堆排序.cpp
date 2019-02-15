
/* ������Ϊ�ȶ�����:  ʱ�临�Ӷ� O( n ), �ռ临�Ӷ� O( 1 ) */

/* -----------------------------------------------------------  */
/* ��ؽӿ�  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* ��������  */
#define MAXSIZE 10
#define RANDOMMAXSIZE 100

#define swap( j, i ) { \
int tmp = 0; tmp = i; \
i = j; j = tmp; }
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* ȫ��  */
/*extern*/ int heap[ MAXSIZE + 1 ] = { -1 }; /* ������  */
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* ����ԭ��  */
void createHeap( int *data/*, int *heap*/ ); /* ������  */
void establishHeapTree();                    /* ������  */
void beforeOrdering( void );                 /* ����ǰ����  */
void isSorted( int *data );                  /* ������  */
void heapSort( int *data );                  /* ������� */
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* ������  */
int main( int argc ,char **argv ) {
	beforeOrdering();
	establishHeapTree();
	heapSort( heap );
	system("pause");
	return 0;
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* ������  */
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
/* ������  */
void establishHeapTree() {
	createHeap( heap );
	printf( "\n��������: " );
	for (int i = 1; MAXSIZE >= i; ++i )
		printf( "%d \t", heap[ i ] );
	putchar( '\n' );
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* ����ǰ����  */
void beforeOrdering( void ) {
	srand( ( unsigned int )time( NULL ) );
	printf( "����ǰ:   " );
	for ( int i = 1; MAXSIZE >= i; ++i ) {
		heap[ i ] = rand() % RANDOMMAXSIZE;
		printf( "%d \t", heap[ i ] );
	}
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* ������  */
void isSorted( int *data ) {
	printf( "\n������: " );
	for ( int i = MAXSIZE; 0 < i; --i )
		printf( "%d\t", data[ i ] );
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* ������� */
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

