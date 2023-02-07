struct DSU {
    int components, n;
    vector <int> f, siz;
    DSU (int _n = 1) : components(_n), n(_n + 5), f(n), siz(n, 1) {
        iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    int operator[](int x) {
        return find(x);
    }
    int same(int a, int b) {
        return find(a) == find(b);
    }
    bool merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            return false;
        }
        components--;
        siz[b] += siz[a];
        f[a] = b;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
    int count() {
        return components;
    }
};