
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) {
            return true;
        }
        if(nums[0] == 0) {
            return false;
        }
        vector<bool> dp = vector<bool>(n + 1, false);
        dp[0] = true;
        dp[1] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                if(nums[j - 1] + j >= i && dp[j] ==  true) {
                    dp[i] = true;
                }
            }
        }
        if(dp[n] == false) {
            return false;
        }
        return true;
    }
};
