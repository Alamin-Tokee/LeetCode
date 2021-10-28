class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        s1;s2;
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        for(;!s1.empty();){
            int x=s1.top();
            s2.push(x);
            s1.pop();
        }
        int val=s2.top();
        s2.pop();
        for(;!s2.empty();){
            int x=s2.top();
            s1.push(x);
            s2.pop();
        }
        return val;
    }
    
    int peek() {
        for(;!s1.empty();){
            int x=s1.top();
            s2.push(x);
            s1.pop();
        }
        int val=s2.top();
        for(;!s2.empty();){
            int x=s2.top();
            s1.push(x);
            s2.pop();
        }
        return val;
    }
    
    bool empty() {
        return s1.empty();
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