//#include "advanced_sort_algorithm.hpp"
//#include "test.hpp"
//
//using namespace std;
//
//int main() {
//
//    int n = 10000;
//    int *arr = generateRandomArray<int>(n, 0, 100);
//    int *arr1 = copyArray(arr, n);
//    int *arr2 = copyArray(arr, n);
//    int *arr3 = copyArray(arr, n);
//
//    // algorithm::selectionSort<int> (arr, 5);
//    string sort_name = "insertion Sort";
//    string sort_name1 = "mergeSort Sort";
//    string sort_name2 = "bubble Sort";
//    string sort_name3 = "quickSort Sort";
//
//    // test::testSort(sort_name3, algorithm::quickSort3Ways<int>, arr2, n);
//    testSort(sort_name1, mergeSortBU<int>, arr, n);
//    // test::testSort(sort_name, algorithm::insertionSort<int>, arr, n);
//
//    // test::testSort(sort_name2, algorithm::bubbleSort<int>, arr2, n);
//
//    // test::printArray<int>(arr, n);
//    // test::printArray<int>(arr1, n);
//
//    delete[] arr;
//    delete[] arr1;
//    delete[] arr2;
//    delete[] arr3;
//
//    return 0;
//}
