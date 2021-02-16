/**
  * 题目2：已有1个库函数query，实现一个本地缓存函数 query_from_cache，
  * n秒内调用相同的key，返回query上一次的内容。
  * 这个题目和 leetcode 146 LRU Cache 类似
  * Time Complexity: Cache(int): O(1)
  *                  putInCache: O(1)
  * (query_from_cache)QueryFromCache: O(1)
  * Space Complexity: O(n)
  */
#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <cassert>

using namespace std;

class Cache {
private:
    class Node {
    public:
        int key, val;
        Node * prev, *next;
        Node(int k, int v) :key(k), val(v), prev(nullptr), next(nullptr) {
        }
    };

    int capacity;
    unordered_map<int, Node*> search_in_cache;

    Node * dummyHead;
    Node * tail;

public:
    Cache(int cap = 3) :capacity(cap) {
        dummyHead = new Node(-1, -1);
        tail = new Node(-1, -1);

        dummyHead->next = tail;
        tail->prev = dummyHead;
    }
    // 释放双向链表
    ~Cache() {
        Node * cur = dummyHead;
        while (cur != nullptr) {
            Node * p = cur->next;
            delete cur;
            cur = nullptr;
            cur = p;
        }
    }

    void putInCache(int key, int value) {
        if (search_in_cache.count(key)) {
            search_in_cache[key]->val = value;
            moveToHead(search_in_cache[key]);
            return;
        }

        search_in_cache[key] = new Node(key, value);
        addFirst(search_in_cache[key]);

        if (search_in_cache.size() > capacity) {
            int del_key = removeLast();
            search_in_cache.erase(del_key);
        }
    }
    // query_from_cache
    int QueryFromCache(int key) {
        if (search_in_cache.count(key)) {
            moveToHead(search_in_cache[key]);
            return dummyHead->next->val;
        }

        return -1;
    }
private:
    // 链表中节点 node 移动到表头（dummyHead下一个）
    void moveToHead(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->prev = node->next = NULL;
        addFirst(node);
    }

    // 添加节点 node 到表头
    void addFirst(Node* node) {

        node->next = dummyHead->next;
        node->next->prev = node;

        node->prev = dummyHead;
        dummyHead->next = node;
    }

    // 移除尾部节点（非tail）
    int removeLast() {
        if (tail->prev != dummyHead) {
            Node* del_node = tail->prev;

            tail->prev = tail->prev->prev;
            tail->prev->next = tail;
            int res = del_node->key;

            delete del_node;
            del_node = nullptr;

            return res;
        }
        return -1;
    }
};

int main() {
    Cache cache(2);
    cache.putInCache(1, 1);
    cache.putInCache(2, 2);
    cout << cache.QueryFromCache(1) << endl;  // 1
    cache.putInCache(3, 3);
    cout << cache.QueryFromCache(2) << endl;  //-1
    cache.putInCache(4, 4);
    cout << cache.QueryFromCache(1) << endl;  //-1
    cout << cache.QueryFromCache(3) << endl;  // 3
    cout << cache.QueryFromCache(4) << endl;  // 4

    return 0;

}