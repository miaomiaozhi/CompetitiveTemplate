class KMP {
public:
    const int INF = 0x3f3f3f3f;
    int *ne;
    KMP () {
        ne = new int(len);
    }
    KMP (string a, string b) {
        len = a.length();
        ne = new int(len);
    }
    void setMainStr(const string mainStr) {
        this->mainStr = mainStr;
    }
    void setCompareStr(const string CompareStr) {
        this->CompareStr = CompareStr;
    }
    void calcNext() {
        if (len == INF) return;
        for (int i = 1, j = 0; i <= len; i ++) {
            while (j && CompareStr[i] != CompareStr[j + 1]) j = ne[j];
            if (CompareStr[i] == CompareStr[j + 1]) j++;
            ne[i] = j;
        }
    }
private:
    string mainStr;
    string CompareStr;
    int len = INF;
};