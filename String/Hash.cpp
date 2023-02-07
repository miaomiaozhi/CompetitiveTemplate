using hashv = pair<int, int>;
constexpr LL mod1 = 1000000007;
constexpr LL mod2 = 1000000009;

hashv operator+(hashv a, hashv b) {
	int c1 = a.fi + b.fi, c2 = a.se + b.se;
	if (c1 >= mod1) c1 -= mod1;
	if (c2 >= mod2) c2 -= mod2;
    return {c1, c2};
}

hashv operator-(hashv a, hashv b) {
	int c1 = a.fi - b.fi, c2 = a.se - b.se;
	if (c1 < 0) c1 += mod1;
	if (c2 < 0) c2 += mod2;
    return {c1, c2};
}

hashv operator*(hashv a, hashv b) {
    return {1LL * a.fi * b.fi % mod1, 1LL * a.se * b.se % mod2};
}
hashv pw[N];
hashv val[N], base = {2331212, 8523441};

/*
    pw[0] = {1, 1};
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * base;
        val[i] = val[i - 1] * base + hashv(s[i], s[i]);
    }
*/