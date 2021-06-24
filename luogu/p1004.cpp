#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int row, x, y, val;
int val_matrix[12][12];
int dp[12][12][12][12];
int main() {

    cin >> row >> x >> y >> val;
    while(!(val == 0 && x == 0 && y == 0)) {
        val_matrix[x][y] = val;
        cin >> x >> y >> val;
    }
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= row; j++) {
            for(int m = 1; m <= row; m++) {
                for(int n = 1; n <= row; n++) {
                    int case1 = dp[i - 1][j][m - 1][n];
                    int case2 = dp[i - 1][j][m][n - 1];
                    int case3 = dp[i][j - 1][m - 1][n];
                    int case4 = dp[i][j - 1][m][n - 1];
                    dp[i][j][m][n] = std::max(std::max(case1, case2), std::max(case3, case4)) + val_matrix[i][j] + val_matrix[m][n];
                    if(i == m && j == n) {
                        dp[i][j][m][n] -= val_matrix[i][j];
                    }
                }
            }
        }
    }
    cout << dp[row][row][row][row];
    return 0;
}
