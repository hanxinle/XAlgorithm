#include <algorithm>
#include <ctime>
#include <iostream>


template <typename T> void insertionSort(T arr[], int l, int r) {
    // arr[l...r]
    for (int i = l + 1; i <= r; ++i) {
        T v = arr[i];
        int j;
        for (j = i; j > l && arr[j - 1] > v; --j)
            arr[j] = arr[j - 1];
        arr[j] = v;
    }
}
// arr[l...mid], arr[mid+1...r]
//下一级如何归并到上一级，需要借助额外内存空间完成
template <typename T> void __merge(T arr[], int l, int mid, int r) {
    T* aux = new T[r - l + 1];

    for (int i = l; i <= r; ++i) {
        aux[i - l] = arr[i];
    }

    int i = l, j = mid + 1;

    for (int k = l; k <= r; ++k) {
        //将辅助数组元素归并到原始数组
        //左部分都移动完毕
        if (i > mid) {
            arr[k] = aux[j - l];
            ++j;
        } else if (j > r) {//右部分都移动完毕
            arr[k] = aux[i - l];
            ++i;
        }

        //一般情况：将辅助数组元素归并到原始数组

        else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            ++i;
        } else {
            arr[k] = aux[j - l];
            ++j;
        }
    }
    delete[] aux;
}
// arr[l..r]
template <typename T>
void __mergeSort(T arr[], int l, int r) {
    /*
     *优化2：对递归结束进行优化
     *if (l >= r) return;
     */

     //退出递归的条件，足够小范围的数组排序

    if (r - l <= 15) {
        insertionSort<T>(arr, l, r);
        return;
    }

    int mid = (l + r) / 2;

    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);

    if (arr[mid] > arr[mid + 1])
        __merge(arr, l, mid, r);

    /*优化1在面，这是优化前代码
     *__mergeSort(arr, l, mid);
     *__mergeSort(arr, mid+1, r);
     *__merge(arr, l, mid, r);
     */
}

template <typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}

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

template <typename T>
void mergeSortBU(T arr[], int n) {
    for (int sz = 1; sz <= n; sz += sz) // sz 每个数组段落的 size
        for (int i = 0; i + sz < n;
             i += sz + sz) { // i 遍历分段数组的索引，每次前进两个sz.
                             // PS:前两个sz大小数组合并了
          // arr[i...i+sz-1],arr[i+sz...i+2*sz-1]
          // std::cout  << "sz = " << sz << " i = "<< i << std::endl;
          // std::cout  << "[" << i << "," << i + sz - 1 << "]" << " & "
          //    << "[" << i + sz <<","<< min((i + sz + sz - 1), n - 1) << "]" <<
          //    std::endl;
          // std::cout  << std::endl;
        __merge(arr, i, i + sz - 1, ::min((i + sz + sz - 1), n - 1));
    }
}

// return j,满足 arr[l...j-1] < arr[j], arr[j] < arr[j+1...r]
template <typename T>
int __partition(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];
    int j = l;

    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] < v) {
            ++j;
            swap(arr[j], arr[i]);
        }
    }

    std::swap(arr[l], arr[j]);
    return j;
}

template <typename T>
int __partition2(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];
    // arr[l+1...i) <= v, arr(j...r] >=v
    int i = l + 1, j = r;
    while (true) {
        while (i <= r && arr[i] < v)
            ++i;
        while (j >= l + 1 && arr[j] > v)
            --j;
        if (i > j)
            break;
        std::swap(arr[i], arr[j]);
        ++i;
        --j;
    }
    swap(arr[l], arr[j]);
    return j;
}

//对 arr[l...r] 快排
template <typename T> void __quickSort(T arr[], int l, int r) {
    // if (l >= r)
    //    return;

    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template <typename T> void quickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}

template <typename T> void __quickSort3Ways(T arr[], int l, int r) {

    // 对于小规模数组, 使用插入排序进行优化
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
    swap(arr[l], arr[rand() % (r - l + 1) + l]);

    T v = arr[l];

    int lt = l;     // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt...r] > v   设置这个值的目的是为了初始为空
    int i = l + 1; // arr[lt+1...i) == v
    while (i < gt) {
        if (arr[i] < v) {
            swap(arr[i], arr[lt + 1]);
            i++;
            lt++;
        } else if (arr[i] > v) {
            swap(arr[i], arr[gt - 1]);
            gt--;
        } else { // arr[i] == v
            i++;
        }
    }

    std::swap(arr[l], arr[lt]);

    __quickSort3Ways(arr, l, lt - 1);
    __quickSort3Ways(arr, gt, r);
}

template <typename T> void quickSort3Ways(T arr[], int n) {
    srand(time(NULL));
    __quickSort3Ways(arr, 0, n - 1);
}
