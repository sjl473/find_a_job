class Solution {
public:
    string minNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b){return to_string(a) + to_string(b) < to_string(b) + to_string(a);});
        string result;
        for(auto x : nums) {
            result += to_string(x);
        }
        return result;
    }
};

