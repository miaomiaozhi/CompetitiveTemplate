//分解质因数
void get_prime_factors(int a) {
    //i一定都只能是质数 证明略
    for (int i = 2; i <= a / i; i ++) {     //枚举到 根号a 
        if (a % i == 0) {   //假如i是一个约数 那就把将a能整除i多少次 也就是i这个质因子出现的次数
            int cnt = 0;
            while(a % i == 0) {     //计算i出现的次数
                a /= i;
                cnt++;
            }
            printf("%d %d\n", i, cnt);
        }
    }
    if (a > 1) {    //假如最后还有a > 1那这个数就是唯一大于根号a的质因子
        printf("%d %d\n", a, 1);
    }
    cout << endl;
}