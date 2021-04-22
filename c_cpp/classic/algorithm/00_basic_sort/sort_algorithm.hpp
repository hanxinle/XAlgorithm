///*
// *hanxinle,2020-07-15,功能：不同排序算法的实现
// */
//#ifndef BASIC_SORT
//#define BASIC_SORT
//
// //#include <iostream>
//
// // Slow implement
// // template <typename T>
// // void insertionSort(T arr[], int n) {
// //    for (int i = 0; i < n; ++i) {
// //        for (int j = i; j > 0 && (arr[j] < arr[j - 1]); --j) {
// //            slow operation
// //            std::swap(arr[j], arr[j - 1]);
// //        }
// //    }
// //}
//
// // O(n^2)
//template <typename T> void insertionSort(T arr[], int n) {
//    for (int i = 1; i < n; ++i) {
//        T v = arr[i];
//        int j;
//        for (j = i; j > 0 && arr[j - 1] > v; --j) {
//            arr[j] = arr[j - 1];
//        }
//        arr[j] = v;
//    }
//}
//
//// O(n^2)
//template <typename T> void selectionSort(T arr[], int n) {
//    for (int i = 0; i < n; ++i) {
//        int minIdx = i;
//        for (int j = i + 1; j < n; ++j) {
//            if (arr[j] < arr[minIdx]) {
//                minIdx = j;
//            }
//        }
//        std::swap(arr[i], arr[minIdx]);
//    }
//}
//
//// O(n^2)
//template <typename T> void bubbleSort(T arr[], int n) {
//    int newn;
//    do {
//        newn = 0;
//        for (int i = 1; i < n; ++i) {
//            if (arr[i - 1] > arr[i]) {
//                std::swap(arr[i - 1], arr[i]);
//                newn = i;
//            }
//        }
//        n = newn;
//    } while (newn > 0);
//}
//
//// O(n^3/2)
//template <typename T> void shellSort(T arr[], int n) {
//    int h = 1;
//
//    while (h < n / 3)
//        h = h * 3 + 1;
//
//    while (h >= 1) {
//        for (int i = h; i < n; ++i) {
//            T v = arr[i];
//            int j;
//            for (j = i; j >= h && arr[j - h] > v; j -= h)
//                std::swap(arr[j], arr[j - h]);
//            arr[j] = v;
//        }
//        h /= 3;
//    }
//}
//
//#endif
