#include <iostream>
#include <vector>

using namespace std;
vector<int> a(10010);
vector<int> b(10010);
vector<int> g(10010);
vector<int> k(10010);
vector<int> s(10010); // s[i] represents the index of carpet
int main() {
    int n;
    cin >> n; // n represents total number of carpets
    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
        s[i] = i;
    }
    int x, y;
    // x, y are target
    bool is_ok = false;
    cin >> x >> y;
    for(int i = n; i >= 1; i--) {
        if(x >= a[i] && x <= a[i] + g[i] && y <= b[i] + k[i] && y >= b[i]) {
            is_ok = true;
            cout << s[i];
            break;
        }
    }   
    if(is_ok == false) {
        cout << "-1"; 
    }
    return 0;
}
