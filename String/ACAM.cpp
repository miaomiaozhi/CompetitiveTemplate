struct ACAM {
    const int ALPHABET_SIZE = 26;
    int n, tot;
    vector <int> cnt, fail;
    vector <vector<int>> tr;
    
    ACAM() {}
    ACAM(int _n) : n(_n + 5), tot(0), cnt(n), fail(n), tr(n, vector<int>(ALPHABET_SIZE)) {}
    
    void insert(string &s) {
        int u = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            int c = s[i] - 'a';
            if (!tr[u][c]) {
                tr[u][c] = ++tot;
            }
            u = tr[u][c];
        }
        cnt[u]++;
    }
    void build() {
        vector <int> q;
        for (int i = 0; i < ALPHABET_SIZE; i++) 
            if (tr[0][i]) q.push_back(tr[0][i]);
        for (vector <int> nq; !q.empty(); q.swap(nq), nq.clear()) {
            for (int &u : q) {
                for (int i = 0; i < ALPHABET_SIZE; i++) {
                    if (tr[u][i]) {
                        fail[tr[u][i]] = tr[fail[u]][i];
                        nq.push_back(tr[u][i]);
                    } else {
                        tr[u][i] = tr[fail[u]][i];
                    }
                }
            }
        }
    }
    int query(string &s) {
        int u = 0, res = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            int c = s[i] - 'a';
            u = tr[u][c];
            for (int j = u; j && cnt[j] != -1; j = fail[j]) {
                res += cnt[j];
                cnt[j] = -1;
            }
        }
        return res;
    }
};