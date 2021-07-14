class Solution {
public:
    int jump(vector<int>& nums) {
        int s = nums.size();
        vector<int> dp = vector<int>(s + 1,  INT_MAX - 10);
        dp[0] = 0;
        dp[1] = 0;
    
        for(int i = 1; i <= s; i++) {
            for(int j = 1; j < i; j++) {
                if(nums[j - 1] + j >= i) {
                    dp[i] = std::min(dp[j] + 1, dp[i]);
                }
            }
        }   
        return dp[s];     
    }
};
// dp[j] = dp[j - 1] + 1 / dp[j - 2] + 1 / dp[j - 3] + 1 / 
// dp[j] = dp[j - 3] + 1 -> v[j - 3] >= 3
// if v[i - x] >= x and 0 <= x <= i
//     dp[i] = dp[i - x] + 1
