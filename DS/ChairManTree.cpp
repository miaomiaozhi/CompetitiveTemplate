struct ChairManTree {
    struct node {
        int l = 0, r = 0, cnt = 0;
    };
    
    int n, idx;
    vector <int> root;
    vector <node> tr;
    
    ChairManTree() {}
    ChairManTree(int _n) : n(_n), idx(0), root(n + 5), tr((n + 5) << 5) {
        function <int(int, int)> build = [&](int l, int r) {
            int u = ++idx;
            if (l == r) {
                return u;
            }
            int mid = l + r >> 1;
            tr[u].l = build(l, mid);
            tr[u].r = build(mid + 1, r);
            return u;
        };
        root[0] = build(1, n);
    }
    ChairManTree(int _n, const vector<int> a) : ChairManTree(_n) {
        assert(a.size() >= n + 1);
        for (int i = 1; i <= n; i++) {
            root[i] = insert(root[i - 1], 1, n, a[i]);
        }
    }
    int insert(int u, int l, int r, int x) {
        int now = ++idx;
        tr[now] = tr[u];
        if (l == r) {
            tr[now].cnt++;
            return now;
        }
        int mid = l + r >> 1;
        if (x <= mid) {
            tr[now].l = insert(tr[u].l, l, mid, x);
        } else {
            tr[now].r = insert(tr[u].r, mid + 1, r, x);
        }
        tr[now].cnt = tr[tr[now].l].cnt + tr[tr[now].r].cnt;
        return now;
    }
    int query(int prev, int now, int l, int r, int k) {
        if (l == r) {
            return r;
        }
        int cnt = tr[tr[now].l].cnt - tr[tr[prev].l].cnt;
        int mid = l + r >> 1;
        if (cnt >= k) {
            return query(tr[prev].l, tr[now].l, l, mid, k);
        } else {
            return query(tr[prev].r, tr[now].r, mid + 1, r, k - cnt);
        }
    }
    int query(int l, int r, int k) {
        return query(root[l - 1], root[r], 1, n, k);
    }
};