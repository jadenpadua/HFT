class MyQueue {

private:
    void transferStacks(stack<int>& sourceStack, stack<int>& destStack) {
        while(sourceStack.size() > 0) {
            int element = sourceStack.top(); sourceStack.pop();
            destStack.push(element);    
        }
    }
public:
    stack<int> s1_;
    stack<int> s2_;
    MyQueue() : s1_(), s2_() {}
    
    void push(int x) {
        transferStacks(s2_, s1_);
        s1_.push(x);
    }
    
    int pop() {
        transferStacks(s1_, s2_);
        int popped = s2_.top(); s2_.pop();
        return popped;
    }
    
    int peek() {
        transferStacks(s1_, s2_);
        int popped = s2_.top();
        return popped;
    }
    
    bool empty() {
        return s1_.size() == 0 && s2_.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
