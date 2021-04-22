//#include <iostream>
//#include <string>
//#include <vector>
//#include <ctime>
//#include <queue>
//#include <cassert>
//
//#include "FileOps.h"
//#include "SequenceST.h"
//using namespace std;
//
//template<typename Key, typename Value>
//class BST {
//private:
//    class Node {
//    public:
//        Key key;
//        Value value;
//        Node *left;
//        Node *right;
//
//        Node(Key key, Value value) {
//            this->key = key;
//            this->value = value;
//            this->left = this->right = NULL;
//        }
//
//        Node(Node * node) {
//            this->key = node->key;
//            this->value = node->value;
//            this->left = node->left;
//            this->right = node->right;
//        }
//    };
//
//    Node * root;
//    int count;
//
//public:
//    BST() {
//        root = NULL;
//        count = 0;
//    }
//    ~BST() {
//        destroy(root);  //后续遍历释放节点
//    }
//
//    int size() {
//        return count;
//    }
//
//    bool isEmpty() {
//        return count == 0;
//    }
//    /**
//     * 所有的接口设计都会隐藏 node 的节点的访问，
//     * 把对 node 节点访问的函数都放在了 private，
//     * 这体现了 OOP 封装的安全性
//     */
//    void insert(Key key, Value value) {
//        root = insert(root, key, value);
//    }
//
//    bool contain(Key key) {
//        return contain(root, key);
//    }
//
//    /**
//     * search 算法使用 Value 类型返回值没有办法处理搜素不到 key 的情况
//     * 一些库的解决方法是 断言判断是否包含 key，再返回对应的 value
//     * 课程的方法是返回 value *,查找不到 key 返回 NULL，统一了查找返回的逻辑
//     */
//
//    Value * search(Key key) {
//        return search(root, key);
//    }
//
//    // 二叉树深度优先遍历方法：前中后序遍历
//    // 区别就在 cout 这句话出现的位置
//    void preOrder() {
//        preOrder(root);
//    }
//
//    void inOrder() {
//        inOrder(root);
//    }
//
//    void postOrder() {
//        postOrder(root);
//    }
//
//    // 层序遍历
//    void levelOrder() {
//        queue<Node*> q;
//        q.push(root);
//        while (!q.empty()) {
//            Node * node = q.front();
//            q.pop();
//            cout << node->key << endl;
//
//            if (node->left)
//                q.push(node->left);
//            if (node->right)
//                q.push(node->right);
//        }
//
//    }
//
//    Key minimum() {
//        assert(count != 0);
//        Node  *minNode = mininum(root);
//        return minNode->key;
//    }
//
//    Key maxinum() {
//        assert(count != 0);
//        Node  *maxiNode = maxiNode(root);
//        return maxiNode->key;
//    }
//    // 下面两个删除算法适用于只有一个孩子的节点
//    // 1 删除最小值
//    void removeMin() {
//        if (root)
//            root = removeMin(root);
//    }
//    // 2 删除最大值
//    void removeMax() {
//        if (root)
//            root = removeMax(root);
//    }
//    // 删除有两个孩子的 key 节点
//    // 新节点是右子树最小值或者左子树最大值都可以
//    void remove(Key key) {
//        remove(root, key);
//    }
//private:
//    // 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
//    // 返回插入新节点后的二分搜索树的根
//    Node *insert(Node *node, Key key, Value value) {
//        if (node == NULL) {
//            count++;
//            return new Node(key, value);
//        }
//
//        if (key == node->key)
//            node->value = value;
//        else if (key < node->key)
//            node->left = insert(node->left, key, value);
//        else
//            node->right = insert(node->right, key, value);
//
//        return node;
//    }
//
//    bool contain(Node *node, Key key) {
//        if (node == NULL)
//            return false;
//        if (key == node->key)
//            return true;
//        else if (key < node->key)
//            return contain(node->left, key);
//        else
//            return contain(node->right, key);
//    }
//
//    Value *search(Node *node, Key key) {
//        if (node == NULL)
//            return NULL;
//
//        if (key == node->key)
//            return &(node->value);
//        else if (key < node->key)
//            return search(node->left, key);
//        else //key > node->key
//            return search(node->right, key);
//    }
//
//    void preOrder(Node *node) {
//        if (node != NULL)
//            cout << node->key << endl;
//        preOrder(node->left);
//        preOrder(node->right);
//    }
//
//    void inOrder(Node *node) {
//        if (node != NULL) {
//            inOrder(node->left);
//            cout << node->key << endl;
//            inOrder(node->right);
//        }
//    }
//
//    void postOrder(Node *node) {
//        if (node != NULL) {
//            postOrder(node->left);
//            postOrder(node->right);
//            cout << node->key << endl;
//        }
//    }
//
//    void destroy(Node *node) {
//        if (node != NULL) {
//            destroy(node->left);
//            destroy(node->right);
//
//            delete node;
//            count--;
//        }
//    }
//
//    Node *mininum(Node * node) {
//        if (node->left == NULL)
//            return node;
//        return mininum(node->left);
//    }
//
//    Node *maxinum(Node * node) {
//        if (node->right == NULL)
//            return node;
//        return maxinum(node->right);
//    }
//
//    // 删除最小值所在节点
//    Node *removeMin(Node *node) {
//        //这个 if 语句将右孩子是否存在的情况都包含了，值得学习
//        if (node->left == NULL) {
//            Node *rightNode = node->right;
//            delete node;
//            count--;
//            // return 相当于将返回的节点拼接到已删除的 node 节点
//            return rightNode;
//        }
//
//        node->left = removeMin(node->left);
//        return node;
//    }
//
//    // 删除最大值所在节点
//    Node *removeMax(Node *node) {
//        if (node->right == NULL) {
//            Node *leftNode = node->left;
//            delete node;
//            count--;
//            return leftNode;
//        }
//
//        node->right = removeMax(node->right);
//        return node;
//    }
//
//    // 删除以 node 为根的 bst 中的 key 节点，该节点有两个孩子
//    // 返回删除节点后的新的 bst
//    Node * remove(Node *node, Key key) {
//        if (node == NULL)
//            return NULL;
//        if (key < node->key)
//            node->left = remove(node->left, key);
//        else if (key > node->key)
//            node->right = remove(node->left, key);
//        else { // 找到了节点
//            // 左孩子或左右孩子都为空
//            if (node->left == NULL) {
//                Node *rightNode = node->right;
//                delete node;
//                count--;
//                return rightNode;
//            }
//
//            if (node->right == NULL) {
//                Node * leftNode = node->left;
//                delete node;
//                count--;
//                return leftNode;
//            }
//            // 左右孩子都存在
//            Node * newNode = new Node(mininum(node->right));
//            count++;
//
//            newNode->right = removeMin(node->right);
//            newNode->left = node->left;
//
//            delete node;
//            count--;
//            return newNode;
//
//        }
//
//    }
//
//};
//
//
//int main() {
//    // 使用圣经作为我们的测试用例
//    string filename = "bible.txt";
//    vector<string> words;
//    if (FileOps::readFile(filename, words)) {
//        cout << "There are totally " << words.size() << " words in " << filename
//            << endl;
//        cout << endl;
//
//        // 测试 BST
//
//
//        // 统计圣经中所有词的词频
//        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
//        // 在这里只做性能测试用
//        BST<string, int> bst = BST<string, int>();
//        for (vector<string>::iterator iter = words.begin(); iter != words.end();
//            iter++) {
//            int *res = bst.search(*iter);
//            if (res == NULL)
//                bst.insert(*iter, 1);
//            else
//                (*res)++;
//        }
//        time_t startTime = clock();
//        // 输出圣经中god一词出现的频率
//        if (bst.contain("god"))
//            cout << "'god' : " << *bst.search("god") << endl;
//        else
//            cout << "No word 'god' in " << filename << endl;
//
//        time_t endTime = clock();
//
//        cout << "BST time: " << double(endTime - startTime) / CLOCKS_PER_SEC
//            << " s." << endl;
//        cout << endl;
//
//        //    // 测试顺序查找表 SST
//        //    startTime = clock();
//
//        //    // 统计圣经中所有词的词频
//        //    // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
//        //    // 在这里只做性能测试用
//        //    SequenceST<string, int> sst = SequenceST<string, int>();
//        //    for (vector<string>::iterator iter = words.begin(); iter != words.end();
//        //        iter++) {
//        //        int *res = sst.search(*iter);
//        //        if (res == NULL)
//        //            sst.insert(*iter, 1);
//        //        else
//        //            (*res)++;
//        //    }
//
//        //    // 输出圣经中god一词出现的频率
//        //    if (sst.contain("god"))
//        //        cout << "'god' : " << *sst.search("god") << endl;
//        //    else
//        //        cout << "No word 'god' in " << filename << endl;
//
//        //    endTime = clock();
//
//        //    cout << "bST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC
//        //        << " s." << endl;
//        //}
//
//
//
//    }
//    return 0;
//}
//
