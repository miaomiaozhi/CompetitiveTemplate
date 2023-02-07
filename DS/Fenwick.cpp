template <class T>
struct Fenwick {
    int n;
    vector<T> tr;
    Fenwick (int _n = 1) : n(_n), tr(_n + 1) {}
    void modify(int x, T c) {
        for(assert(x > 0); x <= n; x += x & -x) {
            tr[x] += c;
        }
    }
    T query(int x) {
        T res = 0;
        for(assert(x >= 0); x > 0; x -= x & -x) {
            res += tr[x];
        }
        return res;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
    int kth(int k) {
        // note : kth smallest, one-based
        int x = 0;
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (x + i < n && k > tr[x + i]) {
                k -= tr[x + i];
                x += i;
            }
        }
        return x + 1;
    }
};