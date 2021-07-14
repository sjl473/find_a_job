class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0) {
            return 0;
        }
        if(s.length() == 1) {
            return 0;
        }
        stack<int> stk;
        vector<bool> v = vector<bool>(s.length(), false);
        for(int i = 0; i < s.length(); i++) {
            if(stk.empty() == true) {
                stk.push(i);
                continue;
            }
            if(s[i] == ')' && s[stk.top()] == '(') { 
                v[i] = true;
                v[stk.top()] = true;
                stk.pop();
            } else {
                stk.push(i);
            }
        }

//         vector<int> dp = vector<int>(v.size(), 0);  
//         int temp = 0;
//         if (v[0] == true) {
//             dp[0] = 1;
//             temp = max(dp[0], temp);
//         }
//         for (int i = 1; i < v.size(); i++) {
//             if (v[i] == true) {
//                 if (v[i-1] ==true) {
//                     dp[i] = dp[i-1] + 1;
//                     temp = max(dp[i], temp);
//                 }else{
//                     dp[i] = 1;
//                     temp = max(dp[i], temp);
//                 }
//             }
//             else {
//                 dp[i] = 0;
//                  temp = max(dp[i], temp);
//             }
//         }
        int dp = 0;
        int m = 0;
        for(int i = 2; i <= v.size(); i++) {
            if(v[i - 1] == true && v[i - 2] == true) {
                dp++;
            } else {
                dp = 0;
            }
            m = std::max(m, dp);
        }
        if(m == 0) {
            return m;
        }
        return m + 1;
    }
};





