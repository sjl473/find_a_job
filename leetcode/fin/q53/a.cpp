class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        vector<short> dp = vector<short>(nums.size(), 0);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

