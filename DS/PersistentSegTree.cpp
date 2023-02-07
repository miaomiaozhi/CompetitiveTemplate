template <class Info>
struct PersistentSegTree {
    int N;
    vector <int> root;
    vector <Info> tr {{}};
    PersistentSegTree() = default;
    PersistentSegTree(int _n, int _N) : N(_N), root(_n + 1) {
        tr.reserve(_n << 6);
    }
    PersistentSegTree(int _n, int _N, const vector<int> &a) : PersistentSegTree(_n, _N) {
        for (int i = 1; i <= _n; i++) {
            root[i] = insert(root[i - 1], 1, N, a[i], i);
        }
    }
    int newNode() {
        tr.push_back(tr[0]);
        return (int) tr.size() - 1;
    }
    void pushup(int u) {
        // @TODO: merge info
        tr[u].pos = min(tr[tr[u].lc].pos, tr[tr[u].rc].pos);
        tr[u].cnt = tr[tr[u].lc].cnt + tr[tr[u].rc].cnt;
    }
    int insert(int v, int l, int r, int x, int i) {
        int u = newNode();
        tr[u] = tr[v];
        // tr[u] <- tr[v] + new info of x
        if (l == r) {
            // @TODO: add contribute to leaf
            tr[u].pos = i;
            tr[u].cnt += 1;
        } else {
            int mid = l + r >> 1;
            if (x <= mid) {
                tr[u].lc = insert(tr[v].lc, l, mid, x, i);
            } else {
                tr[u].rc = insert(tr[v].rc, mid + 1, r, x, i);
            }
            pushup(u);
        }
        return u;
    }
    int query(int u, int v, int l, int r, int x) {
        if (l > x) {
            return 0;
        }
        if (r <= x) {
            return tr[u].cnt - tr[v].cnt;
        }
        int mid = l + r >> 1;
        return query(tr[u].lc, tr[v].lc, l, mid, x) + query(tr[u].rc, tr[v].rc, mid + 1, r, x);
    }
    int query(int l, int r, int range) {
        if (range == 0) {
            return 0;
        }
        return query(root[r], root[l - 1], 1, N, range);
    }
    int find(int u, int l, int r, int q) {
        if (l == r) {
            return r;
        }
        int mid = l + r >> 1;
        if (tr[tr[u].lc].pos < q) {
            return find(tr[u].lc, l, mid, q);
        } else {
            return find(tr[u].rc, mid + 1, r, q);
        }
    }
    int gao(int l, int r) {
        int mex = find(root[r], 1, N, l);
        return r - l + 1 - query(l, r, mex - 1);
    }
};

struct Info {
    int lc = 0, rc = 0;
    int cnt = 0, pos = 0;
};