class MinStack {
private:
    vector<pair<int,int>> minStack;

public:
    MinStack() : minStack() {}
    
    void push(int val) {
        if(minStack.empty()) minStack.emplace_back(val, val);
        else minStack.emplace_back(val, min(val, minStack.back().second));
    }
    
    void pop() {
        minStack.pop_back();
    }
    
    int top() {
        return minStack.back().first;
    }
    
    int getMin() {
        return minStack.back().second;
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
