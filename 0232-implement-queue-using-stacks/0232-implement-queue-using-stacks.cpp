class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }

    void back(){
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int ans;
            while(s1.size()!=1){
                s2.push(s1.top());
                s1.pop();
            }
            ans=s1.top();
            s1.pop();
            back();        
        return ans;   
    }
    
    int peek() {
        int ans;
            while(s1.size()!=1){
                s2.push(s1.top());
                s1.pop();
            }
            ans=s1.top();
            s2.push(s1.top());
            s1.pop();
            back();
        return ans;   
    }
    
    bool empty() {
        return s1.empty() && s2.empty();    
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