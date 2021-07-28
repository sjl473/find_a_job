class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // target = a + b + c - d - e - f
        // sum = a + b + c + d + e + f
        // target + sum = 2 * pos
        // pos = (target + sum) / 2
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            if(std::abs(target) != nums[0]) {
                return 0;
            } else {
                return 1;
            }
        }
        int acc = std::accumulate(nums.begin(), nums.end(), 0);
        if(acc < target) {
            return 0;
        } 
        double pos = static_cast<double>(target + acc) / 2;
        if(static_cast<int>(pos) - pos < 0) {
            return 0;
        }
        pos = static_cast<int>(pos);
        vector<int> dp = vector<int>(pos + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = pos; j >= nums[i]; j--) {
                dp[j] = std::max(dp[j], dp[j - nums[i]] + dp[j]);
            }
        }
        return dp.back();
    }
};
