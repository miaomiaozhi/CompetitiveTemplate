/*
    RMQ <T> (int n, vector <T> a, function cmp_function)
    rmq.init();
    rmq.query(int l, int r);
*/
template <typename T>
struct RMQ {
    int n;
    vector <vector<T>> f;
    vector <int> log_2;
    vector <T> a;
    function <T(T, T)> cmp;

    RMQ() {}
    RMQ (int _n, function<T(T, T)> op) : 
        n(_n), f(_n + 5, vector<T>(__lg(n) + 1)), log_2(_n + 5), a(_n + 5), cmp(op) {}
    RMQ (int _n, const vector <T> &_a, function<T(T, T)> op) : 
        n(_n), f(_n + 5, vector<T>(__lg(n) + 1)), log_2(_n + 5), a(_a), cmp(op) { init(); }
    void init() {
        int m = __lg(n);
        for(int j = 0; j <= m; j ++) {
            for(int i = 1; i + (1 << j) - 1 <= n; i ++) {
                if(!j) f[i][j] = a[i];
                else f[i][j] = cmp(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
            }
        }
        int last = 0;
        for(int i = 0; 1 << i <= n; i ++) log_2[1 << i] = i;
        for(int i = 1; i <= n; i ++) {
            if(!log_2[i]) log_2[i] = last;
            else last = log_2[i];
        }
    }
    T query(T l, T r) {
        assert(l <= r);
        int k = log_2[r - l + 1];
        return cmp(f[l][k], f[r - (1 << k) + 1][k]);
    }
};