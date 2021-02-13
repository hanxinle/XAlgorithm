/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 仅用两个变量，n 每次循环指定
        ListNode * pre = nullptr;
        ListNode * cur = head;
        
        while (cur != nullptr) {
            ListNode * n = cur -> next;
            cur->next = pre;
            pre = cur;
            cur = n;
        }
        return pre;
    }
};