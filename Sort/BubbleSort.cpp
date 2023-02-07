// 冒泡排序
/*
10
6 5 2 1 1 7 8 0 9 1
*/

#include <iostream>

using namespace std;

const int N = 1e5 +10;
int q[N];
int n;

void print(int *q , int n) {
	for (int i = 0; i < n ; i ++) cout << q[i] << " ";
	cout << endl;
}

void bubble_sort (int q[] , int n) {
	int cnt = 0;
	for (int i = n - 1; i >= 0; i --) {
		int flag = 0;		//第一种优化：找到第一次没有进行邻近交换的退出
		int pos = i;		//第二种优化：找到后面已经有序的排序 然后枚举的后端点进行跳跃
		for (int j = 1 ; j <= i ; j ++) {
			if (q[j - 1] > q[j]) {
				swap (q[j - 1] , q[j]);
				flag = 1;
				pos = j;
				cnt ++;
			}
		}
		if (!flag) break;
		i = pos;
	}
}

int main(){
	scanf ("%d" , &n);
	for (int i = 0 ; i < n ; i++) scanf("%d" , &q[i]);
	bubble_sort(q , n);
	cout << endl;
	print(q , n);
}