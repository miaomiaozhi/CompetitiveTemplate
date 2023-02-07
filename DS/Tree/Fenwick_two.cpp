template <typename T>
struct Fenwick {
    int n, m;
    vector <vector<T>> tr;
    Fenwick (int n = 1, int m = 1) : n(n), m(m), tr(n + 1, vector <T> (m + 1, 0)) {}
    int lowbit(int x) {
        return x & -x;
    }
    void modify(int x, int y, T c) {
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= m; j += lowbit(j)) {
                tr[i][j] += c;
            }
        }
    }
    T query(int x, int y) {
        T res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                res += tr[i][j];
            }
        }
        return res;
    }
    T query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
    }
};