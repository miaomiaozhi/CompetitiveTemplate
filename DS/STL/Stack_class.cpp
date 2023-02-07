#include <bits/stdc++.h>
using namespace std;
class Stack {
    private:
        int* data;
        int Max;
        int top;
        void intiStack() {
            data = new int(Max);
            top = -1;
        }
        // void intiStack(int t) {
        //     data = new int(Max);
        //     top = t;
        // }
    public:
        Stack() {
            Max = 10;
            intiStack();
        }
        Stack(int size) {
            Max = size;
            intiStack();
        }
        ~Stack() {
            delete data;
        }
        bool empty() {
            return top == -1;
        }
        bool isfull() {
            return top == Max - 1;
        }
        void push(int x) {
            data[++top] = x;
        }
        int pop() {
            int ret = data[top--];
            return ret;
        }
        int size() {
            return top + 1;
        }
};

int main () {
    Stack stack;
    stack.push(5);
    for (int i = 0; i < 10; i ++) stack.push(1);
    
    cout << stack.size() << ' ';
    while (!stack.empty()) {
        cout << stack.pop() << ' ';
    }
    stack.push(1);
    ~stack;
    return 0;
}