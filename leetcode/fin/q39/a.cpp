class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(target + 1);
        dp[0] = {{}};
        for (int i = 0; i < candidates.size(); i++) {
            for (int j = candidates[i]; j <= target; j++) {
                for (int k = 0; k < dp[j - candidates[i]].size(); k++) {
                    auto my_copy = dp[j - candidates[i]][k];
                    my_copy.push_back(candidates[i]);
                    dp[j].push_back(my_copy);
                }
            }
        }
        return dp[target];
    }
};
