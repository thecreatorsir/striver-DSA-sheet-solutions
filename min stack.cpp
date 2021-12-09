class MinStack {
public:
    /** initialize your data structure here. */
    stack <int> s;
    stack <int> sm;
    int mn = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(s.empty()) sm.push(val);
        else{
            if(val<sm.top()){
                sm.push(val);
            }else{
                sm.push(sm.top());
            }
        }
        s.push(val);  
    }
    
    void pop() {
        if(!s.empty()){
            s.pop();
            sm.pop();
        }
    }
    
    int top() {
        return s.top();
        
    }
    
    int getMin() {
        return sm.top();
    }
};
