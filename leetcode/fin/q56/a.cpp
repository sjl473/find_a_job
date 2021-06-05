#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) {
            return {};
        }
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for(auto & interval : intervals) {
            int a = interval[0];
            int b = interval[1];
            if(result.size() == 0) {
                result.push_back({a, b});
            } else {
                if(result.back()[1] < a) {
                    result.push_back({a, b});
                } else {
                    result.back()[1] = std::max(result.back()[1], b);
                }
            }
        }
        return  result;
    }
};



int main(void) {

}
