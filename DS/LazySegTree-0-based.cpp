template<
    class Info,
    class Tag, class Merge = plus<Info>
> class LazySegTree {
    int n;
    vector<Info> tr;
    vector<Tag> tag;
    const Merge merge = Merge();

public:
    explicit LazySegTree(int _n = 1): n(_n), tr(4 << __lg(n)), tag(4 << __lg(n)) {}
    explicit LazySegTree(const vector<Info> &init): LazySegTree((int) init.size()) {
        function<void(int, int, int)> build = [&](int u, int l, int r) {
            if (r - l == 1) {
                tr[u] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(u * 2, l, m);
            build(u * 2 + 1, m, r);
            pull(u);
        };
        build(1, 0, n);
    }

private:
    void pull(int u) {
        tr[u] = merge(tr[u * 2], tr[u * 2 + 1]);
    }
    void push(int u) {
        apply(u * 2, tag[u]);
        apply(u * 2 + 1, tag[u]);
        tag[u] = Tag();
    }
    void apply(int u, const Tag &v) {
        tr[u].apply(v);
        tag[u].merge(v);
    }
    void set(int u, int l, int r, int x, const Info &v) {
        if (l > x || r <= x) {
            return;
        }
        if (r - l == 1) {
            tr[u] = v;
            return;
        }
        push(u);
        int m = (l + r) / 2;
        set(u * 2, l, m, x, v);
        set(u * 2 + 1, m, r, x, v);
        pull(u);
    }
    void rangeApply(int u, int l, int r, int ql, int qr, const Tag &v) {
        if (l >= qr || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            return apply(u, v);
        }
        push(u);
        int m = (l + r) / 2;
        rangeApply(u * 2, l, m, ql, qr, v);
        rangeApply(u * 2 + 1, m, r, ql, qr, v);
        pull(u);
    }
    Info rangeQuery(int u, int l, int r, int ql, int qr) {
        if (l >= qr || r <= ql) {
            return Info();
        }
        if (ql <= l && r <= qr) {
            return tr[u];
        }
        push(u);
        int m = (l + r) / 2;
        return merge(rangeQuery(u * 2, l, m, ql, qr), rangeQuery(u * 2 + 1, m, r, ql, qr));
    }
    template<class F>
    int rangeFind(int u, int l, int r, int ql, int qr, const F &f) {
        if (l >= qr || r <= ql || f(tr[u]) == true) {
            return n;
        }
        if (r - l == 1) {
            return l;
        }
        push(u);
        int m = (l + r) / 2, idx = rangeFind(u * 2, l, m, ql, qr, f);
        return idx < n ? idx : rangeFind(u * 2 + 1, m, r, ql, qr, f);
    }

public:
    void set(int x, const Info &v) {
        set(1, 0, n, x, v);
    }
    void apply(int x, const Info &v) {
        set(x, merge(query(x), v));
    }
    Info query(int x) {
        return rangeQuery(x, x + 1);
    }
    void rangeApply(int l, int r, const Tag &v) {
        rangeApply(1, 0, n, l, r, v);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template<class F>
    int rangeFind(int l, int r, const F &f) {
        return rangeFind(1, 0, n, l, r, f);
    }
};

struct Tag {
    void merge(const Tag &o) {
    }
};

struct Info {
    void apply(const Tag &o) {
    }
};

Info operator+(const Info &l, const Info &r) {
    return {
    };
}