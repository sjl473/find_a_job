#include <iostream>
using namespace std;
// n zongrenshu
// a nenglizhi shuzu
// kk yaoxuanduoshaoren 
// d zuida jiange
// (1 <= k <= 10, 1 <= d <= 50)
int three_min(long long a,long long b,long long c) {
    return std::min(a, std::min(b,c));
}
int three_max(long long a,long long b,long long c)
{
    return std::max(a,std::max(b,c));
}
int getBestTeams(int n, int a[], int kk, int d) {
    long long result = 0;
    std::vector<vector<int>> dp_max = vector<vector<int>>(kk + 1, vector<int>(n + 1, 0));
    std::vector<vector<int>> dp_min = vector<vector<int>>(kk + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++) {
        dp_max[1][i] = a[i];
        dp_min[1][i] = a[i];
    }
    for(int i = 1; i <= kk; i++) {
        for(int j = 1; j <= n; j++) {
            for(int p = 1; p <= d; p++) {
                if(i - p <= n && i - p >= 1) {
                    dp_min = three_min(dp_min[i][j], dp_min[i-1][j-p]*a[j],dp_max[i-1][j-p]*a[j]);
                    dp_max = three_max(dp_max[i][j], dp_min[i-1][j-p]*a[j],dp_max[i-1][j-p]*a[j]);
                }
            }
            result = std::max(result, dp[kk][i]);
        }
    }
    return result;
}
