template<class Info>
class Treap {
public:
    int n;
    int root = 0;
    vector<Info> tr {{}};   // init
    Treap(int n = 1) : n(n) {
        tr.reserve(n + 5);
    }

private:
    int newnode(int x) {
        // init node info here
        tr.push_back(Info(x));
        return (int) tr.size() - 1;
    }
    void pull(int u) {
        tr[u].siz = tr[tr[u].lc].siz + tr[tr[u].rc].siz + 1;
    }
    // ret: [root_l, root_r] holds val(root_l) <= x, val(root_r) > x
    pair<int, int> split(int u, int x) {
        if (u == 0) {
            return {0, 0};
        }
        if (tr[u].val <= x) {
            auto [l, r] = split(tr[u].rc, x);
            tr[u].rc = l;
            pull(u);
            return {u, r};
        } else {
            auto [l, r] = split(tr[u].lc, x);
            tr[u].lc = r;
            pull(u);
            return {l, u};
        }
    }
    // assume: val(u) <= val(v)
    int merge(int u, int v) {
        if (!u || !v) {
            return u + v;
        }
        if (tr[u].pri < tr[v].pri) {
            tr[u].rc = merge(tr[u].rc, v);
            pull(u);
            return u;
        } else {
            tr[v].lc = merge(u, tr[v].lc);
            pull(v);
            return v;
        }
    }
    bool find(int u, int x) {
        if (!u) {
            return false;
        }
        if (tr[u].val == x) {
            return true;
        }
        return tr[u].val > x ? find(tr[u].lc, x) : find(tr[u].rc, x);
    }
    int kth(int u, int k) {
        int l = tr[tr[u].lc].siz;
        if (l + 1 == k) {
            return tr[u].val;
        }
        if (l + 1 > k) {
            return kth(tr[u].lc, k);
        } else {
            return kth(tr[u].rc, k - (l + 1));
        }
    }

public:
    void insert(int x) {
        int node = newnode(x);
        auto [l, r] = split(root, x);
        root = merge(l, node);
        root = merge(root, r);
    }
    void erase(int x) {
        auto [l, r] = split(root, x - 1);
        auto [u, v] = split(r, x);
        u = merge(tr[u].lc, tr[u].rc);
        root = merge(l, u);
        root = merge(root, v);
    }
    bool find(int x) {
        return find(root, x);
    }
    int rank(int x) {
        auto [u, v] = split(root, x - 1);
        int rnk = tr[u].siz + 1;
        root = merge(u, v);
        return rnk;
    }
    int kth(int k) {
        return kth(root, k);
    }
    int prev(int x) {
        auto [l, r] = split(root, x - 1);
        int val = kth(l, tr[l].siz);
        root = merge(l, r);
        return val;
    }
    int next(int x) {
        auto [l, r] = split(root, x);
        int val = kth(r, 1);
        root = merge(l, r);
        return val;
    }
};

mt19937 rng;
struct TreapInfo {
    // must
    int lc = 0, rc = 0;
    int val = 0, siz = 0;
    int pri;

    // extra

    TreapInfo() {
        pri = rng();
    }
    TreapInfo(int val) : TreapInfo() {
        this->val = val;
        this->siz = 1;
    }
};