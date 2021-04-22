///* 将注释语句和它最近最类似那句替换，就会逆向按层次打印这棵树*/
//#include <iostream>
//#include <queue>
//#include <deque>
//using namespace std;
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
//class LevelOrderTraversal {
//public:
//    static vector<vector<int>> traverse(TreeNode *root) {
//        //static deque<vector<int>> traverse(TreeNode *root) {
//        //deque<vector<int>> result = deque<vector<int>>();
//        vector<vector<int>> result;
//
//        if (root == nullptr) {
//            return result;
//        }
//
//        queue<TreeNode *> queue;
//        // 起始状态 root 入队
//        queue.push(root);
//
//        while (!queue.empty()) {
//            // levelSize 个元素出队
//            int levelSize = queue.size();
//            // 打印每层树节点的值
//            vector<int> currentLevel;
//
//            for (int i = 0; i < levelSize; i++) {
//                // 读取队首元素
//                TreeNode *currentNode = queue.front();
//                // 该元素的左右孩子入队
//                if (currentNode->left != nullptr) {
//                    queue.push(currentNode->left);
//                }
//                if (currentNode->right != nullptr) {
//                    queue.push(currentNode->right);
//                }
//                // 负责打印的 vector 打印队首元素持有的值 
//                currentLevel.push_back(currentNode->val);
//                // 队首元素出队
//                queue.pop();
//            }
//            result.push_back(currentLevel);
//        }
//
//        return result;
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
//    vector<vector<int>> result = LevelOrderTraversal::traverse(root);
//    //deque<vector<int>> result = LevelOrderTraversal::traverse(root);
//
//    cout << "Level order traversal: " << endl;
//    for (auto vec : result) {
//        for (auto num : vec) {
//            cout << num << " ";
//        }
//        cout << endl;
//    }
//}