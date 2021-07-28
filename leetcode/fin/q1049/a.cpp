class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size() == 0) {
            return 0;
        }
        if(stones.size() == 1) {
            return stones[0];
        }
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        int half_sum = sum / 2;

        vector<int> dp = vector<int>(half_sum + 1, 0);
        for(int i = 0; i < stones.size(); i++) {
            for(int j = half_sum; j >= stones[i]; j--) {
                dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        int result_a = 0;
        for(int i = dp.size() - 1; i >= 0; i--) {
            if(dp[i] != 0) {
                result_a = dp[i];
                break;
            }
        }
        int result_b = sum - result_a;
        return abs(result_a - result_b);
    }
};
