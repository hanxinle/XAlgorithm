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
// time cplt: O(n)
// space cplt:O(1)
// 连续节点具有相同的值，只保留一个节点

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while(p && p->next){
            if(p->val == p->next->val) 
                p->next = p->next->next;
            else 
                p = p->next;
        }
        return head; 
    }
};