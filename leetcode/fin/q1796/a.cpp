#include "iostream"
#include "cstring"
using namespace std;
class Solution {
public:
    int secondHighest(string s) {
        cout << s << endl;
        int max_val = 0;
        int second_max_val = 0;
        for(int i = 0; i < s.length(); i++) {
            if(isdigit(s[i])) {
                max_val = std::max(max_val, s[i] - '0');
            }
        }
        cout << max_val << endl;
        bool flag = false;
        s.erase(std::remove(s.begin(), s.end(), max_val + '0'), s.end());
        for(int i = 0; i < s.length(); i++) {
            if(isdigit(s[i])) {
                flag = true;
                second_max_val = std::max(second_max_val, s[i] - '0');
            }
        }
        if(flag == false) {
            return -1;
        }
        return second_max_val;
    }
};
