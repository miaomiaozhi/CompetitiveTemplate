struct Trie {
    static const int ALPHABET_SIZE = 26;
    struct node {
        int cnt = 0;
        int ne[ALPHABET_SIZE] = {0};
    };
    vector <node> tr {{}};
    Trie() = default;
    Trie(int n) {
        // n = |\sum S|
        tr.reserve(n + 10);
    }
    int newNode() {
        tr.push_back(node());
        return (int) tr.size() - 1;
    }
    void insert(const string &s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (!tr[u].ne[x]) {
                tr[u].ne[x] = newNode();
            }
            u = tr[u].ne[x];
        }
        tr[u].cnt += 1;
    }
    int find(const string &s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (!tr[u].ne[x]) {
                return 0;
            }
            u = tr[u].ne[x];
        }
        return tr[u].cnt;
    }
};