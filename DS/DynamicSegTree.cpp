template <class Info>
struct DynamicSegTree {
    int N;  
    vector <Info> tr = {{}, {}};    // init all
    DynamicSegTree() {}
    DynamicSegTree(int _n, int _N) : N(_N) { 
        // n = 1E5, N = 1E9, reserve(n * 50): about 256MB
        tr.reserve(_n * 30);
    }
    DynamicSegTree(int _n, int _N, const Info &_root) : DynamicSegTree(_n, _N) {
        tr[1] = _root;
    }
    int newNode(int u, int l, int r) {
        // @TODO: init info for [l, r]
        if (u == 0) {
            tr.push_back(tr[0]);
            u = (int) tr.size() - 1;
        }
        return u;
    }
    void apply(int u, int l, int r, const int &v) {
        // @TODO: apply tag for range [l, r]
    }
    void pushup(int u) {
    }
    void pushdown(int u, int l, int r) {
        // @TODO: new node for range [l, mid] [mid + 1, r], push tag
        // init tag at last
        int mid = l + r >> 1;
        tr[u].lc = newNode(tr[u].lc, l, mid);
        tr[u].rc = newNode(tr[u].rc, mid + 1, r);
        apply(tr[u].lc, l, mid, tr[u].tag);
        apply(tr[u].rc, mid + 1, r, tr[u].tag);
        tr[u].tag = -1;
    }
    void rangeModify(int u, int l, int r, int ql, int qr, const int &v) {
        if (l > qr || r < ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            apply(u, l, r, v);
            return;
        }
        pushdown(u, l, r);
        int mid = l + r >> 1;
        rangeModify(tr[u].lc, l, mid, ql, qr, v);
        rangeModify(tr[u].rc, mid + 1, r, ql, qr, v);
        pushup(u);
    }
    void rangeModify(int l, int r, const int &v) {
        rangeModify(1, 1, N, l, r, v);
    }
    Info query(int u, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) {
            return Info();
        }
        if (ql <= l && r <= qr) {
            return tr[u];
        }
        pushdown(u, l, r);
        int mid = l + r >> 1;
        return query(tr[u].lc, l, mid, ql, qr) + query(tr[u].rc, mid + 1, r, ql, qr);
    }
    Info query(int l, int r) {
        return query(1, 1, N, l, r);
    }
    Info prod() {
        return tr[1];
    }
};

struct Info {
};

Info operator+(const Info &l, const Info &r) {
    return {
    };
}