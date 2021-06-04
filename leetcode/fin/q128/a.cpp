#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int length = nums.size();
        vector<int>::iterator begin_iter = nums.begin();
        vector<int>::iterator end_iter = nums.end();
        std::sort(begin_iter, end_iter);
        if (length == 0 || length == 1) {
            return length;
        }
        int quick = 1;
        int slow = 0;
        length = 1;
        int max_length = 1;
        while (true) {
            max_length = std::max(max_length, length);
            if (quick == nums.size() - 1) {
                break;
            }
            if (nums[quick] == nums[slow]) {
                quick++;
                slow++;
            } else {
                if (nums[quick] == nums[slow] + 1) {
                    length++;
                    quick++;
                    slow++;
                } else {
                    slow++;
                    quick++;
                    length = 1;
                }
            }
        }
        if(nums[quick] == nums[slow]) {
            return max_length;
        }
        if(nums[quick] == nums[slow] + 1) {
            return std::max(length + 1, max_length);
        }
        return max_length;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3,4, 4, 4, 3};
    cout << s.longestConsecutive(nums);
    return 0;
}


