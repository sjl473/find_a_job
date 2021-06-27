class Solution {
public:
    int hammingDistance(int x, int y) {
        int counter = 0;
        string s1 = std::bitset<10000>(x).to_string();
        string s2 = std::bitset<10000>(y).to_string();
        cout << s1 << endl;
        cout << s2 << endl;
        for(int i = 0; i <=  s1.length() - 1; i++) {
            if(s1[i] != s2[i]) {
                ++counter;
            }
        }
        return counter;
    }
};
