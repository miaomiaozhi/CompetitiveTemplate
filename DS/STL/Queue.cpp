#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int que[N] , front = 0 , back = -1;

void push (int x) {     //将x推入队列中
    que[++ back] = x;
}

bool empty(){      //判断是否为空
    if (back - front < 0) return true;
    return false;       //假如rear 跟 front相差大于等于零的时候就不为空
}

void pop () {       //删除队首
    ++ front;
}

int Front () {      //返回队首
    return que[front];
}

int main () {
    int n;
    cin >> n;
    while (n --) {
        string a;
        cin >> a;
        int x , tmp;
        if (a == "push") {
            cin >> x;
            push(x);
        }
        else if (a == "front") {
            tmp = Front();
            cout << tmp << endl;
        }
        
        else if (a == "pop") {
            pop();
        }
        else if (a == "empty") {
            if (empty()) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}