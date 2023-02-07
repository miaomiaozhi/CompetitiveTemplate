// one-based time/space complecity: O(n log N) ~ O(log N)
template<class T, size_t N>
struct Hamel {
    int n;
    vector<vector<T>> v;
    vector<vector<int>> p;
    Hamel(int _n) : n(_n), v(n + 1, vector<T>(N, T{})), p(n + 1, vector<int>(N)) {}
    Hamel(int _n, const vector<T> &a) : Hamel(_n) {
        for (int i = 1; i <= n; i++) {
            insert(a[i], i);
        }
    }
    void insert(T x, int pos) {
        v[pos] = v[pos - 1], p[pos] = p[pos - 1];
        int y = pos;
        for (int i = N - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (v[pos][i]) {
                    if (p[pos][i] < y) {
                        swap(p[pos][i], y);
                        swap(v[pos][i], x);
                    }
                    x ^= v[pos][i];
                } else {
                    v[pos][i] = x;
                    p[pos][i] = y;
                    break;
                }
            }
        }
    }
    T query(int l, int r) {
        T x {};
        for (int i = N - 1; i >= 0; i--) {
            if (p[r][i] >= l && (x ^ v[r][i]) > x) {
                x ^= v[r][i];
            }
        }
        return x;
    }
};