#include "advanced_sort_algorithm.hpp"
#include "heap_sort.hpp"
#include "index_heap.hpp"
#include "max_heap.hpp"
#include "test.hpp"
#include <string>
using namespace std;

// 使用最小索引堆进行堆排序, 来验证我们的最小索引堆的正确性
template <typename T> void heapSortUsingIndexMinHeap(T arr[], int n) {

    IndexMinHeap<T> indexMinHeap = IndexMinHeap<T>(n);
    for (int i = 0; i < n; i++)
        indexMinHeap.insert(i, arr[i]);

    for (int i = 0; i < n; i++)
        arr[i] = indexMinHeap.extractMin();
}

int main() {

    /***************************借助 heap 操作实现堆排序 start*********************************/
    // srand(time(nullptr));
    // int m = 1000;

    ////堆排序算法1，入堆、出堆
    // MaxHeap<int> heap1(m);
    // for (int i = 0; i < m; i++)
    //    heap1.insert(rand()%100);

    // while (!heap1.isEmpty())
    //    cout << heap1.extractMax() << " ";

    ////堆排序算法2,heapify、出堆
    // int n = 10000;
    // int* arr = test::generateRandomArray<int>(n, 0, 100);
    // MaxHeap<int> heap2(arr, n);
    // while (!heap2.isEmpty())
    //    cout << heap2.extractMax() << " ";

    /***************************借助 heap 操作实现堆排序 end*********************************/

    int n = 1000000;

    string name = "Heap Sort Using Index-Min-Heap";
    int* arr = generateRandomArray<int>(n, 0, n);
    testSort(name, heapSortUsingIndexMinHeap, arr, n);
    delete[] arr;

    // int n = 10000;
    // int* arr = test::generateRandomArray<int>(n, 0, 100);
    // int* arr1 = test::copyArray(arr, n);
    // int* arr2 = test::copyArray(arr, n);
    ////int* arr3 = test::copyArray(arr, n);

    // string sort_name  = "quick Sort";
    // string sort_name1 = "merge Sort";
    // string sort_name2 = "heap  Sort";
    ////string sort_name3 = "quickSort Sort";

    // test::testSort(sort_name,  algorithm::quickSort3Ways<int>, arr, n);
    // test::testSort(sort_name1, algorithm::mergeSortBU<int>, arr1, n);
    // test::testSort(sort_name2, heapSort<int>, arr2, n);

    // test::testSort(sort_name2, algorithm::bubbleSort<int>, arr2, n);

    // test::printArray<int>(arr, n);
    // test::printArray<int>(arr1, n);

    /*delete[] arr;*/
    // delete[] arr1;
    // delete[] arr2;

    return 0;
}
