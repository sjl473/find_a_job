#include "iostream"
#include "vector"
using namespace std;

int main() {
    long long max_num;
    long long max_time;
    cin >> max_time >> max_num;
    vector<long long> dp = vector<long long>(max_time + 1, 0);
    vector<long long> value_list = vector<long long>(max_num, 0);
    vector<long long> time_list = vector<long long>(max_num, 0);
    for(int i = 1; i <= max_num; i++) {
        cin >> time_list[i - 1] >> value_list[i - 1];
    }
    for(long long i = 0; i < max_num; i++) {
        for(long long j = time_list[i]; j <= max_time; j++) {
            dp[j] = std::max(dp[j], dp[j - time_list[i]] + value_list[i]);
        }
    }
    cout << dp.back();
