
#include <cstdio>
#include <iostream>
using namespace std;
int v;
int num;
int dp[20010];
int a[40];
int main() {
    int i, j;
    cin >> v >> num;
    for(int i = 1; i <= num; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= num; i++) {
        for(int j = v; j >= a[i]; j--) {
            if(dp[j] < dp[j - a[i]] + a[i]) {
                dp[j] = dp[j - a[i]] + a[i];
            }
        }
    }
    cout << v - dp[v] << endl;
}
