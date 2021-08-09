class MyQueue {
public:

    stack<int> in;
    stack<int> out;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(out.empty() == true) {
            while(in.empty() == false) {
                out.push(in.top());
                in.pop();
            }
        }
        int res = out.top();
        out.pop();
        return res;
    }
    int peek() {
        int res = this->pop();
        out.push(res);
        return res;
    }
    bool empty() {
        if(out.empty() == true && in.empty() == true) {
            return true;
        }
        return false;
    }
};


