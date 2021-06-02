class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return vector<int>();
        }
        std::map<int, int> hash_table;
        for(int i = 0; i <= nums.size() - 1; i++) {
            map<int, int>::const_iterator key_iter = hash_table.find(target - nums[i]);
            if(key_iter != hash_table.end()) {
                return {key_iter->second + 1, i + 1};
            }
            hash_table[nums[i]] = i;
        }
        return {};
    }
};