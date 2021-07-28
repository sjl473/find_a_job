class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount < 0) {
            return 0;
        }
        if(amount == 0) {
            return 1;
        }
        vector<int> dp = vector<int>(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] = std::max(dp[j], dp[j - coins[i]] + dp[j]);
            }
        }
        return dp[amount];
    }
};
