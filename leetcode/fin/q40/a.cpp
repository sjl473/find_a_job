class Solution {
public:
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    int size = candidates.size();
    if (size == 0) return result;
    vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
    unordered_set<string> my_set;
    std::sort(candidates.begin(), candidates.end());
    dp[0].push_back(vector<int>());
    for (int i = 1; i <= target; ++i) {
        for (int j = 0; j < size && candidates[j] <= i; ++j) {
            for (int k = 0; k < dp[i - candidates[j]].size(); ++k) {
                vector<int> temp = dp[i - candidates[j]][k];
                temp.push_back(candidates[j]);
                sort(temp.begin(), temp.end());
                string s = "";
                for(int l = 0; l < temp.size(); l++) {
                    s += std::to_string(temp[l]);
                }
                if(my_set.find(s) == my_set.end()) {
                    dp[i].push_back(temp);
                    my_set.insert(s);
                } 
            }
        }
    }
    return dp[target];
}
};
