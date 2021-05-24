// pwwkew
// output 3


#include "iostream"
#include "unordered_map"

using namespace std;
class Solution {
public:
    static int lengthOfLongestSubString(string s) {
        if(s.length() == 0) {
            return 0;
        }
        unordered_map<char, int> hash_map;
        int max_length = 0;
        int current_length = 0;
        int start_index = 0;
        for(int i = 0; i < s.length(); i++) {
            // to check whether s[i] is in the hash map
            if(hash_map.find(s[i]) == hash_map.end()) {
                current_length++;
                hash_map[s[i]] = i; // todo: ?
            } else {
                if(current_length > max_length) {
                    max_length = current_length;
                }
                start_index = max(hash_map[s[i]], start_index);
                if(hash_map[s[i]] < start_index) {
                    cout << "fuck" ;
                }
                current_length = i - start_index;
                hash_map[s[i]] = i;
            }
        }
        if(current_length > max_length) {
            max_length = current_length;
        }
        return max_length;
    }

};

int main() {
    Solution::lengthOfLongestSubString("fxffxf");
}