//using namespace std;
//
//#include <iostream>
//#include <queue>
//#include <vector>
//
//class MedianOfAStream {
//public:
//    // 第一部分数字，放在最大堆 max
//    // 第二部分数字，放在最小堆 min
//    priority_queue<int> maxHeap;
//    priority_queue<int, vector<int>, greater<int>> minHeap;
//
//    virtual void insertNum(int num) {
//        // max 为空或者值小于 max 顶部元素，加入 max
//        if (maxHeap.empty() || maxHeap.top() >= num) {
//            maxHeap.push(num);
//        }
//        else {
//            minHeap.push(num);
//        }
//
//        // 平衡两个堆，max 最多比 min 多一个元素
//        // max 元素数量不能小于 min
//        if (maxHeap.size() > minHeap.size() + 1) {
//            minHeap.push(maxHeap.top());
//            maxHeap.pop();
//        }
//        else if (maxHeap.size() < minHeap.size()) {
//            maxHeap.push(minHeap.top());
//            minHeap.pop();
//        }
//    }
//
//    virtual double findMedian() {
//        // 偶数个元素返回两个堆的均值
//        if (maxHeap.size() == minHeap.size()) {
//
//            return maxHeap.top() / 2.0 + minHeap.top() / 2.0;
//        }
//        // 奇数个元素返回 max 顶元素
//        return maxHeap.top();
//    }
//};
//
//int main(int argc, char *argv[]) {
//    MedianOfAStream medianOfAStream;
//    medianOfAStream.insertNum(3);
//    medianOfAStream.insertNum(1);
//    cout << "The median is: " << medianOfAStream.findMedian() << endl;
//    medianOfAStream.insertNum(5);
//    cout << "The median is: " << medianOfAStream.findMedian() << endl;
//    medianOfAStream.insertNum(4);
//    cout << "The median is: " << medianOfAStream.findMedian() << endl;
//}