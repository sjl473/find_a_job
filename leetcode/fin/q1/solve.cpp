#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return vector<int>();
        }
        for(int i = 0; i <= nums.size() - 1; i++) {
            for(int j = i + 1; j <= nums.size() - 1; j++) {
                if(target == nums.at(i) + nums.at(j)) {
                    return {i, j};
                }
            }
        }
        return {};
    }
    vector<int> twoSum1(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return vector<int>();
        }
        std::unordered_map<int, int> hash_table;
        for(int i = 0; i <= nums.size() - 1; i++) {
            unordered_map<int, int>::const_iterator key_iter = hash_table.find(target - nums[i]);
            if(key_iter != hash_table.end()) {
                return {key_iter->second, i};
            }
            hash_table[nums[i]] = i;
        }
        return {};
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int> vec = {1, 2, 2, 3, 4};
    Solution sol = Solution();
    auto re = sol.twoSum1(vec, 4);
    for(int i = 0; i <= re.size() - 1; i++) {
        cout << re.at(i) << endl;
    }
    return 0;
}
