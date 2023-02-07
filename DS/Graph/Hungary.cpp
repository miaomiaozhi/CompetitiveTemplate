匈牙利算法
二分图的最大匹配

形象的解释就是考虑两个点集 boys girls

从 boys 开始，遍历boys i 的所有可能女友，假如有前任就直接跳过；
    然后找到第一个不会前任的可能女友 j：
        1.j没有现任男友
        2.j有现任男友 但是可以换男友
    这两种情况都将j 当成i的女友， 所以match[j] = i 并且st[j] = 1
最后假如都不能找到女友那就直接remake 返回false

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n1, n2, m;

const int N = 510, M = 200010;
int h[N], e[M], ne[M], idx;
int match[N];   //表示右边集合对应左边集合的哪个点。
bool st[N];
//没有st数组会导致爆栈。举个简单例子：左1、左2都指向右1，执行find(1)后会使得match[1] = 1，
//接着执行find(2)时，需执行find(1)，find(1)又需执行find(1)，如此进入了死循环，导致爆栈。

//简而言之就是每次的左边点集不会重复去找已经找过的右边点集。
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            if (!match[j] || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    memset (h, -1, sizeof h);
    for (int i = 0; i < m; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
    }
    int res = 0;
    for (int i = 1; i <= n1; i ++) {
        memset (st, false, sizeof st);
        if (find(i)) res ++;
    }
    cout << res;
    return 0;
}