/**
 * avl 节点多一个 height
 * 多一个判断是否是avl的接口 isBalanced()及辅助函数
 * LL，LR，RR，RL的旋转树平衡方法在 insert，remove中都有涉及
 * 这种写小函数的完成辅助任务的方法是非常值得借鉴的
 * 可以保护 root 变量
 */
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <cassert>

#include "FileOps.h"
#include "SequenceST.h"
using namespace std;

template<typename Key, typename Value>
class AVL {
private:
    class Node {
    public:
        Key key;
        Value value;
        int height;
        Node* left;
        Node* right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
            this->height = 1;
        }

        Node(Node* node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
            this->height = node->height;
        }
    };

    Node* root;
    int count;

public:
    AVL() {
        root = NULL;
        count = 0;
    }
    ~AVL() {
        destroy(root);  //后续遍历释放节点
    }
    // 是否满足二叉树条件
    bool isBst() {
        vector<Key> keys;
        inOrder(root, keys);

        for (auto it = keys.begin() + 1; it != keys.end(); it++) {
            if (*(it - 1) > *(it))
                return false;
            return true;
        }
    }
    bool isBalanced() {
        return isBalanced(root);
    }
    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }
    /**
     * 所有的接口设计都会隐藏 node 的节点的访问，
     * 把对 node 节点访问的函数都放在了 private，
     * 这体现了 OOP 封装的安全性
     */
    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }

    bool contain(Key key) {
        return contain(root, key);
    }

    /**
     * search 算法使用 Value 类型返回值没有办法处理搜素不到 key 的情况
     * 一些库的解决方法是 断言判断是否包含 key，再返回对应的 value
     * 课程的方法是返回 value *,查找不到 key 返回 NULL，统一了查找返回的逻辑
     */

    Value* search(Key key) {
        return search(root, key);
    }

    // 二叉树深度优先遍历方法：前中后序遍历
    // 区别就在 cout 这句话出现的位置
    void preOrder() {
        preOrder(root);
    }

    void inOrder() {
        inOrder(root);
    }

    void postOrder() {
        postOrder(root);
    }

    // 层序遍历
    void levelOrder() {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->key << endl;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

    }

    Key minimum() {
        assert(count != 0);
        Node* minNode = mininum(root);
        return minNode->key;
    }

    Key maxinum() {
        assert(count != 0);
        Node* maxiNode = maxiNode(root);
        return maxiNode->key;
    }
    //// 下面两个删除算法适用于只有一个孩子的节点
    //// 1 删除最小值
    //void removeMin() {
    //    if (root)
    //        root = removeMin(root);
    //}
    //// 2 删除最大值
    //void removeMax() {
    //    if (root)
    //        root = removeMax(root);
    //}
    // 删除有两个孩子的 key 节点
    // 新节点是右子树最小值或者左子树最大值都可以
    void remove(Key key) {
        remove(root, key);
    }
private:
    // 节点高度
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // 节点的平衡因子
    int getBalanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    bool isBalanced(Node* node) {
        if (node == nullptr)
            return true;

        int balanceFator = getBalanceFactor(node);
        if (abs(balanceFator) > 1)
            return false;
        return isBalanced(node->left) && isBalanced(node->right);
    }

    // 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二分搜索树的根
    Node* insert(Node* node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }


        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);
        else
            node->value = value;
        // 更新高度
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        // 平衡因子
        int balanceFactor = getBalanceFactor(node);
        //if (balanceFactor > 1)
        //    cout << "Unbalanced: " << balanceFactor << endl;
        // 平衡维护,4种情况
        // LL,右旋转
        if ((balanceFactor > 1) && getBalanceFactor(node->left) >= 0)
            return rightRotate(node);
        // RR，左旋转
        if ((balanceFactor < -1) && getBalanceFactor(node->right) <= 0)
            return leftRotate(node);
        // LR
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // RL
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // RR 右旋转，稍后设置为 private
    // 对节点y进行向右旋转操作，返回旋转后新的根节点x
    //        y                              x
    //       / \                           /   \
    //      x   T4     向右旋转 (y)        z     y
    //     / \       - - - - - - - ->    / \   / \
    //    z   T3                       T1  T2 T3 T4
    //   / \
    // T1   T2
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t3 = x->right;

        x->right = y;
        y->left = t3;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // LL 对节点y进行向左旋转操作，返回旋转后新的根节点x
    //    y                             x
    //  /  \                          /   \
    // T1   x      向左旋转 (y)       y     z
    //     / \   - - - - - - - ->   / \   / \
    //   T2  z                     T1 T2 T3 T4
    //      / \
    //     T3 T4
    Node* leftRotate(Node* y) {

        Node* x = y->right;
        Node* t2 = x->left;

        x->left = y;
        y->right = t2;

        // 更新height
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }



    bool contain(Node* node, Key key) {
        if (node == NULL)
            return false;
        if (key == node->key)
            return true;
        else if (key < node->key)
            return contain(node->left, key);
        else
            return contain(node->right, key);
    }

    Value* search(Node* node, Key key) {
        if (node == NULL)
            return NULL;

        if (key == node->key)
            return &(node->value);
        else if (key < node->key)
            return search(node->left, key);
        else //key > node->key
            return search(node->right, key);
    }
    // 前序
    void preOrder(Node* node) {
        if (node != NULL)
            cout << node->key << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
    // 中序
    void inOrder(Node* node) {
        if (node != NULL) {
            inOrder(node->left);
            cout << node->key << endl;
            inOrder(node->right);
        }
    }
    // 中序遍历，并且将节点数据域存储于vec
    // 相当于进行排序
    void  inOrder(Node* node, vector<Key>& vec) {
        if (node == nullptr)
            return;
        inOrder(node->left, vec);
        vec.push_back(node->key);
        inOrder(node->right, vec);
    }
    // 后序遍历
    void postOrder(Node* node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << endl;
        }
    }

    void destroy(Node* node) {
        if (node != NULL) {
            destroy(node->left);
            destroy(node->right);

            delete node;
            count--;
        }
    }

    Node* mininum(Node* node) {
        if (node->left == NULL)
            return node;
        return mininum(node->left);
    }

    Node* maxinum(Node* node) {
        if (node->right == NULL)
            return node;
        return maxinum(node->right);
    }

    //// 删除最小值所在节点
    //Node *removeMin(Node *node) {
    //    //这个 if 语句将右孩子是否存在的情况都包含了，值得学习
    //    if (node->left == NULL) {
    //        Node *rightNode = node->right;
    //        delete node;
    //        count--;
    //        // return 相当于将返回的节点拼接到已删除的 node 节点
    //        return rightNode;
    //    }

    //    node->left = removeMin(node->left);
    //    return node;
    //}

    //// 删除最大值所在节点
    //Node *removeMax(Node *node) {
    //    if (node->right == NULL) {
    //        Node *leftNode = node->left;
    //        delete node;
    //        count--;
    //        return leftNode;
    //    }

    //    node->right = removeMax(node->right);
    //    return node;
    //}

    // 删除以 node 为根的 bst 中的 key 节点，该节点有两个孩子
    // 返回删除节点后的新的 bst
    Node* remove(Node* node, Key key) {
        if (node == nullptr)
            return nullptr;
        Node* retNode;
        if (key < node->key) {
            node->left = remove(node->left, key);
            retNode = node;
        } else if (key > node->key) {
            node->right = remove(node->left, key);
            retNode = node;
        } else { // 找到了节点
            // 左孩子或左右孩子都为空
            if (node->left == nullptr) {
                Node* rightNode = node->right;
                delete node;
                count--;
                retNode = rightNode;
            }

            else if (node->right == nullptr) {
                Node* leftNode = node->left;
                delete node;
                count--;
                retNode = leftNode;
            }
            // 左右孩子都存在
            else {
                Node* newNode = new Node(mininum(node->right));
                count++;

                newNode->right = remove(node->right, newNode->key);
                newNode->left = node->left;

                delete node;
                count--;
                retNode = newNode;
            }
        }
        retNode->height = 1 + max(getHeight(retNode->left), getHeight(retNode->right));
        // 平衡因子
        int balanceFactor = getBalanceFactor(retNode);

        // 平衡维护,4种情况
        // LL,右旋转
        if ((balanceFactor > 1) && getBalanceFactor(retNode->left) >= 0)
            return rightRotate(retNode);
        // RR，左旋转
        if ((balanceFactor < -1) && getBalanceFactor(retNode->right) <= 0)
            return leftRotate(retNode);
        // LR
        if (balanceFactor > 1 && getBalanceFactor(retNode->left) < 0) {
            retNode->left = leftRotate(retNode->left);
            return rightRotate(retNode);
        }
        // RL
        if (balanceFactor < -1 && getBalanceFactor(retNode->right) > 0) {
            retNode->right = rightRotate(retNode->right);
            return leftRotate(retNode);
        }
        return retNode;
    }
};


int main() {
    string filename = "bible.txt";
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        cout << "There are totally " << words.size() << " words in " << filename
            << endl;
        cout << endl;

        // 测试 BST


        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        AVL<string, int> bst = AVL<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end();
             iter++) {
            int* res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }
        time_t startTime = clock();
        // 输出圣经中god一词出现的频率
        if (bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "AVL time: " << double(endTime - startTime) / CLOCKS_PER_SEC
            << " s." << endl;
        cout << endl;
        cout << "isBst ";
        if (bst.isBst())
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "isBalanced ";
        if (bst.isBalanced())
            cout << "true" << endl;
        else
            cout << "false" << endl;

    }
    return 0;
}
