//while(遍历s) {
//index = hash_map[s[i]]
//if(can found s[i] in hash map且index 属于[left, right]) {
//  left = index + 1;
//}
//has_map[s[i]] = right
//// right++是遍历条件
//}
#include "vector"
#include "iostream"

using namespace std;

int main() {
    string s = "xxxxx";
    vector<int> v(128, -1);
    int max_right = 0;
    int max_left = 0;
    int right = 0;
    int left = 0;
    for (int i = 0; i <= s.length() - 1; i++) {
        right = i;
        int prev_index = v[s[i]];
        if (prev_index <= right && prev_index >= left && prev_index != -1) {
            left = prev_index + 1;
        }
        v[s[i]] = right;
//        cout << right << " " << left << endl;
        if (max_right - max_left <= right - left) {
            max_left = left;
            max_right = right;
        }
    }
    cout << max_right << " " << max_left << endl;
    for (int i = max_left; i <= max_right; i++) {
        cout << s[i] << endl;
    }

}

//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        if (s.length() == 0) {
//            return 0;
//        }
//        vector<int> v(128, -1);
//        int max_right = 0;
//        int max_left = 0;
//        int right = 0;
//        int left = 0;
//        for (int i = 0; i <= s.length() - 1; i++) {
//            right = i;
//            int prev_index = v[s[i]];
//            if (prev_index <= right && prev_index >= left && prev_index != -1) {
//                left = prev_index + 1;
//            }
//            v[s[i]] = right;
//
//            if (max_right - max_left <= right - left) {
//                max_left = left;
//                max_right = right;
//            }
//        }
//        return max_right - max_left + 1;
//    }
//};