
#include "iostream"
#include "vector"
using namespace std;
void printer(vector<vector<int>> storage, int i, int j) {
    if(i == j) {
        cout << "a" << i;
    } else {
        cout << "<";
        printer(storage, i, storage[i][j]);
        printer(storage, storage[i][j] + 1, j);
        cout << ">";
    }
}
int main() {
    vector<int> v = {30,35,15,5,10,20,25};
    int n = v.size() - 1;
    vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> storage = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i <= n; i++) {
        dp[i][i] = 0;
    }
    for(int i = n; i >= 1; i--) {
        for(int j = i; j <= n; j++) {
            if(j == i) {
                dp[i][j] = 0;
            } else {
                for(int k = i; k <= j - 1; k++) { // i + 1 ??
                    if(dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j] < dp[i][j]) {
                        dp[i][j] = dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j];
                        storage[i][j] = k;
                    }
                }
            }
        }
    }
    int result = dp[1][n];
    cout << result << endl;
    printer(storage, 1, n);
}
