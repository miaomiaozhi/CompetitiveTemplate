// note: query range assume n * n
// Time/Space complexity: O(n * m * log(min(n, m)))
// Quqery: O(n * m * log(min(n, m))) ~ O(1)
template<typename T>
struct TwoDimensionalSquareTable {
#define rep(i, a, b) for (int i = a; i <= b; i++)
    int n, m;
    const function<T (T, T, T, T)> cmp;
    vector<vector<vector<T>>> f;
    TwoDimensionalSquareTable(int _n, int _m, const vector<vector<T>> &a, function<T (T, T, T, T)> _cmp)
        : n(_n), m(_m), cmp(_cmp) { // begin
        assert(a.size() > n && a[0].size() > m);
        const int LG = __lg(min(n, m));
        f.assign(LG + 1, vector(n + 1, vector<T>(m + 1)));
        rep(i, 1, n) rep(j, 1, m) f[0][i][j] = a[i][j];
        rep(k, 1, LG) rep(i, 1, n - (1 << k) + 1) rep(j, 1, m - (1 << k) + 1) {
            f[k][i][j] = cmp(
                f[k - 1][i][j],
                f[k - 1][i + (1 << k - 1)][j],
                f[k - 1][i][j + (1 << k - 1)],
                f[k - 1][i + (1 << k - 1)][j + (1 << k - 1)]
            );
        }
    }
    T query(int x1, int y1, int x2, int y2) {
        assert(x2 - x1 == y2 - y1);
        int k = __lg(x2 - x1 + 1);
        return cmp(
            f[k][x1][y1],
            f[k][x2 - (1 << k) + 1][y1],
            f[k][x1][y2 - (1 << k) + 1],
            f[k][x2 - (1 << k) + 1][y2 - (1 << k) + 1]
        );
    }
#undef rep
};