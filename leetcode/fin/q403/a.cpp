class Solution {
    public:
    bool canCross(vector<int> stones) {
        vector<vector<bool>> dp =
            vector<vector<bool>>
            (stones.size() + 1, vector<bool>(stones.size() + 1, false));
        dp[0][0] = true;
        if(stones[1] == 1) {
            dp[1][1] = true;
        } else {
            return false;
        }
        for(int i = 1; i <= stones.size(); i++) {
            for(int j = 1; j < i; j++) {
                int step = stones[i - 1] - stones[j - 1];
                if(step <= j) {
                    dp[i][step] = dp[j][step - 1] || dp[j][step] || dp[j][step + 1];
                }
            }
        }
        for(int i = 0; i <= stones.size(); i++) {
            if(dp[stones.size()][i] == true) {
                cout << i << endl;
                return true;
            }
        }
        return false;
    }
};

