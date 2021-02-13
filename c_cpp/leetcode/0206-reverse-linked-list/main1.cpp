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
        if (head == nullptr) 
            return nullptr;
        if (head->next == nullptr)
            return head;
        //声明2个变量
        ListNode *pre = nullptr;
        ListNode *p   = head;
        ListNode *n = head->next;
        
        while (n) {
            p->next = pre;
            pre=p;
            p=n;
            n = n -> next;
        }      
        p -> next = pre;
        
        return p;
   
    }
};