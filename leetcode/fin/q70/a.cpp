class Solution {
public:
    int climbStairs(int n) {
        vector<int> nums = vector<int>();
        nums.push_back(1);
        nums.push_back(2);
        vector<int> dp = vector<int>(n + 1, 0);
        dp[0] = 1;
        for(int j = 1; j <= n; j++) {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] <= j) {
                    dp[j] = std::max(dp[j], dp[j - nums[i]] + dp[j]);
                } 
            }
        }
        return dp.back();
    }
};
