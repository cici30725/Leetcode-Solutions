class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        sk.push(val);
        if(min_sk.empty() || val <= min_sk.top())
            min_sk.push(val);
    }
    
    void pop() {
        int cur = sk.top();
        sk.pop();
        if(cur==min_sk.top())
            min_sk.pop();
    }
    
    int top() {
        return sk.top();
    }
    
    int getMin() {
        return min_sk.top();
    }
private:
    stack<int> sk;
    stack<int> min_sk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */