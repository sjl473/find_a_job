class MyStack {
public:
    queue<int> q;
    void push(int x) {
       q.push(x); 
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q.size() == 0) {
            return 0;
        }
        if(q.size() == 1) {
            int temp = q.front();
            q.pop();
            return temp;
        }
        int my_size = q.size();
        for(int i = 2; i <= my_size; i++) {
            int temp = q.front();
            q.push(temp);
            q.pop();
        }
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        int temp = this->pop();
        q.push(temp);
        return temp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q.size() == 0) {
            return true;
        }
        return false;
    }
};


