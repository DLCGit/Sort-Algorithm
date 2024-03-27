/**
 * @file quick_sort.c
 * @author Shencheng Lin (deeplinshencheng@gmail.com)
 * @brief 快速排序算法的实现。
 * @version 2.2
 * @date 2024-03-27
 *
 * 快速排序为不稳定排序:
 * - 平均、最好时间复杂度: O(n log n)
 * - 最坏时间复杂度: O(n^2)
 * - 空间复杂度: O(log n)
 *
 * @copyright Copyright (c) 2024 Shencheng Lin. All rights reserved.
 * This code is for personal use only and may not be redistributed without
 * permission.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

#define SWAP(arr, i, j) \
  do {                  \
    int temp = arr[i];  \
    arr[i] = arr[j];    \
    arr[j] = temp;      \
  } while (0)

/**
 * @brief 释放内存。
 * @param array 要释放的数组指针。
 */
void FreeArray(int* array) { free(array); }

/**
 * @brief 初始化数组。
 * @param size 数组大小。
 * @param min_value 数组元素的最小值。
 * @param max_value 数组元素的最大值。
 * @return 初始化后的数组指针。
 */
int* InitArray(int size, int min_value, int max_value) {
  int* array = (int*)malloc(size * sizeof(int));
  srand((unsigned int)time(NULL));
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % (max_value - min_value + 1) + min_value;
  }
  return array;
}

/**
 * @brief 打印数组。
 * @param array 要打印的数组指针。
 * @param size 数组大小。
 */
void PrintArray(const int* array, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

/**
 * @brief 对数组进行分区操作。
 * @param array 要分区的数组指针。
 * @param left 分区的左边界。
 * @param right 分区的右边界。
 * @return 分区点的索引。
 */
int Partition(int* array, int left, int right) {
  int random_index = left + rand() % (right - left + 1);
  SWAP(array, random_index, right);

  int pivot = array[right];
  int i = left - 1;
  for (int j = left; j < right; ++j) {
    if (array[j] <= pivot) {
      ++i;
      SWAP(array, i, j);
    }
  }
  SWAP(array, i + 1, right);
  return i + 1;
}

/**
 * @brief 非递归的快速排序。
 * @param array 要排序的数组指针。
 * @param left 排序的左边界。
 * @param right 排序的右边界。
 */
void QuickSort(int* array, int left, int right) {
  int* stack = (int*)malloc((right - left + 1) * sizeof(int));
  int top = -1;
  stack[++top] = left;
  stack[++top] = right;

  while (top >= 0) {
    right = stack[top--];
    left = stack[top--];

    if (left < right) {
      int pivot_index = Partition(array, left, right);

      if (pivot_index - 1 > left) {
        stack[++top] = left;
        stack[++top] = pivot_index - 1;
      }

      if (pivot_index + 1 < right) {
        stack[++top] = pivot_index + 1;
        stack[++top] = right;
      }
    }
  }

  free(stack);
}

/**
 * @brief 主函数。
 * @return 返回值为 0，表示程序正常结束。
 */
int main() {
  int* array = InitArray(MAX_SIZE, 1, MAX_SIZE);
  PrintArray(array, MAX_SIZE);
  QuickSort(array, 0, MAX_SIZE - 1);
  PrintArray(array, MAX_SIZE);
  FreeArray(array);
  return 0;
}