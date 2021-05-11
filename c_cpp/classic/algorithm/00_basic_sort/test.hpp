/*
 *hanxinle,2020-07-15,功能：排序算法测试
 */
#ifndef TEST
#define TEST

#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>

template <typename T> T* generateRandomArray(int n, T rangeL, T rangeR) {
    T* arr = new T[n];
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }
    return arr;
}

template <typename T> T* generateNearlySortedArray(int n, int swapTimes) {
    T* arr = new T[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }

    srand(time(nullptr));
    for (int i = 0; i < swapTimes; ++i) {
        int x = rand() % n;
        int y = rand() % n;
        std::swap(arr[x], arr[y]);
    }
    return arr;
}

template <typename T> void printArray(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T> bool isSorted(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}

template <typename T>
void testSort(const std::string& sortName, void(*sort)(T[], int), T arr[],
              int n) {
    clock_t start_time = clock();
    sort(arr, n);
    clock_t end_time = clock();

    assert(isSorted(arr, n));
    std::cout << sortName << ":" << double(end_time - start_time) / CLOCKS_PER_SEC
        << "s" << std::endl;
}

template <typename T> T* copyArray(T src[], int n) {
    T* arr = new T[n];
    std::copy(src, src + n, arr);
    return arr;
}

#endif // !TEST
