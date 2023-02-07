template <class Info>
struct SegTreeMerge {
    // assume: interval range : [1, N]
    int N;
    vector<Info> tr {{}};   // init all
    SegTreeMerge() = default;
    SegTreeMerge(int _n, int _N) : N(_N) {
        tr.reserve(_n << 6);
    }
    void pushup(int u) {
        // @TODO: merge infos of two childs
        // eg: tr[u] = tr[tr[u].lc] + tr[tr[u].rc];
    }
    int newNode(int u) {
        if (u == 0) {
            tr.push_back(Info());
            u = (int) tr.size() - 1;
        }
        return u;
    }
    int merge(int u, int v, int l, int r) {
        // merge SegTree: SegTree[u] <- SegTree[u] + SegTree[v]
        if (!u || !v) {
            return u + v;
        }
        if (l == r) {
            // @TODO: merge leaf
        } else {
            int mid = l + r >> 1;
            tr[u].lc = merge(tr[u].lc, tr[v].lc, l, mid);
            tr[u].rc = merge(tr[u].rc, tr[v].rc, mid + 1, r);
            pushup(u);
        }
        return u;
    }
    void merge(int u, int v) {
        // merge SegTree rooted at v to rooted at u
        // v -> u
        merge(u, v, 1, N);
    }
    void modify(int u, int l, int r, int x, const int &v) {
        // tr[u] hold info of [l, r]
        // modify info[x] <- info[x] + v
        if (l > x || r < x) {
            return;
        }
        if (l == r) {
            // @TODO: modify leaf
            return;
        }
        tr[u].lc = newNode(tr[u].lc);
        tr[u].rc = newNode(tr[u].rc);
        int mid = l + r >> 1;
        modify(tr[u].lc, l, mid, x, v);
        modify(tr[u].rc, mid + 1, r, x, v);
        pushup(u);
    };
    void modify(int u, int x, const int &v) {
        // modify SegTree rooted at u
        modify(u, 1, N, x, v);
    }
    auto solve(int n, vector <vector<pair<int, int>>> &work, vector<vector<int>> &adj) {
        // @TODO: Solve problems
        vector <int> root(n + 1);
        vector <int> ans(n + 1);
        function <void(int, int)> dfs = [&](int u, int fa) {
            root[u] = newNode(root[u]);
            for (int v : adj[u]) if (v != fa) {
                dfs(v, u);
                merge(root[u], root[v]);
            }
            for (auto [pos, val] : work[u]) {
                modify(root[u], pos, val);
            }
            ans[u] = tr[root[u]].val;
        };
        dfs(1, -1);
        return ans;
    }
};

struct Info {
    int lc = 0, rc = 0;
};