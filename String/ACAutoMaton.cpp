struct ACAutoMaton {
    static constexpr int ALPHABET_SIZE = 26;
    struct node {
        int cnt = 0;
        int fail = 0;
        int ne[ALPHABET_SIZE] = {0};
        int &operator[](const int &x) {
            return ne[x];
        }
    };
    vector <node> tr {{}};
    ACAutoMaton() = default;
    ACAutoMaton(int n) {
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
            if (!tr[u][x]) {
                tr[u][x] = newNode();
            }
            u = tr[u][x];
        }
        tr[u].cnt += 1;
    }
    void build() {
        queue <int> q;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (tr[0][i]) {
                q.push(tr[0][i]);
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                int u = tr[p][i], j = tr[p].fail;
                if (!u) {
                    tr[p][i] = tr[j][i];
                } else {
                    tr[u].fail = tr[j][i];
                    q.push(u);
                }
            }
        }
    }
    int query(const string &s) {
        int u = 0;
        int ans = 0;

        int m = tr.size();
        vector <vector<int>> adj(m);
        for (int i = 1; i < m; i++) {
            adj[tr[i].fail].push_back(i);
        }

        for (char ch : s) {
            u = tr[u][ch - 'a'];
            for (int j = u; j != 0 && tr[j].cnt != -1; j = tr[j].fail) {
                ans += tr[j].cnt;
                tr[j].cnt = -1;
            }
        }
        return ans;
    }
};