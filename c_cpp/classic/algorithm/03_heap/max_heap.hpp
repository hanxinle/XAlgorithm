//#ifndef MAXHEAP
//#define MAXHEAP
//
//#include <algorithm>
//#include <cassert>
//#include <iostream>
//
//template <typename T> class MaxHeap {
//private:
//    T *data;
//    int count;
//    int capacity;
//
//    void shiftUp(int k) {
//        while (k > 1 && data[k / 2] < data[k]) {
//            std::swap(data[k / 2], data[k]);
//            k /= 2;
//        }
//    }
//
//    void shiftDown(int k) {
//        //左孩子不越界
//        while (2 * k <= count) {
//            //先搞定索引,，右孩子不越界，
//            int j = 2 * k;
//            if (j + 1 < count && data[j + 1] > data[j])
//                j++;
//            //根节点下移规则
//            if (data[k] >= data[j])
//                break;
//
//            std::swap(data[k], data[j]);
//
//            k = j;
//        }
//    }
//
//public:
//    //堆的索引是从1开始的，最大的索引是 count
//    MaxHeap(int capacity) {
//        data = new T[capacity + 1];
//        count = 0;
//        this->capacity = capacity;
//    }
//
//    // heapify
//    MaxHeap(T arr[], int n) {
//        data = new T[n + 1];
//        capacity = n;
//
//        for (int i = 0; i < n; ++i)
//            data[i + 1] = arr[i];
//
//        count = n;
//
//        for (int i = count / 2; i >= 1; i--)
//            shiftDown(i);
//    }
//
//    ~MaxHeap() {
//        delete[] data;
//    }
//
//    void insert(T v) {
//        assert(count + 1 <= capacity);
//        data[count + 1] = v;
//        shiftUp(count + 1);
//        count++;
//    }
//
//    T extractMax() {
//        assert(count > 0);
//        T ret = data[1];
//        std::swap(data[1], data[count]);
//        count--;
//        shiftDown(1);
//        return ret;
//    }
//
//    bool isEmpty() {
//        return count == 0;
//    }
//
//    T getMax() {
//        assert(count > 0);
//        return data[1];
//    }
//
//    int size() {
//        return count;
//    }
//};
//
//#endif // !MAXHEAP
