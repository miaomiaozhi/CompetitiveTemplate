#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int stc[N] , tt = 0;        //当tt为0是代表栈为空 tt一定是先自加 也就是 ++tt 
                            // 不然tt就会指向空的地方 也就是非空的tt一定指向栈顶！！！
void push(int x) {      //入栈
    stc[++ tt] = x;
}

void pop () {       //将栈顶元素删除
    -- tt;
}

bool empty() {      //判断是不是空栈
    if (tt == 0) return true;
    else return false;
}

int top () {    //输出栈顶元素
    return stc[tt];
}

int main () {
    int n;
    cin >> n;
    while (n --) {
        string a;
        int x;
        int tmp;
        cin >> a;
        if (a == "push") {
            cin >> x;
            push(x);
        }
        else if (a == "top") {
            tmp = top();
            cout << tmp << endl;
        }
        
        else if (a == "pop") {
            pop();
        }
        
        else {
            if (empty()) cout << "YES\n";
            else if (!empty()) cout << "NO\n";
        }
    }
    return 0;
}
