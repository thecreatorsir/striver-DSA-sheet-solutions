//stack using two queues
class MyStack {
    queue<int> q1;
    queue<int> q2;
    int tp=-1;
public:
    void push(int x) {
        q1.push(x);
        tp = x;
    }
    
    int pop() {
        while(q1.size()!=1){
            q2.push(q1.front());
            tp = q1.front();
            q1.pop();
        }
        int ele = q1.front();
        q1.pop();
        queue<int> temp = q1;
        q1 = q2;
        q2=temp;
        return ele;
    }
    
    int top() {
        return tp;
    }
    
    bool empty() {
        return q1.empty();
    }
};

//stack using one queue
class MyStack {
    queue<int> q;
    int tp=-1;
public:  
    void push(int x) {
        q.push(x);
        tp = x;
    }
    int pop() {
        int sz = q.size();
        while(sz!=1){
            q.push(q.front());
            tp = q.front();
            q.pop();
            sz--;
        }
        int ele = q.front();
        q.pop();
        return ele;
    }
    int top() {
        return tp;
    }
    bool empty() {
        return q.empty();
    }
};
