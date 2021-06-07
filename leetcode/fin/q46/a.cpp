class Solution {
public:
    vector<int> path;
    void bt(vector<vector<int>>* result, vector<bool>* is_used, const vector<int>* nums) {
        for(int i = 0 ; i < nums->size(); i++) {
            if((*is_used)[i] == false) {
                (*is_used)[i] = true;
                path.push_back((*nums)[i]);
                bt(result, is_used, nums);
                path.pop_back();
                (*is_used)[i] = false;
            } else {
                continue;
            }
        }
        if(path.size() == is_used->size()) {
            result->emplace_back(path);
            return;    
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> is_used(nums.size(), false);
        bt(&result, &is_used, &nums);
        return result;
    }
};


