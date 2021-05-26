class Solution {
public:
    int reverse(int x) {
        long a = static_cast<int>(x);
        if(x != a) {
            return 0;
        }
        bool f = false;
        if(a <= 0) {
            f = true;
            a = -a;
        }
        string s = to_string(a);
        std::reverse(s.begin(), s.end());
        a = std::stol(s);
        if(a >= 2147483648) {
            return 0;
        }
        if(f == true) {
            return -static_cast<int>(a);
        }
        return static_cast<int>(a);
    }
};