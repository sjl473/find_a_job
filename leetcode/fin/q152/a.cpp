class Solution {
public:
int three_max(int a, int b, int c) {
    return std::max(std::max(a, b), c);
}
int three_min(int a, int b, int c) {
    return std::min(std::min(a, b), c);
}
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp = vector<vector<int>>(2, vector<int>(n, 0));
    dp[0][0] = nums[0];
    dp[1][0] = nums[0];
    for(int i = 1; i < n; i++) {
                dp[1][i] = three_min(nums[i], nums[i] * dp[0][i - 1], nums[i] * dp[1][i - 1]);
        dp[0][i] = three_max(nums[i], nums[i] * dp[0][i - 1], nums[i] * dp[1][i - 1]);

    }
    return *std::max_element(dp[0].begin(), dp[0].end());
}
};
