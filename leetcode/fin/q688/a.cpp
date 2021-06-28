class Solution {
public:
    bool TestPalindrome(string& s) {
        if(s.length() == 0 || s.length() == 1) {
            return true;
        }
        bool flag_b = false;
        if((s.length() & 1) == 0) {
            // even
            int begin = 0;
            int end = s.length() - 1;
            while(true) {
                if(begin > end) {
                    flag_b = true;
                    break;
                }
                if(s[begin] == s[end]) {
                    // pass
                } else {
                    break;
                }
                begin++;
                end--;
            }
        } else {
            // odd
            int begin = 0;
            int end = s.length() - 1;
            while(true) {
                if(begin == end) {
                    flag_b = true;
                    break;
                }
                if(s[begin] == s[end]) {
                    // pass
                } else {
                    break;
                }
                begin++;
                end--;
            }
        }
        if(flag_b == true) {
            return flag_b;
        }
        return false;
    }
    bool validPalindrome(string s) {
        if(s.length() == 0) {;
            return true;
        }
        if(s.length() == 1) {
            return true;
        }
        if(s.length() == 2) {
            return true;
        }
        int begin = 0;
        int end = s.length() - 1;
        while(begin < end) {
            if(s[begin] != s[end]) {
                break;
            }
            ++begin;
            --end;
        }
        if(begin >= end) {
            return true;
        }
        bool flag_a = false;
        bool flag_b = false;
        string c1 = s.substr(begin + 1, end - begin);
        string c2 = s.substr(begin, end - begin);
        if(TestPalindrome(c1) == true || TestPalindrome(c2) == true) {
            return true;
        }
        return false;
    }
};
