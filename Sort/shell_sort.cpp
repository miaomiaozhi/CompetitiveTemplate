#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int q[N] , n;

void shell_sort (int q[] , int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i ++) {
            for (int j = i - gap; j >= 0 && q[j] > q[j + gap]; j -= gap) {
                swap (q[j] , q[j + gap]);
            }
        }
    }
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> q[i];
    shell_sort(q , n);
    for (int i = 0; i < n; i ++) cout << q[i] << " ";
    return 0;
}