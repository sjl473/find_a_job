
#include <cstring>
#include <iostream>

using namespace std;

int main(void) {
    string s = "dfhsjBBACABB";
    int max_len = 0;
    int len = s.length();
    int max_left = 0;
    int max_right = 0;
    // even
    // a b c d e f
    // 0 1 2 3 4 5
    //  * * * * *
    //  0 1 2 3 4
    for (int i = 0; i < len - 1; i++) {
        int le = i - 0 + 1;
        int re = len - i - 1;
        int d = std::min(le, re);
        for (int j = 1; j <= d; j++) {
            if (s[j + i] == s[i - j + 1] && j + i != i - j + 1) {
                int temp_len = j + i - i + j - 1 + 1;
                if (max_len >= temp_len) {
                    // pass
                } else {
                    max_len = temp_len;
                    max_right = i + j;
                    max_left = i - j + 1;
                }
            } else {
                break;
            }
        }
    }
//     odd
//     x x * x x
//     0 1 2 3 4 5 6
    for (int i = 0; i < len; i++) {
        int le = i - 0;
        int re = len - i - 1;
        int d = std::min(le, re);
        for (int j = 1; j <= d; j++) {
            if (s[j + i] == s[i - j] && j + i != i - j) {
                // pass

                int temp_len = i + j - i + j + 1;
                if (max_len >= temp_len) {
                    // pass
                } else {
                    max_len = temp_len;
                    max_right = i + j;
                    max_left = i - j;
                }
            } else {
                break;
            }
        }
    }
    cout << max_len << endl;
    cout << max_left <<  " " << max_right << endl;
    s.substr(max_left, max_right - max_left + 1);
    return 0;
}