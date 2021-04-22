//#include "sort_algorithm.hpp"
//#include "test.hpp"
//#include <iostream>
//using namespace std;
//
//int main() {
//
//    int n = 10000;
//    int *arr = test::generateRandomArray<int>(n, 0, 30);
//    int *arr1 = test::copyArray(arr, n);
//    int *arr2 = test::copyArray(arr, n);
//    int *arr3 = test::copyArray(arr, n);
//    // algorithm::selectionSort<int> (arr, 5);
//    string sort_name = "insertion Sort";
//    string sort_name1 = "selection Sort";
//    string sort_name2 = "bubble Sort";
//    string sort_name3 = "shell Sort";
//
//    testSort(sort_name, insertionSort<int>, arr, n);
//    testSort(sort_name1, selectionSort<int>, arr1, n);
//    testSort(sort_name2, bubbleSort<int>, arr2, n);
//    testSort(sort_name3, shellSort<int>, arr3, n);
//    printArray<int>(arr, n);
//    printArray<int>(arr1, n);
//
//    delete[] arr;
//    delete[] arr1;
//    delete[] arr2;
//    delete[] arr3;
//
//    return 0;
//}
