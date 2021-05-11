#include "max_heap.hpp"

template <typename T> void heapSort1(T arr[], int n) {
    MaxHeap<T> maxheap(n);
    for (int i = 0; i < n; i++)
        maxheap.insert(i);

    for (int i = n - 1; i >= 0; i--)
        arr[i] = maxheap.extractMax();
}

template <typename T> void heapSort2(T arr[], int n) {
    MaxHeap<T> maxheap(arr, n);
    for (int i = n - 1; i >= 0; i--)
        arr[i] = maxheap.extractMax();
}

template <typename T> void __shiftDown(T arr[], int n, int k) {
    // 左孩子不越界
    while (2 * k + 1 < n) {
        //先搞定索引,，右孩子不越界，
        int j = 2 * k + 1;
        if (j + 1 < n && arr[j + 1] > arr[j])
            j += 1;
        //根节点下移规则
        if (arr[k] >= arr[j])
            break;

        std::swap(arr[k], arr[j]);

        k = j;
    }
}
template <typename T>
void heapSort(T arr[], int n) {
    for (int i = (n - 1) / 2; i >= 0; i--)
        __shiftDown(arr, n, i);

    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}
