/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Time Complexity: O(n)
// Space Complexity: O(h)

// 通过这种解法，学习设计辅助函数，辅助函数增加参数列表，增加可处理信息的维度
// 判断一个节点的值应该在 min max 之间，并且不相等
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        return isValidBST(root, INT_MIN  , INT_MAX );  // min,max 取值到整数的极值
    }

private:
    bool isValidBST(TreeNode* node,long long min, long long max){

        if(node == NULL)
            return true;

        if(node->val < min || node->val > max)
            return false;

        if(node->left != NULL && node->left->val >= node->val)
            return false;

        if(node->right != NULL && node->right->val <= node->val)
            return false;
        //在这里参数调用会有溢出的隐患，将参数强制转化为 long long 类型
        return isValidBST(node->left, min,(long long) node->val - 1) && isValidBST(node->right, (long long)node->val + 1, max);
    }

};