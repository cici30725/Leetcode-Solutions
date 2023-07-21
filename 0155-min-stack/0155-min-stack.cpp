class MinStack {
public:
    stack<int> main_stack;
    stack<int> min_stack;
        
    MinStack() {
        return;
    }
    
    void push(int val) {
        main_stack.push(val);
        if(min_stack.empty())
            min_stack.push(val);
        else if(val <= min_stack.top()){
            min_stack.push(val);
        }
    }
    
    void pop() {
        int cur = main_stack.top();
        main_stack.pop();
        if(!min_stack.empty() && min_stack.top() == cur)
            min_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
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