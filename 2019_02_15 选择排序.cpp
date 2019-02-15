
/* 选择排序为不稳定排序: 平均、最好、最坏时间复杂度 O( n^2 ), 空间复杂度 O( 1 ) */

/* -----------------------------------------------------------  */
/* 相关接口  */
#include <stdio.h>
#include <stdlib.h> 
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 相关特殊宏  */
#define MAXSIZE 10

#define swap( arr, j, i ) { \
int tmp = 0; tmp = arr[ i ]; \
arr[ i ] = arr[ j ]; arr[ j ] = tmp; }
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 全局  */
int arr[ MAXSIZE ] = { 8, 5, 2, 6, 9, 3, 1, 4, 0, 7 };
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 函数原型  */
void BeforeOrdering( int *arr, int n );            /* 排序前    */
void SelectionSort( int *arr, int n );             /* 选择排序  */
void AfterOrdering( int *arr, int n );             /* 排序后    */
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 主测试  */
int main( int argc, char **argv )
{
	BeforeOrdering( arr, sizeof( arr ) / sizeof( int ) );
    SelectionSort( arr, sizeof( arr ) / sizeof( int ) );
    AfterOrdering( arr, sizeof( arr ) / sizeof( int ) );
    
    system("pause");
    return 0;
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 排序前  */
void BeforeOrdering( int *arr, int n ) {
	printf( "排序前: " );
    for ( int i = 0; n > i; ++i )
        printf( "%d ", arr[ i ] );
    putchar( '\n' );
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 选择排序  */
void SelectionSort( int *arr, int n ) {
    for ( int i = 0; n - 1 > i; ++i ) {   /* i 为已排序序列的末尾  */
        int min = i;                      /* 每次遍历都记录元素的位置  */
        for ( int j = i + 1; n > j; ++j ) /* 未排序序列  */
            if ( arr[ j ] < arr[ min ] )  /* 找出未排序序列中的最小值（改变符号 == 升序、降序）  */
                min = j;
        if ( min != i )
            swap( arr, min, i );          /* 放到已排序序列的末尾  */
    }
}
/* -----------------------------------------------------------  */


/* -----------------------------------------------------------  */
/* 排序后  */
void AfterOrdering( int *arr, int n ) {
	printf( "排序后: " );
    for ( int i = 0; n > i; ++i )
        printf( "%d ", arr[ i ] );
    putchar( '\n' );
}
/* -----------------------------------------------------------  */

