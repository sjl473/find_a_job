//bool isMatch2(std::string s, std::string p) {
//    if (p.empty()) {
//        return s.empty();
//    }
//
//    // 前面加某一相同字符，
//    // 防止 (ab, c*ab) 这样的匹配，
//    // 避免复杂的初始化操作
//    s = " " + s;
//    p = " " + p;
//    int m = s.size(), n = p.size();
//
//    // 定义记忆数组，并初始化为false
//    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
//
//    // 设添加的字符为真
//    dp[0][0] = true;
//
//    // 记忆数组能保持字符串上一个字符的状态
//    // 因此可以对下一个字符进行判断
//    for (int i = 1; i < m + 1; i++) {
//        for (int j = 1; j < n + 1; j++) {
//            // 不带 '*' 号时的匹配
//            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
//                dp[i][j] = dp[i - 1][j - 1];
//            } else if (p[j - 1] == '*') {
//                // 考虑 '*' 时的两种情况
//                if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
//                    dp[i][j] = dp[i][j - 2];
//                } else {
//                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
//                }
//            }
//        }
//    }
//
//    // 返回最后字符的匹配状态
//    return dp[m][n];
//}
//
//作者：OOOffer
//        链接：https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/hui-su-fa-dong-tai-gui-hua-by-luo-jing-yu-yu/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。