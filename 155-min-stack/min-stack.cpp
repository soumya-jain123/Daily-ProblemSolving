class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int x) {
        int newMin = st.empty() ? x : min(st.top().second, x);
        st.push({x, newMin});
    }
    
    void pop() {
        if(!st.empty())
            st.pop();
    }
    
    int top() {
        if(st.empty())
            return -1;
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty())
            return -1;
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */