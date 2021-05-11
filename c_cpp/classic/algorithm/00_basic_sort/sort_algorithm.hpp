/*
 *hanxinle,2020-07-15,功能：不同排序算法的实现
 */
#ifndef BASIC_SORT
#define BASIC_SORT

 //#include <iostream>

 // Slow implement
 // template <typename T>
 // void insertionSort(T arr[], int n) {
 //    for (int i = 0; i < n; ++i) {
 //        for (int j = i; j > 0 && (arr[j] < arr[j - 1]); --j) {
 //            slow operation
 //            std::swap(arr[j], arr[j - 1]);
 //        }
 //    }
 //}

// O(n^2)
// 插入排序，第二层循环从后先前，判断值是否大于v，大于则与前面的值交换，
// 这样处理后，能把v放置在顺序上它能处于的最小的位置，
// 一定要注意i=1开始，不能跳步，不然理不清内循环的逻辑
template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T v = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > v; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = v;
    }
}

// O(n^2)
// 选择排序的逻辑是，从头到尾，在二层循环时找到最小的值的索引，
// 然后和外循环索引交换指向的值，这样每次外循环都把最小值置于当前i指向位置处

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        ::swap(arr[i], arr[minIdx]);
    }
}

// O(n^2)
// 
template <typename T>
void bubbleSort(T arr[], int n) {

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                ::swap(arr[j+ 1], arr[j]);
            }
        }
}
// O(n^2)
// 冒泡排序这种实现是麻烦的，简单好理解的实现是双层循环，每次双循环的结果都把最大值置于数组末尾
// 上面这种才是应该参考的
//template <typename T>
//void bubbleSort(T arr[], int n) {
//    int newn;
//    do {
//        newn = 0;
//        for (int i = 1; i < n; ++i) {
//            if (arr[i - 1] > arr[i]) {
//                ::swap(arr[i - 1], arr[i]);
//                newn = i;
//            }
//        }
//        n = newn;
//    } while (newn > 0);
//}

// O(n^3/2)
template <typename T>
void shellSort(T arr[], int n) {
    int h = 1;

    while (h < n / 3)
        h = h * 3 + 1;

    while (h >= 1) {
        for (int i = h; i < n; ++i) {
            T v = arr[i];
            int j;
            for (j = i; j >= h && arr[j - h] > v; j -= h)
                ::swap(arr[j], arr[j - h]);
            arr[j] = v;
        }
        h /= 3;
    }
}

#endif
