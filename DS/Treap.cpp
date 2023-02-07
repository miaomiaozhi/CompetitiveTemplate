/*
 Treap tr(n);
 Treap tr(); 动态开点
*/
struct Treap {
#define ls tr[u].l
#define rs tr[u].r
    struct TreapNode {
        int l = 0, r = 0;
        int key = 0, val = 0;
        int siz = 0;
    };
    int n, ptr, root;
    vector <TreapNode> tr;
    vector <int> a;
    Treap() : n(0), ptr(0), root(0), a(0) {
        tr.reserve((int) 1E6);
        tr.push_back({0, 0, 0, 0, 0});
    }
    Treap(int _n) : n(_n), ptr(0), tr(_n + 5), a(_n + 5), root(0) {}
    void pushup(int u) {
        tr[u].siz = tr[ls].siz + tr[rs].siz + 1;
    }
    void pushdown(int u) {
    }
    int size() {
        return tr[root].siz;
    }
    // 动态开点直接返回 (int)tr.size() - 1
    int add_node (int val) {
        tr[++ptr] = {0, 0, rand(), val, 1};
        return ptr;
    }
    // 按值分裂 
    void split_by_val(int u, int val, int &x, int &y) {
        if (!u) {
            x = y = 0;
            return;
        }
        pushdown(u);
        if (tr[u].val <= val) {
            x = u, split_by_val(rs, val, rs, y);
        } else {
            y = u, split_by_val(ls, val, x, ls);
        }
        pushup(u);
    }
    // 按大小分裂
    void split(int u, int k, int &x, int &y) {
        if (!u) {
            x = y = 0;
            return;
        }
        pushdown(u);
        if (tr[ls].siz + 1 <= k) {
            x = u, split(rs, k - tr[ls].siz - 1, rs, y);
        } else {
            y = u, split(ls, k, x, ls);
        }
        pushup(u);
    }
    // prio(x) > prio(y) && val(x) <= val(y)
    int merge(int x, int y) {
        if (!x || !y) return x + y;
        if (tr[x].key > tr[y].key) {
            pushdown(x);
            tr[x].r = merge(tr[x].r, y);
            pushup(x);
            return x;
        } else {
            pushdown(y);
            tr[y].l = merge(x, tr[y].l);
            pushup(y);
            return y;
        }
    }
    void insert(int val) {
        int x, y;
        split_by_val(root, val, x, y);
        root = merge(x, merge(add_node(val), y));
    }
    void del(int val) {
        int x, y, z;
        split_by_val(root, val, x, z);
        split_by_val(x, val - 1, x, y);
        y = merge(tr[y].l, tr[y].r);
        root = merge(merge(x, y), z);
    }
    // 根据值查排名
    int find_rk_by_val(int val) {
        int x, y;
        split_by_val(root, val - 1, x, y);
        int res = tr[x].siz + 1;
        root = merge(x, y);
        return res;
    }
    // 根据排名查值
    int find_val_by_rk(int k) {
        int u = root;
        while (u) {
            if (tr[ls].siz + 1 == k) return tr[u].val;
            else if (tr[ls].siz + 1 > k) u = ls;
            else k -= tr[ls].siz + 1, u = rs;
        }
        return -1;
    }
    bool exist(int val) {
        int x, y, z;
        split_by_val(root, val, x, z);
        split_by_val(x, val - 1, x, y);
        bool hs = y ? 1 : 0;
        merge(x, merge(y, z));
        return hs;
    }
    int prev(int val) {
        int x, y;
        split_by_val(root, val - 1, x, y);
        int u = x;
        while (rs) u = rs;
        int res = tr[u].val;
        root = merge(x, y);
        return res;
    }
    int next(int val) {
        int x, y;
        split_by_val(root, val, x, y);
        int u = y;
        while (ls) u = ls;
        int res = tr[u].val;
        root = merge(x, y);
        return res;
    }
#undef ls
#undef rs
};