class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q1;
    queue<int> q2;
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int ans;
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
       
        }
        ans=q1.front();
        q1.pop();
        while(q2.size()!=0)
        {
            q1.push(q2.front());
            q2.pop();
       
        }
        return ans;
            
    }
    
    int top() {
        int ans;
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
         ans=q1.front();
        q1.pop();
        
        while(q2.size()!=0)
        {
            q1.push(q2.front());
            q2.pop();
       
        }
        q1.push(ans);
           
       
        
       
         return ans;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */