// 物品个数3402
// 物品重量400
// 物品价值100
// 背包重量12880
#include "vector"
#include "iostream"
using namespace std;
int main() {
    int num = 0;
    int max_size = 0;
    cin >> num >> max_size;
    vector<int> weight_list = vector<int>(num, 0);
    vector<int> value_list = vector<int>(num, 0);
    vector<int> dp = vector<int>(12881, 0);
    for(int i = 0; i < num; i++) {
        cin >> weight_list[i] >> value_list[i];
    }
    for(int i = 0; i < num; i++) {
        for(int j = max_size; j >= weight_list[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - weight_list[i]] + value_list[i]);
        }
    }
    cout << dp[max_size];
}
