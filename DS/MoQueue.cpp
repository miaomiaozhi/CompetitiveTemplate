/*
    单调队列 ： Monotonous Queue
    mo_queue <int> q(max_len, windows_size);
	默认单调下降队列 即队头是最大的
*/
template <typename T>
struct mo_queue {
    function <bool(T, T)> mo_queue_default_cmp_function = [](T a, T b) {
        return a <= b;
    };
    int head, tail;
    int len, m;     // len ： 队列最大长度   m ：窗口大小
    vector <T> val, q;
    function <bool(T, T)> cmp;

    mo_queue (int len = 100010, int m = 0) :
         m(m), len(len), val(len), q(len), head(0), tail(-1), cmp(mo_queue_default_cmp_function) {}
    mo_queue (function <bool(T, T)> op, int len = 100010, int m = 0) : 
        m(m), len(len), val(len), q(len), head(0), tail(-1), cmp(op) {}
    inline void init() {
        head = 0, tail = -1;
    }
    /*
         _val 表示当前的值， idx 表示当前值对应的下标
        注意是前 m 项和还是 后 m 项和
        队尾 <= 当前即将插入的元素 那就弹出队尾
    */
    inline void push (T _val, int idx) {
        while (head <= tail && q[head] < idx - m + 1) head++;
        while (head <= tail && cmp(val[tail], _val)) tail--;
        q[++tail] = idx;
        val[tail] = _val;
    }
    inline T front() {
        return val[head];
    }
};