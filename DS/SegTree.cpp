template<class Info>
struct SegTree {
    int n;
    vector<Info> tr;
    SegTree() {}
    SegTree(int _n): n(_n), tr((n + 5) * 4) {}
    SegTree(int _n, const vector<Info> a): SegTree(_n) {
        function <void(int, int, int)> build = [&](int u, int l, int r) {
            if (l == r) {
                tr[u] = a[r];
                return;
            }
            int mid = l + r >> 1;
            build(u * 2, l, mid);
            build(u * 2 + 1, mid + 1, r);
            pushup(u);
        };
        build(1, 1, n);
    }
    void pushup(int u) {
        tr[u] = tr[u * 2] + tr[u * 2 + 1];
    }
    void modify(int u, int l, int r, int x, const Info &v) {
        if (l == r) {
            tr[u] = v;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid) {
            modify(u * 2, l, mid, x, v);
        } else {
            modify(u * 2 + 1, mid + 1, r, x, v);
        }
        pushup(u);
    }
    Info query(int u, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) {
            return Info();
        }
        if (ql <= l && r <= qr) {
            return tr[u];
        }
        int mid = l + r >> 1;
        return query(u * 2, l, mid, ql, qr) + query(u * 2 + 1, mid + 1, r, ql, qr);
    }
    void modify(int x, const Info &v) {
        modify(1, 1, n, x, v);
    }
    Info query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

struct Info {
};

Info operator+(const Info &l, const Info &r) {
    return {
    };
}