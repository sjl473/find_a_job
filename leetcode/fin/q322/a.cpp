class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0) {
            return -1;
        }
        if(amount == 0) {
            return 0;
        }
        if(coins.size() == 0) {
            return -1;
        }
        vector<int> dp = vector<int>(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; j++) {
                if(dp[j - coins[i]] == INT_MAX) {
                } else {
                    dp[j] = std::min(dp[j], 1 + dp[j - coins[i]]);
                }
            }
        }
        if(dp.back() == INT_MAX) {
            return -1;
        }
        return dp.back();
    }
};
