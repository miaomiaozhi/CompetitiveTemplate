#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class BiNode {
public:
	int val;
	BiNode *left = nullptr;
	BiNode *right = nullptr;
	BiNode *parent = nullptr;
	BiNode() {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	BiNode(int val) {
		this->val = val;
		BiNode();
	}
	friend class BST;
};

class BST {
public:
	BiNode *root;
	int searchTimes = 0;
	BST() {
		root = nullptr;
	}
	BST(vector <int> &arr) {
		root = nullptr;
		int n = arr.size();
		for (int i = 0; i < n; i ++) {
			insert(root, arr[i]);
		}
	}

	bool insert(BiNode *&node, int x) {
		if (node == nullptr) {
			node = new BiNode(x);
			return true;
		}
		if (node->val == x) return false;
		if (node->val < x) {
			return insert(node->right, x);
		}
		else {
			return insert(node->left, x);
		}
		return true;
	}

	void inOrder() {
		inOrder(root);
		cout << endl;
	}

	BiNode* findK(BiNode *node, int k) {
		if(node == nullptr || node->val == k) return node;
		if(node->val < k) {
			return findK(node->left, k);
		}
		return findK(node->right, k);
	}

	int getSearchValTimes(int x) {
		searchTimes = 0;
		if(searchVal(root, x)) {
			return searchTimes;
		}
		return -1;
	}

	void deleteVal(int x) {
		BiNode *fa = new BiNode();
		deleteVal(root, x);
	}

private:
	void deleteVal(BiNode *&node, int x) {
		if(node == nullptr) return;
		if(node->val < x) {
			deleteVal(node->right, x);
			return;
		}
		if(node->val > x) {
			deleteVal(node->left, x);
			return;
		}

		if(!node->left && !node->right) {
			delete node;
			node = nullptr;
		}

		if(!node->left && node->right) {
			
		}

	}

	bool searchVal(BiNode *node, int x) {
		if(node == nullptr) return 0;
		searchTimes++;
		if(node->val == x) return 1;
		if (node->val < x) {
			return searchVal(node->right, x);
		}
		else {
			return searchVal(node->left, x);
		}
	}

	void preOrder(BiNode *node) {
		if(node == nullptr) return;
		cout << node->val << ' ';
		preOrder(node->left);
		preOrder(node->right);
	}

	void inOrder(BiNode *node) {
		if(node == nullptr) return;
		inOrder(node->left);
		cout << node->val << ' ';
		inOrder(node->right);
	}

	void postOrder(BiNode *node) {
		if(node == nullptr) return;
		postOrder(node->left);
		postOrder(node->right);
		cout << node->val << ' ';
	}
};

int main() {
	int T;
	cin >> T;
	while(T --) {
		vector <int> a;
		int n, m;
		cin >> n;
		for (int i = 0; i < n; i ++) {
			int t;
			cin >> t;
			a.pb(t);
		}
		BST bst = BST(a);
		bst.inOrder();
		cin >> m;
		while(m --) {
			int x;
			cin >> x;
			bst.deleteVal(x);
			bst.inOrder();
		}
	}
	return 0;
}