class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rs = s;
        std::reverse(rs.begin(), rs.end());
        vector<vector<int>> dp = vector<vector<int>>(rs.length() + 1, vector<int>(s.length() + 1, 0));
        for(int i = 1; i <= rs.length(); i++) {
            for(int j = 1; j <= s.length(); j++) {
                if(s[j - 1] == rs[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i -  1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[rs.length()][s.length()];
    }
};


