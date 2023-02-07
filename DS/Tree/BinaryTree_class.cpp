#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

class BiNode {
private:
    char val;   //节点的编号 val值可以任意换
    int weight = INF;   //节点的权值
    BiNode *left;   //左右孩子
    BiNode *right;
    BiNode() {     //构造函数
        left = nullptr;
        right = nullptr;
    }
    BiNode(char t) {
        BiNode();
        val = t;
    }
    BiNode(char t, int weight) {
        BiNode();
        val = t;
        this->weight = weight;
    }
    ~BiNode () {       //析构函数
        delete left;
        delete right;
    }
    friend class BiTree;
};

class BiTree {
private:
    BiNode *root;
    BiTree () {
        root = new BiNode();
    }
    
    void creatTree(BiNode *&node) {     //前序遍历建树
        char t;
        cin >> t;
        if (t == '0') {         //空树看题目要求来设定
            node = nullptr;
            return;
        }
        node = new BiNode(t);      //新建一个节点，然后将节点的值置成t
        creatTree(node->left);     //递归建立左右子树
        creatTree(node->right); 
    }

    void preOrder (BiNode *&node) {     //前序遍历
        if (node == nullptr) return;
        cout << node->val << ' ';
        preOrder(node->left);
        preOrder(node->right);
    }
    
    void inOrder(BiNode *&node) {   //中序遍历
        if (node == nullptr) return;
        
        inOrder(node->left);
        cout << node->val << ' ';
        inOrder(node->right);
    }
    
    void postOrder(BiNode *&node) {     //后序遍历
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << ' ';
    }
    
    void floorOrder(BiNode *&node) {      //层序遍历
        if (node == nullptr) return;
        queue <BiNode*> q;
        q.push(node);
        while(q.size()) {
            int n = q.size();
            for (int i = 0; i < n; i ++) {
                BiNode *f = q.front();
                q.pop();
                if (f == nullptr) continue;
                cout << f->val << ' ';
                if (f->left != nullptr) q.push(f->left);
                if (f->right != nullptr) q.push(f->right);
            }
        }
    }

    int getLeafCount(BiNode *&node) {    // 传入根节点，跟叶子节点；返回叶子节点数
        int cnt = 0;
        if (node != nullptr) {
            if (node->left == nullptr && node->right == nullptr) {
                cnt ++;
                return 1;
            }
            getLeafCount(node->left);
            getLeafCount(node->right);
        }
        return cnt;
    }

    int getDepth(BiNode *&node) {   //返回到根的高度
        int deep = 0;
        if (node == nullptr) return deep;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        deep = leftDepth >= rightDepth ? leftDepth + 1 : rightDepth + 1; 
        return deep;
    }

    void getLeafFather(BiNode *&node, char fatherVal, vector <char> &ans) {    //传入空的ans 返回每个叶子的父亲
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(fatherVal);
        }
        getLeafFather(node->left, node->val, ans);
        getLeafFather(node->right, node->val, ans);
    }

    int getMaxWeight(BiNode *&node) {   // 得到最大的路径权值。
        if (node == nullptr) return 0;
        int s = node->weight;
        int left = getMaxWeight(node->left);
        int right = getMaxWeight(node->right);
        return s + max(left, right);
    } 

    bool isLeaf(BiNode *node) {
        if (node == nullptr) return false;
        if (node->left == nullptr && node->right == nullptr) return true;
        return false;
    }
    
    void getLeafWeight(BiNode *node) {  //去到叶子节点的权值
        if (node == nullptr) return;
        if (isLeaf(node)) {
            int v;
            cin >> v;
            node->weight = v;
        }
        getLeafWeight(node->left);
        getLeafWeight(node->right);
    }

    //启动函数
public:
    BiTree() {
        creatTree(root);
    }
    ~BiTree() {
        delete root;
    }
    void preOrder() {
        preOrder(root);
    }
    void inOrder() {
        inOrder(root);
    }
    void postOrder() {
        postOrder(root);
    }
    void floorOrder() {
        floorOrder(root);
    }
    int getLeafCount() {
        return getLeafCount(root);
    }
    int getDepth() {
        return getDepth(root);
    }
    vector <char> getLeafFather() {
        vector <char> ret;
        getLeafFather(root, '@', ret);  //根节点随便传入一个虚拟的父节点就可以了
        return ret;
    }
    int getMaxWeight() {
        return getMaxWeight(root);
    }
    void getLeafWeight() {
        getLeafWeight(root);
    }
};

int main() {
    BiTree tree = BiTree();
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    tree.floorOrder();
}