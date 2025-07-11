class MinStack {
public:
    stack<pair<int, int>> x;

    MinStack() {}

    void push(int val) {
        if (x.empty()) {
            x.push({val, val});
        } else {
            x.push({val, min(x.top().second, val)});
        }
    }

    void pop() {
        x.pop();
    }

    int top() {
        return x.top().first;
    }

    int getMin() {
        return x.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */