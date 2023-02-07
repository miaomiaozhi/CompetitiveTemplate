struct CTreeNode {
    int l, r;
    mutable int v;
    CTreeNode (const int &_l, const int &_r, const int &_v) : l(_l), r(_r), v(_v) {}
    inline bool operator<(const CTreeNode &o) const { 
        return l < o.l;
    }
};

/*
    ODT odt(n);
    odt.insert(l, r, val);
    odt.function();

    remember to add right bound : odt.insert(n, n, ...);
*/
struct CTree {
    set <CTreeNode> odt;
    int n;
    CTree (int _n = 1) : n(_n) {
        odt.clear();
    }

    void insert(int l, int r, int v) {
        odt.insert({l, r, v});
    }

    /*
        将包含 x 的区间分裂成 [l, x - 1], [x, r]
    */
    auto split (int x) {
        if (x > n) return odt.end();
        auto it = --odt.upper_bound({x, 0, 0});
        if (it->l == x) return it;
        int l = it->l, r = it->r, v = it->v;
        odt.erase(it);
        odt.insert({l, x - 1, v});
        return odt.insert({x, r, v}).fi;
    }

    // 区间赋值
    void assign (int l, int r, int v) {
        auto itr = split(r + 1), itl = split(l);
        odt.erase(itl, itr);
        odt.insert({l, r, v});
    }

    // 区间最大连续的 1
    int query(int l, int r) {
        auto itr = split(r + 1), itl = split(l);
        int last = 0;
        int mx = 0;
        for (; itl != itr; itl++) {
            auto [l, r, v] = *itl;
            if (v) {
                last += r - l + 1;
                mx = max(mx, last);
            } else {
                last = 0;
            }
        }
        return mx;
    } 
};