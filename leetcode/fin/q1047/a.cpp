#include "iostream"
#include "stack"
#include "unordered_set"
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(int i = 0; i < s.length() ;i++) {
            if(stk.empty() == true) {
                stk.push(s[i]);
                continue;
            }
            if(stk.top() == s[i]) {
                stk.pop();
                continue;
            } else {
                stk.push(s[i]);
            }
        }
        if(s.empty() == true) {
            return "";
        }
        string result = "";
        while(stk.empty() == false) {
            result += stk.top();
            stk.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
