class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(target + 1);
        std::sort(candidates.begin(), candidates.end());
        dp[0] = {{}};
        set<vector<int>> my_set;
        for (int i = 0; i < candidates.size(); i++) {
            for (int j = target; j >= candidates[i]; j--) {
                for (int k = 0; k < dp[j - candidates[i]].size(); k++) {
                    auto my_copy = dp[j - candidates[i]][k];
                    my_copy.push_back(candidates[i]);
                    if(my_set.find(my_copy) == my_set.end()) {
                        dp[j].push_back(my_copy);
                        my_set.insert(my_copy);
                    } else {
                        
                    }
                }
            }
        }
        return dp[target];
    }
};


