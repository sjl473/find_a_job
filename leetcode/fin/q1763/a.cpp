#include "iostream"
#include "stack"
#include "unordered_set"
using namespace std;
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length() ;
        if(n == 1 || n == 0) {
            return "";
        }
        stack<std::pair<int, int>> stk;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(i == j) {
                    // pass
                } else {
                    stk.push(make_pair(i, j));
                }
            }
        }
        string result = "";
        int max_left = 0;
        int max_right = 0;
        while(stk.empty() == false) {
            auto temp = stk.top();
            bool flag = true;
            int my_first = std::min(temp.first, temp.second);
            int my_second = std::max(temp.first, temp.second);
            string check = s.substr(my_first, my_second - my_first + 1);
            unordered_set<char> my_set;
            for(int i = 0; i < check.length(); i++) {
                my_set.insert(check[i]);
            }
            for(char i = 'a'; i <= 'z'; i++) {
                if(my_set.count(i) > 0) {
                    if(my_set.count(i - 32) > 0) {

                    } else {
                        flag = false;
                        break;
                    }
                } 
                if(my_set.count(i - 32) > 0) {
                    if(my_set.count(i) > 0) {
                        //
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag == false) {
                //
            } else {
                if(max_right - max_left <= my_second - my_first) {
                    max_right = my_second;
                    max_left = my_first;
                } else {
                    //
                }
            }
            stk.pop();
        }
        if(max_left == 0 && max_right == 0) {
            return "";
        }
        result = s.substr(max_left, max_right - max_left + 1);
        return result;
    }
};



