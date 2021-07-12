class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size(), 1);
        for(int i = 0; i < dp.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

