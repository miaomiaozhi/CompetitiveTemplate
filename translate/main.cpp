// #pragma GCC optimize(2) 
// #define OJ
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <list>
#include <bitset>
#include <random>
#include <iterator>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define caseT int CaseT;cin >> CaseT;for(int _Case = 1; _Case <= CaseT; _Case++)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout << fixed << setprecision(10)

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
template <typename T1, typename T2> void inline read(T1 &a, T2 &b) { read(a), read(b); }
template <typename T1, typename T2, typename T3> void inline read(T1 &a, T2 &b, T3 &c) { read(a), read(b), read(c); }
template <typename T> inline void wr(T x){ if(x < 0) putchar('-'), x = -x; if(x >= 10) wr(x / 10); putchar(x % 10 + '0'); }
template <typename T1, typename T2> void inline wr(T1 &a, T2 &b) { wr(a), putchar(' '), wr(b), putchar('\n'); }
template <typename T> inline void wrn(T x, char end = '\n') { wr(x); putchar(end); }

typedef long long LL;
typedef pair <int, int> PII;
typedef pair<double, double> PDD;
typedef unsigned long long ULL;

mt19937 mrand (random_device{}());
LL rnd(LL x) { return mrand() % x; }
//<--------------------------------------------------------------------->
const int MO = 1e9 + 7;
const int N = 500010;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1);

int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1}, dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int main () {
    // #ifdef OJ
        freopen("D:\\Template\\translate\\in.txt","r",stdin);
        freopen("D:\\Template\\translate\\out.txt","w",stdout);
    // #endif 
/*     先检查数据范围 N MO 记得开 long long 图论是不是无向边呢? */
/*     流同步关了的话不要用 puts !!!!!   数据读完了再特判 !!!!  读完数据先输出一遍 !!!!!      */

    // IOS;
    string s;
    while (getline(cin, s)) {
        cout << "\"";

        for (char ch : s) {
            if (ch == '\"' || ch == '\\') cout << "\\";
            cout << ch;
        }

        cout << "\"," << endl;
    }
    
    
    return 0;
}