#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1}, dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

class TreeNode{
public:
	int weight;   //节点权值
	int ch;      //
    char c;     //节点编号
    string st;   //编码
	TreeNode* left, *right;
	TreeNode(): left(nullptr),right(nullptr) {}
    TreeNode(int data):left(nullptr),right(nullptr), weight(data) {}
	TreeNode(int data,int ch):left(nullptr),right(nullptr), weight(data), ch(ch) {}
};

struct cmp{     //小根堆排序
    bool operator()(TreeNode *n1, TreeNode *n2) const{
        return (n1->weight > n2->weight) || (n1->weight== n2->weight&&n1->c>n2->c);
    }
};

class Huffman{
private :
    TreeNode *root;
    string encode_st;       //编码字符串
public:
    vector<pair<int,string>> ans;
    void creatTree(vector<int>& a, vector<char> s){     //建树 传入每个节点的权值数组 节点编号数组
        priority_queue<TreeNode*,vector<TreeNode*>,cmp> q;
        for(int i = 0; i < a.size(); i++){
            TreeNode *node = new TreeNode(a[i],i);
            node->c = s[i];
            q.push(node);
        }
        while(q.size() > 1){
            auto node1 = q.top(); q.pop();
            auto node2 = q.top(); q.pop();
            TreeNode *parent= new TreeNode(node1->weight + node2->weight);
            parent->left = node1;
            parent->right = node2;
            parent->ch = -1;       //-1为后面加的parent 不重复添加
            q.push(parent);
        }
        root = new TreeNode;
        root = q.top(); q.pop();
    }

    void encode(TreeNode* root,string str){     //编码
        if (root == nullptr) return;
        if(root->ch >= 0){ 
            root->st = str; 
            return;
        }
        encode(root->left,str + '0');   //左边就是 0 右边就是 1
        encode(root->right,str + '1');     
    }
    
    void decode(const string& code){      //解码
        string a;
        encode(root,a);
        string res;
        int i = 0, n = code.size();
        TreeNode* temp = new TreeNode();
        temp = root;
        while (i < n) {	 
            if (code[i] == '0') {     //左
                temp = temp->left;
                i++;
                if(i==n&&temp->ch==-1) {
                    cout<<"error"<<endl; 
                    return ;
                }
                if (!temp->left&&!temp->right) {
                    res += temp->c;
                    temp = root;
                    continue;
                }
            }
            if (code[i] == '1')  {      // 右
                temp = temp->right;
                i++;
                if(i==n&&temp->ch==-1) {
                    cout<<"error"<<endl; 
                    return ;
                }
                if (!temp->left&&!temp->right) {
                    res += temp->c;
                    temp = root;
                    continue;
                }
                
            }
            if(!temp) {
                cout << "error" << endl; 
                return;
            }
        }
        cout << res << endl;
    }
};

int main(){
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector<int> a;      //权值数组
        vector<char> s;     //节点编号数组
        a.resize(n);
        s.resize(n);

        for (int i = 0; i < n; i ++) cin >> a[i];
        for (int i = 0; i < n; i ++) cin >> s[i];
        Huffman tree;
        tree.creatTree(a, s);
        int T;
        cin >> T;
        string b;
        
        for (int i = 0; i < T; i ++) {
            cin >> b;
            tree.decode(b);
        }
    }
}