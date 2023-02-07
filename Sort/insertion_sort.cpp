//插入排序

#include <iostream>
#include <vector>
using namespace std;

void insertion_sort (vector <int> &q) {
    int n = q.size();
    for (int i = 1 ; i < n ; i ++) {
        int tmp = q[i] , j = i - 1;
        for (j = i - 1; j >= 0 && q[j] > tmp ; j --) {
            q[j + 1] = q[j];    
        }
        q[j + 1] = tmp;
    }
}

int main () {
    vector <int> q;
    int n;
    cin >> n;
    for (int i = 0 , t; i < n ; i ++) {
        cin >> t;
        q.push_back(t);
    }
    insertion_sort(q);
    for (int &i : q) cout << i << " ";
    return 0;
}