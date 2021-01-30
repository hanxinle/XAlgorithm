/**
  * 题目1：用熟悉的语言写一个函数，把字符串里面的空格全部去掉，
  * 并返回删除的空格的个数，不允许开辟空间，只能申请简单类型的自动变量
  * 要求时间复杂度 O(n)
  * Time Complexity : O(n)
  * Space Complexity : O(1)
  */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    static int DeleteWhiteSpace(string &s) {
        int res = 0;

        if (s.size() <= 0)
            return 0;

        auto st = s.begin();
        auto cur = st;

        while (cur != s.end()) {
            if (isspace(*cur)) {
                res++;
                cur++;
            }
            else {
                *st = *cur;
                cur++;
                st++;
            }
        }
        s.erase(st, s.end());
        return res;
    }
};

void test(string & test_string) {
    cout << "original input s=" << "\"" << test_string << "\"" << endl;
    cout << "count of WhiteSpace(s) is " << Solution::DeleteWhiteSpace(test_string) << endl;
    cout << "after delete white space(s) s=" << "\"" << test_string << "\"" << endl;
}


int main() {
    string s1 = " a b c  ";
    string s2 = " a b  c";
    string s3 = "";
    test(s1);
    test(s2);
    test(s3);

    return 0;
}

//--------------------------------------------------------------------
// 这个是我视频面试的时的解法，时间复杂度时O(n),使用一个辅助的字符串拼接
// 去除空格的结果，空间复杂度是O(n).
//class Solution {
//public:
//    static int DeleteWhiteSpace(string &s) {
//        int res = 0;
//        string ss = "";
//        // 输入检查
//        if (s.size() <= 0)
//            return 0;
//        // 主要功能
//        for (auto it = s.begin(); it != s.end(); it++) {
//            if (isspace(*it))
//                res++;
//            else
//                ss += *it;
//        }
//        s = ss;
//        cout << "In DelSpace s = " << s << endl;
//        return res;
//    }
//
//};
//--------------------------------------------------------------------