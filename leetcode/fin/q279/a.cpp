class Solution {
public:
    int numSquares(int n) {
        vector<int> dp = vector<int>(n + 1, 0);
        // 1, 0
        // 1, 1
        // 0, 1
        // 0, 0
        for(int i = 1; i <= n; i++) {
            int min_num = INT_MAX;
            for(int j = 1; i - j * j >= 0; j++) {
                min_num = std::min(min_num, dp[i - j * j]);
            }
            dp[i] = min_num + 1;
        }
        return dp[n];
    }
};
