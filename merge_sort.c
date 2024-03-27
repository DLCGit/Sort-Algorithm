/**
 * @file merge_sort.c
 * @author Shencheng Lin (deeplinshencheng@gmail.com)
 * @brief 归并排序算法的实现。
 * @version 2.0
 * @date 2024-03-27
 *
 * 归并排序为稳定排序:
 * - 平均、最好、最坏时间复杂度: O(n log n)
 * - 空间复杂度: O(n)
 *
 * @copyright Copyright (c) 2024 Shencheng Lin. All rights reserved.
 * This code is for personal use only and may not be redistributed without
 * permission.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

/**
 * @brief 释放内存。
 * @param arr 要释放的数组指针。
 */
void Destroy(int* arr) { free(arr); }

/**
 * @brief 初始化数组。
 * @param size 数组大小。
 * @param min 数组元素的最小值。
 * @param max 数组元素的最大值。
 * @return 初始化后的数组指针。
 */
int* Init(int size, int min, int max) {
  int* arr = (int*)malloc(size * sizeof(int));
  srand((unsigned int)time(NULL));
  for (int i = 0; i < size; ++i) {
    arr[i] = rand() % (max - min + 1) + min;
  }
  return arr;
}

/**
 * @brief 打印数组。
 * @param arr 要打印的数组指针。
 * @param size 数组大小。
 */
void Print(const int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/**
 * @brief 合并两个已排好序的子数组。
 * @param arr 要合并的数组指针。
 * @param left 左子数组的起始索引。
 * @param mid 左子数组的结束索引。
 * @param right 右子数组的结束索引。
 */
void Merge(int* arr, int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = 0;
  int len = right - left + 1;
  int* temp = (int*)malloc(len * sizeof(int));

  while (i <= mid && j <= right) {
    temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
  }
  while (i <= mid) {
    temp[k++] = arr[i++];
  }
  while (j <= right) {
    temp[k++] = arr[j++];
  }
  for (k = 0; k < len; ++k) {
    arr[left + k] = temp[k];
  }

  free(temp);
}

/**
 * @brief 递归实现归并排序。
 * @param arr 要排序的数组指针。
 * @param left 要排序的数组的起始索引。
 * @param right 要排序的数组的结束索引。
 */
void MergeSortRecursive(int* arr, int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = left + (right - left) / 2;
  MergeSortRecursive(arr, left, mid);
  MergeSortRecursive(arr, mid + 1, right);
  Merge(arr, left, mid, right);
}

/**
 * @brief 迭代实现归并排序。
 * @param arr 要排序的数组指针。
 * @param size 数组大小。
 */
void MergeSortIterative(int* arr, int size) {
  for (int step = 1; step < size; step *= 2) {
    for (int left = 0; left < size - step; left += 2 * step) {
      int mid = left + step - 1;
      int right =
          (left + 2 * step - 1 < size - 1) ? left + 2 * step - 1 : size - 1;
      Merge(arr, left, mid, right);
    }
  }
}

/**
 * @brief 主函数。
 * @return 返回值为 0，表示程序正常结束。
 */
int main() {
  int* arr1 = Init(MAX_SIZE, 1, MAX_SIZE);
  int* arr2 = Init(MAX_SIZE, 1, MAX_SIZE);

  printf("递归归并排序前:     ");
  Print(arr1, MAX_SIZE);
  MergeSortRecursive(arr1, 0, MAX_SIZE - 1);

  printf("非递归归并排序前:   ");
  Print(arr2, MAX_SIZE);
  MergeSortIterative(arr2, MAX_SIZE);

  printf("递归归并排序结果:   ");
  Print(arr1, MAX_SIZE);
  printf("非递归归并排序结果: ");
  Print(arr2, MAX_SIZE);

  Destroy(arr1);
  Destroy(arr2);
  return 0;
}