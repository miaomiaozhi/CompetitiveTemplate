    //约数

// 1、求一个数a的所有约数
vector <int> get_divisors(int a) {
    vector<int> ret;
    for (int i = 1; i <= a / i; i ++) {
        if (a % i == 0) {       //假如i是一个约数  那么a / i也是一个约数
            ret.push_back(i);
            if (i != a / i)
                ret.push_back(a / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

// 2、 求a的约数个数
/*
N = p1 α1 ∗ p2 α2 ∗⋯∗ pk αk
ans = 约数个数也就等于 (α1+1)(α2+1)…(αk+1)
因为任何一个约数d可以表示成pβ11∗pβ22∗⋯∗pβkk,0≤βi≤αi每一项的βi如果不同，
那么约数d就不相同（算数基本定理，每个数的因式分解是唯一的）所以n的约数就跟βi的选法是
一一对应的β1一共有0∼α1种选法β2一共有0∼α2种选法…βk一共有0∼αk种选法乘法原理，一共有ans个约数
*/
const int MO = 1e9 + 7;
int main () {
    int n;
    cin >> n;
    unordered_map <int, int> primes;
    while (n --) {      //a分解质因数 将每个质因数的次数记录在哈希表
        int a;
        cin >> a;
        for (int i = 2; i <= a / i; i ++) {
            while (a % i == 0) {
                primes[i] ++;
                a /= i;
            }
        }
        if (a > 1) primes[a]++;
    }
    long long ret = 1;
    for (auto prime : primes) {
        ret = ret * (prime.second + 1) % MO;    //公式就是每个质数的次数 + 1 累乘
    }
    cout << ret;
    return 0;
}

// 3.  求a的所有约数之和    公式
unordered_map <int, int> primes;
    while(n --) {
        int a;
        cin >> a;
        for (int i = 2; i <= a / i; i ++) {
            while (a % i == 0) {
                primes[i]++;
                a /= i;
            }
        }
        if (a > 1) primes[a] ++;
    }
    
    LL res = 1;
    for (auto p : primes) {
        LL a = p.first, b = p.second;
        LL t = 1;
        while (b -- ) t = (t * a + 1) % MO;
        res = res * t % MO;
    }

//欧几里得算法 辗转相除法
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}