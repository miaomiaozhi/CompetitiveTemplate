template <class T = long long>
struct TwoDimensionalFenwick {
    int N, M;
    vector <vector<T>> tr;
    TwoDimensionalFenwick(int _n = 1, int _m = 1) : N(_n + 1), M(_m + 1), tr(N, vector<T>(M, T(0))) {}
    int lowbit(int x) {
        return x & -x;
    }
    void modify(int x, int y, T k) {
        assert(x > 0 && y > 0);
        for (int i = x; i < N; i += lowbit(i))
            for (int j = y; j < M; j += lowbit(j))
                tr[i][j] += k;
    }
    T query(int x, int y) {
        T res = 0;
        assert(x >= 0 && y >= 0 && x < N && y < M);
        for (int i = x; i > 0; i -= lowbit(i))
            for (int j = y; j > 0; j -= lowbit(j))
                res += tr[i][j];
        return res;
    }
    T query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
    }
};