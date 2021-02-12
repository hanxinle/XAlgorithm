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
// 连续节点具有相同的数据域，则删除这些节点
// 通过变量量 num 记录是否有连续节点具有相同数据域的情况
// 因为头节点可能会删除，为了统一处理逻辑，构造dummyHead节点
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* prev = dummyHead;
        ListNode* cur = prev->next;
        
        // cur == head
        while(cur){

            int num = 0;
            ListNode* p = cur;
            while(p && p->val == cur->val){
                num ++;
                p = p->next;
            }

            if(num > 1)
                prev->next = p;
            else
                prev = cur;
            cur = p;
        }

        ListNode* ret = dummyHead->next;  // ret == 原 head or 新 head（原 head 因为有重复被删除）
        delete dummyHead;
        return ret;
    }
};