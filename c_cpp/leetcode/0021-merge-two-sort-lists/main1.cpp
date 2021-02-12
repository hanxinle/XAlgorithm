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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // 边界检查，判断是否是空链表
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;

    ListNode* pMergedHead = NULL;
    // 递归调用 mergeTwoLists，这是题目求解的关键
    // 起始，数值小的头节点作为返回的链表的头，并且自身向后遍历一个单位
    // 返回值下一个节点由调用自身得到
    if (l1->val < l2->val) {
        pMergedHead = l1;
        pMergedHead->next = mergeTwoLists(l1->next, l2);
    }
    else {
        pMergedHead = l2;
        pMergedHead->next = mergeTwoLists(l1, l2->next);
    }
    return pMergedHead;      
    }
};