// LCA lca(n, graph, root = 1);
struct LCA {
    vector<vector<int>> e, fa;
    vector<int> dep;
    int n, root;

    LCA () {}
    LCA (int _n, vector<vector<int>> &_e, int _r = 1) : e(_e), n(_n), dep(_n + 1), fa(), root(_r) {
        const int LG = __lg(n);
        fa.resize(LG + 1, vector<int>(n + 1));
        init();
    }
    void init() {
        const int LG = __lg(n);
        dep[root] = 1;

        for (vector <int> nq, q{root}; !q.empty(); q.swap(nq), nq.clear()) {
            for (int &u : q) {
                for (int v : e[u]) if (!dep[v]) {
                    dep[v] = dep[u] + 1;
                    fa[0][v] = u;
                    for (int i = 1; i <= LG; i++) {
                        fa[i][v] = fa[i - 1][fa[i - 1][v]];
                    }
                    nq.push_back(v);
                }
            }
        }
    }
    int lca(int a, int b) {
        const int LG = __lg(n);
        if(dep[a] < dep[b]) swap(a, b);
        for(int i = LG; i >= 0; i--) {
            if (dep[fa[i][a]] >= dep[b]) {
                a = fa[i][a];
            }
        }
        if(a == b) return b;
        for(int i = LG; i >= 0; i--) {
            if (fa[i][a] != fa[i][b]) {
                a = fa[i][a];
                b = fa[i][b];
            }
        }
        return fa[0][a];
    }
};