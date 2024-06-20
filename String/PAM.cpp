constexpr int ALPHABET_SIZE = 26;
struct Info {
    int len = 0;
    int fail = 0;
    int cnt = 0;
    int ne[ALPHABET_SIZE] {};

    int &operator[](const int &x) {
        return ne[x];
    }
};

struct PalindromeAutoMaton {
    vector<int> s {-1};
    vector<Info> t;
    int last = 0;   // last state

    PalindromeAutoMaton(int n = 1) {
        t.reserve(n + 5);
        s.reserve(n + 5);
        newnode(0);
        newnode(-1);
        // even -> odd
        t[0].fail = 1;
    }
    int newnode(int len_) {
        t.push_back({len_});
        return (int) t.size() - 1;
    }
    // return a MAXIMUM length state holds 
    // prev() + str(x) + next() is a palindrome str
    int find(int x) {
        while (s.back() != s[(int) s.size() - 2 - t[x].len]) {
            x = t[x].fail;
        }
        return x;
    }
    void extend(int x) {
        s.push_back(x);
        int u = find(last);
        if (!t[u][x]) {
            int v = newnode(t[u].len + 2);
            t[v].fail = t[find(t[u].fail)][x];
            t[u][x] = v;
        }
        last = t[u][x];
        t[last].cnt += 1;
    }
};