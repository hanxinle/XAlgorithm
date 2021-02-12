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
/// Recursive
/// Time Complexity: O(len(l1) + len(l2))
/// Space Complexity: O(len(l1) + len(l2))
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1 == NULL)
            return l2;

        if(l2 == NULL)
            return l1;
        // 依旧是递归，但是不需要声明中间变量当作链表头节点作为该解法的返回值
        // 根据头节点数据域的值关系确定头节点
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }

        // else 因为上面 if 语句已经返回，这里不写 else 区分不同情况
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
        
    }
};