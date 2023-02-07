struct SegTree {
    const int inf = 1e6;
    // 空间 O((n + q) log n)
    struct node {
        int l, r;
        LL sum, tag;
        node(): l(0), r(0), sum(0), tag(0) {}
    };
    
    int n, root, idx;
    vector <node> tr;
    SegTree(int _n = 1) : n(_n + 1), root(0), idx(0), tr(n << 5) {}
    void pushup(int u) {
        tr[u].sum = tr[tr[u].l].sum + tr[tr[u].r].sum;
    }
    void modify(int &u, int l, int r, int pos, LL v) {
        if (!u) u = ++idx;
        if (l == r) {
            tr[u].sum += v;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) modify(tr[u].l, l, mid, pos, v);
        else modify(tr[u].r, mid + 1, r, pos, v);
        pushup(u);
    }
    LL query(int u, int l, int r, int ql, int qr) {
        if (!u) return 0;
        if (ql <= l && r <= qr) return tr[u].sum;
        int mid = (l + r) >> 1;
        LL res = 0;
        if (ql <= mid) res += query(tr[u].l, l, mid, ql, qr);
        if (qr > mid) res += query(tr[u].r, mid + 1, r, ql, qr);
        return res;
    }
    void modify(int i, LL x) {
        modify(root, 1, n, i, x);
    }
    LL query(int l, int r) {
        return query(root, 1, n, l, r);
    }
};