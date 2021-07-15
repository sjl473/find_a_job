class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_set<int> m;
        unordered_set<int> mm;
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i]) > 0) {
                mm.insert(nums[i]);
            } else {
                m.insert(nums[i]);
            }
        }
        int sum = 0;
        for(auto iter = m.begin(); iter != m.end(); iter++) {
            if(mm.count(*iter) > 0) {
                // pass
            } else {
                sum += *iter;
            }
        }
        return sum;
    }
};
