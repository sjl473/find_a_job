class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0) {
            return 0;
        }
        int result = INT_MIN;
        vector<vector<int>> dp = vector<vector<int>>(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for(int i = 1; i <= nums1.size(); i++) {
            for(int j = 1; j <= nums2.size(); j++) {
                if(nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } 
                result = std::max(dp[i][j], result);
            }
        }
        return result;
    }
};



