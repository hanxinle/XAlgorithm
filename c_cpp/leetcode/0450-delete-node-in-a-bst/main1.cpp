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

// Time Complexity: O(logn)
// Space Complexity: O(h)

// 题目给出的情况是，找到该节点并且删除后由它的右孩子替换父节点

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
            //return root;
        }

        else if(key > root->val){
            root->right = deleteNode(root->right, key);
            //return root;
        }
        // key == root->val 的情况
        // 被删除节点只有左孩子，右孩子中的一个
        // 将该孩子替换父节点即可
        else {  // key == root->val
        
        if(!root->right) return root->left;
 
        if(!root->left)  return root->right;
        // 如果左右孩子都存在，minnode 则在右子树找最小节点
        // 并且由右子树最小节点替换父节点

        TreeNode *minnode = root->right;
        while(minnode->left){
            minnode = minnode->left;
        }

        root->val = minnode->val;
        // 右子树删除最小节点，左子树不变
        root->right = deleteMinNode(root->right);
        //return root;
        }
        return root;
    }

private:
    TreeNode* deleteMinNode(TreeNode* root){
        // 如果没有左子树，返回右子树（相当于删掉了父节点）
        if(!root->left) return root->right;
        root->left = deleteMinNode(root->left);
        return root;
    }   
};