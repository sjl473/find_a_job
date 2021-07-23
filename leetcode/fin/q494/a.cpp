class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int new_tar = (sum + target) / 2;
        if(sum < target || (sum + target) % 2 != 0) {
            return 0;
        }
        vector<int> dp = vector<int>(new_tar + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = new_tar; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[new_tar];
    }
};
