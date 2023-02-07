// a = merge(a);
auto merge = [&](vector <PII> &segs) {
    vector <PII> res;
    if (segs.empty()) return res;

    segs.push_back({1e9, 1e9});
    sort(segs.begin(), segs.end());

    auto [L, R] = segs[0];
    for (auto [l, r] : segs) {
        if (l > R) {
            res.pb({L, R});
            L = l, R = r;
        } else {
            R = max(R, r);
        }
    }
    return res;
};

// auto c = interset(a, b);
auto interset = [&](vector <PII> a, vector <PII> b) {
    vector <PII> res;
    int n = a.size(), m = b.size();
    
    for (int i = 0, j = 0; i < n && j < m; ) {
        int l = max(a[i].fi, b[j].fi);
        int r = min(a[i].se, b[j].se);
        if (l <= r) {
            res.pb({l, r});
        }
        if (a[i].se < b[j].se) i++;
        else j++;
    }
    return res;
};