//using namespace std;
//
//#include <iostream>
//
//class TreeNode {
//public:
//    int val = 0;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode(int x) {
//        val = x;
//        left = right = nullptr;
//    }
//};
//
//class TreePathSum {
//public:
//    static bool hasPath(TreeNode *root, int sum) {
//        if (root == nullptr) {
//            return false;
//        }
//
//        // 只有根节点且根节点就等于和
//        if (root->val == sum && root->left == nullptr && root->right == nullptr) {
//            return true;
//        }
//
//        // 递归检测左右子树，有一个存在和为 sum 即返回 true
//        return hasPath(root->left, sum - root->val) || hasPath(root->right, sum - root->val);
//    }
//};
//
//int main(int argc, char *argv[]) {
//    TreeNode *root = new TreeNode(12);
//    root->left = new TreeNode(7);
//    root->right = new TreeNode(1);
//    root->left->left = new TreeNode(9);
//    root->right->left = new TreeNode(10);
//    root->right->right = new TreeNode(5);
//    cout << "Tree has path: " << TreePathSum::hasPath(root, 23) << endl;
//    cout << "Tree has path: " << TreePathSum::hasPath(root, 16) << endl;
//}