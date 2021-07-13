class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int n = nums.size();
        int dp = nums[0];
        result = dp;
        for(int i = 1; i < n; i++) {
            dp = max(dp + nums[i], nums[i]);
            result = max(result, dp);
        }
        return result;
    }
};



