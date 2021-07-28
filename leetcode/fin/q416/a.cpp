class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 0) {
            return false;
        }
        if(nums.size() == 1) {
            return false;
        }
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int half_sum = sum / 2;
        if(sum % 2 == 1) {
            return false;
        }
        vector<int> dp = vector<int>(half_sum + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = half_sum; j >= nums[i]; j--) {
                dp[j] = std::max(dp[j], nums[i] + dp[j - nums[i]]);
            }
        }
        if(dp[half_sum] == half_sum) {
            return true;
        }
        return false;
    }
};
