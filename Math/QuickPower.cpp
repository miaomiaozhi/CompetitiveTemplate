#include <iostream>
using namespace std;

//O（logn）地计算出 a 的 b 次方 模上 P

当n b 互质的时候，可以用快速幂求逆元：
a / b ≡ a * x (mod n)
两边同乘b可得 a ≡ a * b * x (mod n)
即 1 ≡ b * x (mod n)
同 b * x ≡ 1 (mod n)
由费马小定理可知，当n为质数时
b ^ (n - 1) ≡ 1 (mod n)
拆一个b出来可得 b * b ^ (n - 2) ≡ 1 (mod n)
故当n为质数时，b的乘法逆元 x = b ^ (n - 2)

当n不是质数时，可以用扩展欧几里得算法求逆元：
a有逆元的充要条件是a与p互质，所以gcd(a, p) = 1
假设a的逆元为x，那么有a * x ≡ 1 (mod p)
等价：ax + py = 1
exgcd(a, p, x, y)


/*
两个数a ，b
假如a能整除b记作  b|a
且b p 都是质数 那么就有a / b 同余于 a * x  mod p， x被称为b的逆元
也就是将除法转换成乘法的一个操作 当b p互质时 此时
x = b^（p - 2）(mod p)
本质上就是计算b^（p - 2）(mod p)
*/

void quickMid(int a, int b, int p) {
    long long ret = 1;
    while (b) {
        if (b & 1) {    //假如二进制位有1   那么就将ret乘上贡献并且取余 
            ret = ret * a % p;
        }
        a = (long long)a * a % p;        //然后计算每一次的贡献tmp^(2 ^ k)
        b >>= 1;        //b右移一位
    }
    cout << (ret % p) << endl;
}

//  快速幂求逆元 输入的格式就是b n  其中c = n - 2
int quickPower_inverseElement(int b, int c, int n) {
    int ret = 1;
    while (c) {
        if (c & 1) ret = (long long)ret * b % n;
        b = (long long)b * b % n;
        c >>= 1;
    }
    return ret % n;
}

int main () {
    int n;
    cin >> n;
    while (n --) {
        int a, b, p;
        cin >> a >> b >> p;
        quickMid(a, b, p);
    }
    return 0;
}