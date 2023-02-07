// 逆序对的数目

// 给定一个长度为n的整数数列，请你计算数列中的逆序对的数量。

// 逆序对的定义如下：对于数列的第 i 个和第 j 个元素，如果满足 i < j 且 a[i] > a[j]，则其为一个逆序对；否则不是。

// 输入格式
// 第一行包含整数n，表示数列的长度。

// 第二行包含 n 个整数，表示整个数列。

// 输出格式
// 输出一个整数，表示逆序对的个数。

// eg :输入6
// 2 3 4 5 6 1
//输出 5

#include <iostream>

using namespace std;
const int N = 1e5 +10;

int q[N];
int n;

int numbers(int q[] , int l , int r)
{
    int j = r , i = l;
    int result = 0;
    
    if(l >= r) return 0;
    
    while (i < j)
    {
        for (i ; i < j ; i++)
            if(q[i] > q[j]) result ++;
        
        i = l;
        j--;
    }
    
    return result;
}

int main ()
{
    scanf("%d" , &n);
    
    for (int i = 0 ; i < n ; i ++) scanf("%d" , &q[i]);
    
    printf("%d" , numbers(q , 0 , n -1));
    
}