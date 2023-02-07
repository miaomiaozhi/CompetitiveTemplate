//判断质数
#include <iostream>
using namespace std;

//试除法 O(根号n)
int n;
int prime[n], cnt;
int st[n];
/*
i <= a / i 
*/
bool isprime (int a) {
    if (a < 2) return false;
    for (int i = 2; i <= a / i; i ++){  //小细节  为了防止爆int 所以要在判断的时候移向
        if (a % i == 0) return false;
    }
    return true;
}

//埃氏筛法 筛质数 O（nlog（logn））
void E_shaizi () {
    int n , cnt = 0;        //n为范围 上界
    cin >> n;
    int q[n] = {0};
    bool st[n] = {false};
    for (int i = 2; i <= n ; i ++) {
        if (st[i]) continue;
        cnt ++;         //质数的个数
        q[i] = 1;       //哪个是质数
        for (int j = i + i ; j <= n ; j += i) st[j] = true;
    }
    cout << cnt;
}

//线性筛
void n_prime(int n) {
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) prime[cnt++] = i;
        for (int j = 0; prime[j] <= n / i; j ++) {
                st[prime[j] * i] = 1;
                if (i % prime[j] == 0) break;
        }
    }
}