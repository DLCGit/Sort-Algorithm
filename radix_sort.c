/**
 * @file radix_sort.c
 * @author Shencheng Lin (deeplinshencheng@gmail.com)
 * @brief 基数排序算法的实现。
 * @version 2.0
 * @date 2024-03-27
 *
 * 基数排序为稳定排序:
 * - 平均、最好、最坏时间复杂度: O(d(n + r))
 * - 空间复杂度: O(n + r)
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
 * @brief 计数排序。
 * @param arr 待排数组指针。
 * @param output 排序后数组指针。
 * @param count 保存 0 ~ max 中每个值出现的次数的数组指针。
 * @param digit 保存从 0 ~ max 中取出的值的数组指针。
 * @param max 数组元素的最大值。
 * @param size 数组大小。
 */
void CountSort(int* arr, int* output, int* count, int* digit, int max,
               int size) {
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }
  for (int i = 0; i < size; ++i) {
    count[digit[i]]++;
  }
  for (int i = 1; i <= max; ++i) {
    count[i] += count[i - 1];
  }
  for (int i = size - 1; i >= 0; --i) {
    output[count[digit[i]] - 1] = arr[i];
    count[digit[i]]--;
  }
  for (int i = 0; i < size; ++i) {
    arr[i] = output[i];
  }
}

/**
 * @brief 基数排序。
 * @param arr 待排数组指针。
 * @param output 排序后数组指针。
 * @param count 保存 0 ~ 9 中每个值出现的次数的数组指针。
 * @param digit 保存每次遍历该位上的数的数组指针。
 * @param size 数组大小。
 * @param numDigits 元素位数。
 */
void RadixSort(int* arr, int* output, int* count, int* digit, int size,
               int numDigits) {
  int base = 1;
  for (int i = 1; i <= numDigits; ++i) {
    for (int j = 0; j < size; ++j) {
      digit[j] = (arr[j] / base) % 10;
    }
    CountSort(arr, output, count, digit, 9, size);
    base *= 10;
  }
}

/**
 * @brief 主函数。
 * @return 返回值为 0，表示程序正常结束。
 */
int main() {
  int* arr = Init(MAX_SIZE, 1, MAX_SIZE);
  int output[MAX_SIZE];
  int digit[MAX_SIZE];
  int count[MAX_SIZE];
  Print(arr, MAX_SIZE);
  RadixSort(arr, output, count, digit, MAX_SIZE, 6);
  Print(arr, MAX_SIZE);
  Destroy(arr);
  return 0;
}