#include <iostream>
#include <algorithm>
using namespace std;
int dp[55][55][55][55];
int matrix[55][55];
int n;
int m;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> matrix[i][j];   
        }
    }
    for(int i = 1; i <= n; i++) {
       for(int j = 1; j <= m; j++) {
           for(int k = i + 1; k <= n; k++) {
               for(int l = 1; l <= m; l++) {
                   dp[i][j][k][l] = std::max(std::max(dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1]), 
                   std::max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1])) + matrix[i][j] + matrix[k][l];
               }
           }
       } 
    }   
    cout << dp[n - 1][m][n][m - 1] << endl;
    return 0;
}
