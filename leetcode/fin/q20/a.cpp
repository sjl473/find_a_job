class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) {
            return true;
        }
        if(s.length() == 1) {
            return false;
        }
        stack<char> my_stack;
        my_stack.push('*');
        for (int i = 0; i < s.length(); i++) {
            if(my_stack.top() == '(') {
                if(s[i] == ')') {
                    my_stack.pop();
                    continue;
                }
            }
            if(my_stack.top() == '{') {
                if(s[i] == '}') {
                    my_stack.pop();
                    continue;
                }
            }
            if(my_stack.top() == '[') {
                if(s[i] == ']') {
                    my_stack.pop();
                    continue;
                }
            }
            my_stack.push(s[i]);
        }
        if(my_stack.size() == 1) {
            return true;
        }
        
        return false;
    }
};
