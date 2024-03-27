/**
 * @file heap_sort.c
 * @author Shencheng Lin (deeplinshencheng@gmail.com)
 * @brief 堆排序算法的实现。
 * @version 2.0
 * @date 2024-03-27
 *
 * 堆排序为不稳定排序:
 * - 平均、最坏、最好时间复杂度: O(n log n)
 * - 空间复杂度: O(1)
 *
 * @copyright Copyright (c) 2024 Shencheng Lin. All rights reserved.
 * This code is for personal use only and may not be redistributed without
 * permission.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define MAX_VALUE 100

#define SWAP(a, b) \
  do {             \
    int tmp = a;   \
    a = b;         \
    b = tmp;       \
  } while (0)

/**
 * @brief 初始化数组。
 * @param arr 要初始化的数组指针。
 */
void Init(int* arr) {
  srand((unsigned int)time(NULL));
  printf("排序前: ");
  for (int i = 1; i <= MAX_SIZE; ++i) {
    arr[i] = rand() % MAX_VALUE;
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/**
 * @brief 打印数组。
 * @param arr 要打印的数组指针。
 * @param size 数组大小。
 */
void Print(const int* arr, int size) {
  for (int i = 1; i <= size; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/**
 * @brief 调整堆。
 * @param arr 要调整的数组指针。
 * @param size 数组大小。
 * @param parent 要调整的父节点索引。
 */
void Heapify(int* arr, int size, int parent) {
  int largest = parent;
  int left = 2 * parent;
  int right = 2 * parent + 1;

  if (left <= size && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right <= size && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != parent) {
    SWAP(arr[parent], arr[largest]);
    Heapify(arr, size, largest);
  }
}

/**
 * @brief 建立堆。
 * @param arr 要建立堆的数组指针。
 */
void BuildHeap(int* arr) {
  for (int i = MAX_SIZE / 2; i >= 1; --i) {
    Heapify(arr, MAX_SIZE, i);
  }
  printf("建立树堆: ");
  Print(arr, MAX_SIZE);
}

/**
 * @brief 堆排序。
 * @param arr 要排序的数组指针。
 */
void HeapSort(int* arr) {
  BuildHeap(arr);
  for (int i = MAX_SIZE; i >= 2; --i) {
    SWAP(arr[1], arr[i]);
    Heapify(arr, i - 1, 1);
    Print(arr, MAX_SIZE);
  }
  printf("\n");
}

/**
 * @brief 主函数。
 * @return 返回值为 0，表示程序正常结束。
 */
int main() {
  int heap[MAX_SIZE + 1] = {-1};
  Init(heap);
  HeapSort(heap);
  return 0;
}