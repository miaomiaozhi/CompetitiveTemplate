struct HLD {
    int n, cnt, root;
    vector <vector<int>> e;
    vector <int> fa, dep, dfn, rnk, son, siz, top;
    
    HLD() {}
    HLD(int _n, int _r = 1) : n(_n + 1), e(n), cnt(0), root(_r), 
        fa(n), dep(n), dfn(n), rnk(n), son(n), siz(n), top(n) {
    }
    HLD(int _n, vector <vector<int>> &_e, int _r = 1) : n(_n + 1), e(_e), cnt(0), root(_r),
        fa(n), dep(n), dfn(n), rnk(n), son(n), siz(n), top(n) {
        init();
    }
    void init() {
        dfs1(root, -1);
        dfs2(root, root);
    }
    void add(int u, int v) {
        e[u].push_back(v);
        e[v].push_back(u);
    }
    void dfs1(int u, int father) {
        siz[u] = 1, son[u] = -1;
        for (int v : e[u]) {
            if (v != father) {
                fa[v] = u, dep[v] = dep[u] + 1;
                dfs1(v, u);
                siz[u] += siz[v];
                if (son[u] == -1 || siz[v] > siz[son[u]]) 
                    son[u] = v;
            }
        }
    }
    void dfs2(int u, int t) {
        dfn[u] = ++cnt;
        rnk[cnt] = u, top[u] = t;
        if (son[u] == -1) return;
        dfs2(son[u], t);
        for (int v : e[u])
            if (v != fa[u] && v != son[u]) 
                dfs2(v, v);
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            u = fa[top[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }
    template <typename T>
    T query(int u, int v, function <T(int, int)> func) {
        T ret = 0;
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ret += func(dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        if (dep[u] < dep[v]) swap(u, v);
        ret += func(dfn[v], dfn[u]);
        return ret;
    }
    void modify(int u, int v, function <void(int, int)> func) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            func(dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        if (dep[u] < dep[v]) swap(u, v);
        func(dfn[v], dfn[u]);
    }
};